main :: IO ()
main = do
    putStrLn "Introduzca un valor para a: "
    aCadena <- getLine
    
    putStrLn "Introduzca un valor para b: "
    bCadena <- getLine

    let a = read aCadena :: Float
        b = read bCadena :: Float
        suma = (+) a b
        producto = a * b
        cocienteAB = (/) a b
        cocienteBA = b / a

    putStrLn $ "a + b = " ++ show suma
    putStrLn $ "a * b = " ++ show producto
    putStrLn $ "a / b = " ++ show cocienteAB
    putStrLn $ "b / a = " ++ show cocienteBA
