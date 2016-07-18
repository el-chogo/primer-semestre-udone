if __name__ == "__main__":
    numero = int(input("Introduzca un numero: "))

    for contador in range(1, numero):
        if contador % 2 == 0:
            print(str(contador) + " es un numero par!")
        else:
            print(str(contador) + " es un numero impar!")

