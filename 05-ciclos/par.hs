main :: IO ()
main = do
    putStrLn "Introduzca un numero"
    numeroStr <- getLine

    let numero = read numeroStr :: Int

    parImpar numero

    where
        parImpar :: Int -> IO ()
        parImpar numero = parImpar' numero 1

        parImpar' :: Int -> Int -> IO()
        parImpar' numero contador
            | numero == contador = return ()
            | otherwise = do
                case (contador `mod` 2) of 
                    0 -> putStrLn $ (show $ contador) ++ " es un numero par!"
                    x -> putStrLn $ (show $ contador) ++ " es un numero impar!"
                parImpar' numero (contador + 1)
