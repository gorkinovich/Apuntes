# Fichero: decorador.py
class Foo:
    bar = 0

    @staticmethod
    def inc_bar(valor):
        Foo.bar += valor

    @classmethod
    def show_bar(cls):
        print(cls.bar)

    def __init__(self, data):
        self.__data = data

    @property
    def data(self):
        """Propiedad 'data' de 'Foo'."""
        print("get data:", self.__data)
        return self.__data

    @data.setter
    def data(self, value):
        print("set data:", self.__data, "=", value)
        self.__data = value

    @data.deleter
    def data(self):
        print("del data:", self.__data)
        del self.__data
