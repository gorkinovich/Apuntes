# Fichero: ambitof.py
def barnl():
    x = 20
    def foo():
        nonlocal x
        x //= 10
    foo()
    print(f"bnl: {x = }")

def bargl():
    x = 20
    def foo():
        global x
        x //= 10
    foo()
    print(f"bgl: {x = }")

x = 10
barnl()
print(f"mod: {x = }")
bargl()
print(f"mod: {x = }")