puts "Introduzca un valor para a"
a = gets().chomp().to_i()

puts "Introduzca un valor para b"
b = gets.chomp.to_i

suma = a + b
producto = a * b
cocienteAB = a / b
cocienteBA = b / a

puts "a + b = " + suma.to_s()
puts "a * b = " + producto.to_s
puts "a / b = " + cocienteAB.to_s
puts "b / a = " + cocienteBA.to_s
