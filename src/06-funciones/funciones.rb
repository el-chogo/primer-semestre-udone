def capitalizar(nombre)
    nombreModificado = nombre.dup
    longitud = nombre.length - 1
    capitalizarActual = true

    for contador in 0..longitud
        if capitalizarActual and (nombre[contador] != " ")
            nombreModificado[contador] = nombre[contador].upcase
            capitalizarActual = false
        elsif nombre[contador] == " "
            capitalizarActual = true
        end
    end

    nombreModificado
end

def saludar(nombre)
    puts "Hola #{capitalizar(nombre)}"
end

puts "Introduzca su nombre completo"
saludar(gets.chomp)
