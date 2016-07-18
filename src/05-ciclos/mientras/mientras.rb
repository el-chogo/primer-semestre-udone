puts "Introduzca un numero"
numero = gets.chomp.to_i

puts "Introduzca un exponente"
exponente = gets.chomp.to_i

contador = 0
resultado = 1

while contador < exponente
    resultado = resultado * numero
    contador += 1
end

puts resultado
