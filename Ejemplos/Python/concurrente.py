# Fichero: concurrente.py
import asyncio
import random
import sys

async def foo(id, value):
    result = 0
    while value >= 0:
        print(f"{id}: {value}")
        await asyncio.sleep(random.uniform(1,2))
        result += value
        value -= 1
    return id, result

async def bar(maxids, maxval):
    if maxids > 0:
        print("INICIO")
        random.seed()
        crs = [foo(id, maxval) for id in range(maxids)]
        [print(type(i)) for i in crs]
        print("EJECUTAR")
        results = await asyncio.gather(*crs)
        print("FINAL")
        print(f"{results = }")
    else:
        print("NADA")

def test(maxids, maxval):
    asyncio.run(bar(maxids, maxval))

if __name__ == "__main__":
    ids = 3
    val = 6

    try:
        if len(sys.argv) >= 3:
            val = int(sys.argv[2])
        if len(sys.argv) >= 2:
            ids = int(sys.argv[1])
    except:
        pass

    test(ids, val)
