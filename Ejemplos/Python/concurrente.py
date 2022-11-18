# Fichero: concurrente.py
import asyncio
import random

async def foo(id, x):
    print(f"{id}: {x}")
    await asyncio.sleep(random.uniform(1,2))
    if x <= 0:
        return id, 0
    else:
        _, y = await foo(id, x - 1)
        return id, x + y

async def bar(n):
    print("BEGIN")
    random.seed()
    r = await asyncio.gather(
        foo(1, n),
        foo(2, n))
    print("END")
    print(r)

def test(n):
    asyncio.run(bar(n))
