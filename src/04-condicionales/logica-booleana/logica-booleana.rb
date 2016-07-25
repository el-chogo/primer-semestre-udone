puts "Verdadero y Falso: #{true and false}"
puts "Falso y Verdadero: #{false and true}"
puts "AND logico se comporta como el producto entre 1 (Verdadero) y 0 (Falso)"
puts "1 x 0 = #{1 * 0}"
puts "0 x 1 = #{0 * 1}"
puts "Verdadero y Verdadero: #{true and true}"
puts "Falso y Falso: #{false and false}"

puts "Verdadero o Falso: #{true or false}"
puts "Falso o Verdadero: #{false or true}"
puts "OR logico se comporta como la suma entre 1 (Verdadero) y 0 (Falso)"
puts "1 + 0 = #{1 + 0}"
puts "0 + 1 = #{0 + 1}"
puts "Verdadero o Verdadero: #{true or true}"
puts "Falso o Falso: #{false or false}"

if false or nil
  puts "Esto nunca pasara"
else
  puts "false y nil evaluan a falso"
end

if true and 2
  puts "La presencia de un valor evalua a verdadero"
end
