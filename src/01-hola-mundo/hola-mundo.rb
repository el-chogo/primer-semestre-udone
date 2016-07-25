# coding: utf-8
# De igual manera que en Python, Ruby no tiene una función predeterminada
# como punto de entrada. Por lo tanto comparamos si la variable mágica
# __FILE__, que contiene el nombre del archivo, es igual al nombre del programa
# en ejecución

if __FILE__ == $PROGRAM_NAME
  puts "Hola mundo"
end
