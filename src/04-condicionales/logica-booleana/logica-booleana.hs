main :: IO ()
main = do
    putStrLn ("Verdadero y Falso: " ++ (show $ (True && False)))
    putStrLn ("Falso y Verdadero: " ++ (show $ (False && True)))
    putStrLn ("Verdadero y Verdadero: " ++ (show $ (True && True)))
    putStrLn ("Falso y Falso: " ++ (show $ (False && False)))

    putStrLn ("Verdadero o Falso: " ++ (show $ (True || False)))
    putStrLn ("Falso o Verdadero: " ++ (show $ (False || True)))
    putStrLn ("Verdadero o Verdadero: " ++ (show $ (True || True)))
    putStrLn ("Falso o Falso: " ++ (show $ (False || False)))
