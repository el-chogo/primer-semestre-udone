def mapear(f, xs)
  mapear_privado = lambda do |f, xs, ys|
    x, *rest = xs
    return mapear_privado.call(f, rest, ys << f.call(x)) unless xs.empty?
    ys
  end
  mapear_privado.call(f, xs, [])
end

def reducir(f, xs, y)
  x, *rest = xs
  return reducir(f, rest, f.call(y, x)) unless xs.empty?
  y
end

def cuadrado(n)
  n * n
end

def sumar(a, b)
  a + b
end

def voltear(xs)
  voltear_privado = lambda do |xs|
    x, *rest = xs
    if (xs.empty?)
      []
    else
      voltear_privado[rest] << x
    end
  end

  voltear_privado[xs]
end

def tomar_cuando (f, xs)
  reducir(lambda {|acc, x| f[x] ? acc << x : acc}, xs, [])
end

def alguno?(f, xs)
  reducir(lambda {|acc, x| f[x] or acc}, xs, false)
end

def todos?(f, xs)
  reducir(lambda {|acc,x| f[x] and acc}, xs, true)
end

def tomar(n, xs)
  contador = 0

  fn = lambda do |acc, x|
    if contador < n
      contador += 1
      acc << x
    else
      acc
    end
  end

  reducir(fn, xs, [])
end

def generar_divisor(n)
  lambda {|x| x % n == 0}
end

def todas_funciones(*fs)
  lambda {|x| reducir(lambda {|acc, f| f[x] and acc}, fs, true)}
end

def main
  numeros = (1..1000).to_a

  divisor_7 = generar_divisor(7)
  divisor_13 = generar_divisor(13)

  divisores = todas_funciones(divisor_7, divisor_13)

  puts "Numeros divisibles por el 7 y 13 del 1 al 1000"

  tomar_cuando(divisores, numeros)

  puts "Introduzca una palabra"
  palabra = gets.chomp


  palindromo = palabra.downcase == (voltear palabra.downcase.chars).join("")

  if palindromo
    puts "La palabra introducida es un palindromo"
  else
    puts "La palabra introducida no es un palindromo"
  end
end

if __FILE__ == $PROGNAME
  main
end
