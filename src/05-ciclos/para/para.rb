puts "Introduzca un numero"
numero = gets.chomp.to_i

for contador in 1..numero
    if contador % 2 == 0
        puts contador.to_s + " es par!"
    else
        puts contador.to_s + " es impar!"
    end
end
