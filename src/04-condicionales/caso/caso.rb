puts "Introduzca un numero"
numero = gets.chomp.to_i

case numero
when 0
  puts "Numero neutro con respecto a la suma"
when 1
  puts "Numero neutro con respecto a la multiplicacion"
when 2
  puts "Base del sistema binario"
when 3
  puts "Lados del triangulo"
when 4
  puts "Casas de Hogwarts"
when 5
  puts "Puntas de una estrella"
when 6
  puts "Primer numero perfecto"
when 7
  puts "Numero magico"
else
  puts "Solo se imprimen resultados para numeros del 0 al 7"
end
