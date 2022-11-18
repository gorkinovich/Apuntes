# Fichero: ambito.py
x = 10
print(f"{x = }")

def foo():
	global x, y
	x += 1
	y = x * 2
	print(f"{x = }")

foo()
print(f"{y = }")
