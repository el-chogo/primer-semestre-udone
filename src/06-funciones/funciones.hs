import Data.Char
import Data.List

tomarPalabra :: String -> (String, String)
tomarPalabra = tomarPalabra' []
    where
    tomarPalabra' :: String -> String -> (String, String)
    tomarPalabra' acc [] = (acc, [])
    tomarPalabra' acc (x:xs)
        | x == ' ' = (acc, xs)
        | otherwise = tomarPalabra' (acc ++ [x]) xs

mayusculas :: String -> String
mayusculas (x:xs) = [toUpper x] ++ xs

separarPalabras :: String -> [String]
separarPalabras = separarPalabras' []
    where
    separarPalabras' :: [String] -> String -> [String]
    separarPalabras' acc [] = acc
    separarPalabras' acc xs
        | palabraActual == "" = separarPalabras' acc restoActual
        | otherwise = separarPalabras' (acc ++ [palabraActual]) restoActual
        where
        parActual = tomarPalabra xs
        palabraActual = fst parActual
        restoActual = snd parActual

capitalizar :: String -> String
capitalizar = concat . intersperse " " . map mayusculas . separarPalabras

saludar :: String -> String
saludar = (flip (++)) "!" . (++) "Hola "

main :: IO ()
main = do
    putStrLn "Introduce tu nombre"
    nombre <- getLine
    putStrLn $ saludar nombre
