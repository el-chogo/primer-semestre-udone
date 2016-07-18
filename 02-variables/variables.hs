main :: IO ()
main = do
    putStrLn "Cual es tu nombre?"
    nombre <- getLine
    putStrLn $ "Hola " ++ nombre ++ "!"
