main :: IO ()
main = do
    putStrLn "Escriba un nombre: "
    nombre <- getLine
    
    case nombre of "Napoleon" -> putStrLn "Su apellido es Bonaparte!"
                    _ -> putStrLn "No se ha podido determinar su apellido"
