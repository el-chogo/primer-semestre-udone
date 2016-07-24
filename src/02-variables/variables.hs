main :: IO ()
main = do
    putStrLn "Cual es tu nombre?"

    -- El uso de la notación <- será explicado en el sitio en un futuro
    -- por ahora basta con saber que las asignaciones a nombres
    -- dentro de main, siempre que involucre IO, serán realizadas mediante
    -- <- y no =
    nombre <- getLine
    putStrLn $ "Hola " ++ nombre ++ "!"
