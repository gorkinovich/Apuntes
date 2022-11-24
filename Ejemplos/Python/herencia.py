# Fichero: herencia.py

class Abuelos:
    def __init__(self):
        print("Los abuelos han llegado.")

    def saludar(self):
        print("¡Los abuelos saludan!")

class Padres(Abuelos):
    def __init__(self):
        super().__init__()
        print("Los padres han llegado.")

    def saludar(self):
        print("¡Los padres saludan!")

class Tíos(Abuelos):
    def __init__(self):
        super().__init__()
        print("Los tíos han llegado.")

    def saludar(self):
        print("¡Los tíos saludan!")

class Hijos(Padres, Tíos):
    def __init__(self):
        super().__init__()
        print("Los hijos han llegado.")

    def saludar(self, salsup=True):
        if salsup:
            super(Hijos, self).saludar()
        print("¡Los hijos saludan!")

    def saludos(self):
        Abuelos.saludar(self)
        Padres.saludar(self)
        Tíos.saludar(self)
        self.saludar(False)

if __name__ == "__main__":
    hijos = Hijos()
    print()
    hijos.saludar()
    print()
    hijos.saludos()
