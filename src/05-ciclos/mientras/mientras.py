if __name__ == "__main__":
    resultado = 1
    numero = int(input("Introduzca un numero: "))
    potencia = int(input("Introduzca una potencia: "))

    while (potencia > 0):
        resultado = numero * resultado
        potencia = potencia - 1

    print(resultado)
