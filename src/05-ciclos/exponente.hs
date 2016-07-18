main :: IO ()
main = do
    putStrLn "Ingrese un numero"
    numeroStr <- getLine
    putStrLn "Ingrese una potencia"
    potenciaStr <- getLine

    let numero = read numeroStr :: Int
        potencia = read potenciaStr :: Int

    putStrLn $ show $ exponente numero potencia

    where
        exponente :: Int -> Int -> Int
        exponente n a = exponente' n a 1

        exponente' :: Int -> Int -> Int -> Int
        exponente' n 0 r = 1
        exponente' n 1 r = r * n
        exponente' n a r = exponente' n (a - 1) (r * n)
