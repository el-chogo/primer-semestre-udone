if __name__ == "__main__":
    resultado = 1
    numero = input("Introduzca un numero: ")
    potencia = input("Introduzca una potencia: ")

    while (potencia > 0):
        resultado = numero * resultado
        potencia = potencia - 1

    print(resultado)
    
