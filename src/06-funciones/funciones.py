def capitalizar(nombre):
    capitalizarActual = True
    listaNombre = list(nombre)
    for indice,letra in enumerate(listaNombre):
        if (capitalizarActual and listaNombre[indice] != " "):
            listaNombre[indice] = listaNombre[indice].upper()
            capitalizarActual = False
        if (listaNombre[indice] == " "):
            capitalizarActual = True
    return "".join(listaNombre)

def saludar(nombre):
    print("Hola " + capitalizar(nombre))

if __name__ == "__main__":
    saludar(input("Escribe tu nombre completo: "))
