# Fichero: paralelo.py
import asyncio

async def foo(x, n):
    print(f"{x} ({n})")
    await asyncio.sleep(n)
    if x <= 0:
        return 0, n
    else:
        y, _ = await foo(x - 1, n)
        return x + y, n

async def bar(n):
    print("BEGIN")
    r = await asyncio.gather(
        foo(n, 2),
        foo(n, 1))
    print("END")
    print(r)

def test(n):
    asyncio.run(bar(n))
