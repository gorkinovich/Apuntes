//------------------------------------------------------------------------------
// Copyright (c) 2023 Gorka Suárez García
//
// Permission is hereby granted, free of charge, to any person obtaining a
// copy of this software and associated documentation files (the "Software"),
// to deal in the Software without restriction, including without limitation
// the rights to use, copy, modify, merge, publish, distribute, sublicense,
// and/or sell copies of the Software, and to permit persons to whom the
// Software is furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included
// in all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
// THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
// FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
// DEALINGS IN THE SOFTWARE.
//------------------------------------------------------------------------------
using System;
using System.IO;
using System.Text;
using System.Linq;
using System.Collections.Generic;

namespace StackEdit {
    /// <summary>
    /// The StackEdit transformation utility tool for markdown files.
    /// </summary>
    class StackEdit {
        /// <summary>
        /// The main entry of the command.
        /// </summary>
        /// <param name="args">The arguments of the command.</param>
        public static void Main (string[] args) {
            var operation = CreateOperation(args);
            try {
                operation.Run();
            } catch (Exception e) {
                if (CheckOption(args, "debug")) {
                    Console.WriteLine($"Message: {e.Message}");
                    Console.WriteLine($"StackTrace: {e.StackTrace}");
                }
            }
        }

        /// <summary>
        /// Checks if an option exists in a sequence of strings.
        /// </summary>
        /// <param name="values">The sequence of strings.</param>
        /// <param name="option">The option to find.</param>
        /// <returns>True if the option exists.</returns>
        static bool CheckOption(IEnumerable<string> values, string option) {
            return values.Where(x => x.ToLower() == option).Count() > 0;
        }

        /// <summary>
        /// Creates an operation to be executed in the command.
        /// </summary>
        /// <param name="args">The arguments to check.</param>
        /// <returns>The created operation.</returns>
        static IOperation CreateOperation (string[] args) {
            // Get the possible arguments of the command:
            var option = args.ElementAtOrDefault(0)?.ToLower();
            var input = args.ElementAtOrDefault(1)?.ToLower();
            var output = args.ElementAtOrDefault(2)?.ToLower();
            // Check and make the operation to execute:
            IOperation result = GitHubOperation.Make(option, input, output);
            if (result != null) {
                return result;
            }
            result = WebPageOperation.Make(option, input, output);
            if (result != null) {
                return result;
            }
            return new ShowHelpOperation();
        }
    }

    /// <summary>
    /// This interface represents an operation to execute.
    /// </summary>
    interface IOperation {
        /// <summary>
        /// Executes the operation.
        /// </summary>
        void Run ();
    }

    /// <summary>
    /// This type represents a show help operation.
    /// </summary>
    class ShowHelpOperation : IOperation {
        /// <summary>
        /// Executes the operation.
        /// </summary>
        public void Run () {
            Console.WriteLine("COMMAND options parameters");
            Console.WriteLine("-g, -github    input [output]");
            Console.WriteLine("-w, -webpage   input [output]");
        }
    }

    /// <summary>
    /// This type represents a abstract file operation.
    /// </summary>
    abstract class FileOperation {
        /// <summary>
        /// The input file path of the operation.
        /// </summary>
        public string Input { get; init; }

        /// <summary>
        /// The output file path of the operation.
        /// </summary>
        public string Output { get; init; }

        /// <summary>
        /// Makes a new instance of a file operation object.
        /// </summary>
        /// <typeparam name="T">The type to create.</typeparam>
        /// <param name="option">The option to check.</param>
        /// <param name="input">The input file.</param>
        /// <param name="output">The output file.</param>
        /// <param name="shortName">The short name of the commad.</param>
        /// <param name="longName">The long name of the commad.</param>
        /// <param name="make">The constructor function.</param>
        /// <returns>The new instance or null.</returns>
        protected static T Make<T> (string option, string input, string output,
            string shortName, string longName, Func<string, string, T> make)
            where T : FileOperation {
            if ((option == shortName || option == longName) && input != null && File.Exists(input)) {
                string outputPath, inputPath = Path.GetFullPath(input);
                if (output == null || output == input) {
                    outputPath = Path.ChangeExtension(input, ".out");
                } else {
                    outputPath = Path.GetFullPath(output);
                }
                return make(inputPath, outputPath);
            }
            return null;
        }

        /// <summary>
        /// Loads all the input lines of the operation.
        /// </summary>
        /// <returns>The lines of the file.</returns>
        protected IEnumerable<string> LoadLines () {
            return File.ReadAllLines(Input);
        }

        /// <summary>
        /// Saves all the output lines of the operation.
        /// </summary>
        /// <param name="lines">The output lines.</param>
        protected void SaveLines (IEnumerable<string> lines) {
            using (var stream = new StreamWriter(Output, false, new UTF8Encoding(true))) {
                foreach (var line in lines) {
                    stream.Write(line);
                    stream.Write("\n");
                }
            }
        }
    }

    /// <summary>
    /// This type represents a GitHub MarkDown transformation operation.
    /// </summary>
    class GitHubOperation : FileOperation, IOperation {
        /// <summary>
        /// The short name of the commad.
        /// </summary>
        public const string ShortName = "-g";

        /// <summary>
        /// The long name of the commad.
        /// </summary>
        public const string LongName = "-github";

        /// <summary>
        /// Makes a new instance of a GitHub MarkDown transformation operation object.
        /// </summary>
        /// <param name="option">The option to check.</param>
        /// <param name="input">The input file.</param>
        /// <param name="output">The output file.</param>
        /// <returns>The new instance or null.</returns>
        public static GitHubOperation Make (string option, string input, string output) {
            return Make(option, input, output, ShortName, LongName,
                (inpath, outpath) => new GitHubOperation { Input = inpath, Output = outpath });
        }

        /// <summary>
        /// Executes the operation.
        /// </summary>
        public void Run () {
            insideLatex = false;
            SaveLines(LoadLines().Select(latexMathReplace)
                                 .Select(codeTableReplace));
        }

        /// <summary>
        /// Replaces some fragments of text inside latex math tags.
        /// </summary>
        /// <param name="victim">The value to change.</param>
        /// <returns>The modified line.</returns>
        private string latexMathReplace(string victim) {
            var fragments = victim.Split(latexMathTag);
            if (fragments.Length > 1) {
                for (int i = 0; i < fragments.Length; i++) {
                    if (insideLatex) {
                        fragments[i] = insideLatexMathReplace(fragments[i]);
                    }
                    if (i + 1 < fragments.Length && fragments[i].LastOrDefault() != '`') {
                        insideLatex = !insideLatex;
                    }
                }
                return string.Join(latexMathTag, fragments);
            } else if (insideLatex) {
                return insideLatexMathReplace(victim);
            } else {
                return victim;
            }
        }

        /// <summary>
        /// Replaces some fragments of text inside latex math tags.
        /// </summary>
        /// <param name="victim">The value to change.</param>
        /// <returns>The modified line.</returns>
        private string insideLatexMathReplace (string victim) {
            var result = new StringBuilder(victim);
            foreach (var (old, next) in latexFragments) {
                result.Replace(old, next);
            }
            return result.ToString();
        }

        /// <summary>
        /// Replaces some fragments of text inside code tags in tables.
        /// </summary>
        /// <param name="victim">The value to change.</param>
        /// <returns>The modified line.</returns>
        private string codeTableReplace(string victim) {
            // Check that the line is a table:
            if (insideLatex) {
                return victim;
            }
            var line = victim.Trim();
            if (line.Length <= 1 || line[0] != '|' || line[^1] != '|') {
                return victim;
            }
            // Transform the fragments of text:
            bool code = false;
            var result = new StringBuilder(victim);
            for (int i = 0; i < result.Length; i++) {
                if (result[i] == '`') {
                    code = !code;
                } else if (result[i] == '|' && code) {
                    result.Replace("|", @"\|", i, 1);
                    ++i;
                }
            }
            return result.ToString();
        }

        /// <summary>
        /// The current inside latex math equation flag.
        /// </summary>
        private bool insideLatex = false;

        /// <summary>
        /// The latex text fragments to replace inside the file.
        /// </summary>
        private readonly (string, string)[] latexFragments = new (string, string)[] {
            (@"\\", @"\\\\"),
            (@"\char95", @"\\_"),
            (@"\char35", @"\\#"),
            (@"\char36", @"\\$"),
            (@"\char37", @"\\%"),
            (@"\char123", @"\\{"),
            (@"\char125", @"\\}"),
            (@"\texttt{\textasciitilde}", @"\texttt{\\~{}}\")
        };

        /// <summary>
        /// The latex tag for math equations.
        /// </summary>
        private const string latexMathTag = @"$$";
    }

    /// <summary>
    /// This type represents a web page transformation operation.
    /// </summary>
    class WebPageOperation : FileOperation, IOperation {
        /// <summary>
        /// The short name of the commad.
        /// </summary>
        public const string ShortName = "-w";

        /// <summary>
        /// The long name of the commad.
        /// </summary>
        public const string LongName = "-webpage";

        /// <summary>
        /// Makes a new instance of a web page transformation operation object.
        /// </summary>
        /// <param name="option">The option to check.</param>
        /// <param name="input">The input file.</param>
        /// <param name="output">The output file.</param>
        /// <returns>The new instance or null.</returns>
        public static GitHubOperation Make (string option, string input, string output) {
            return Make(option, input, output, ShortName, LongName,
                (inpath, outpath) => new GitHubOperation { Input = inpath, Output = outpath });
        }

        /// <summary>
        /// Executes the operation.
        /// </summary>
        public void Run () {
            SaveLines(LoadLines().Select(symbolsReplace));
        }

        /// <summary>
        /// Replaces some fragments of text inside code tags in tables.
        /// </summary>
        /// <param name="victim">The value to change.</param>
        /// <returns>The modified line.</returns>
        private string symbolsReplace (string victim) {
            var result = new StringBuilder(victim);
            for (int i = 0; i < result.Length; i++) {
                if (result[i] == '') {
                    result[i] = 'ı';
                }
            }
            return result.ToString();
        }
    }
}
