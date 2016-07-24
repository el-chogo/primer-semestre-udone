import Data.Char

mapear :: (a -> b) -> [a] -> [b]
mapear f [] = []
mapear f (x:xs) = f x : (mapear f xs)

reducir :: b -> (a -> b -> b) -> [a] -> b
reducir initial f [] = initial
reducir initial f (x:xs) = f x (reducir initial f xs)

voltear :: [a] -> [a]
voltear [] = []
voltear (x:xs) = (voltear xs) ++ [x]

alguno :: (a -> Bool) -> [a] -> Bool
alguno f [] = False
alguno f (x:xs) = f x || alguno f xs

todos :: (a -> Bool) -> [a] -> Bool
todos f [] = True
todos f (x:xs) = f x && alguno f xs

alguno' :: (a -> Bool) -> [a] -> Bool
alguno' f xs = reducir False (||) $ mapear f xs

todos' :: (a -> Bool) -> [a] -> Bool
todos' f xs = reducir True (&&) $ mapear f xs

tomar :: Int -> [a] -> [a]
tomar = tomar' []
    where
    tomar' :: [a] -> Int -> [a] -> [a]
    tomar' acc _ [] = acc
    tomar' acc 0 _ = acc
    tomar' acc tantos (x:xs) = tomar' (acc ++ [x]) (tantos - 1) xs

tomarCuando :: (a -> Bool) -> [a] -> [a]
tomarCuando f [] = []
tomarCuando f (x:xs)
    | f x = x : tomarCuando f xs
    | otherwise = tomarCuando f xs

tomarTantosCuando :: (a -> Bool) -> Int -> [a] -> [a]
tomarTantosCuando _ _ [] = []
tomarTantosCuando _ 0 _ = []
tomarTantosCuando f n (x:xs)
    | f x = x : tomarTantosCuando f (n - 1) xs
    | otherwise = tomarTantosCuando f n xs

divisor :: Int -> Int -> Bool
divisor x y = (==) 0 $ mod y x

verdadParaFunciones :: [(a -> Bool)] -> a -> Bool
verdadParaFunciones fs x = todos' (\f -> f x) fs

minusculas :: String -> String
minusculas = mapear toLower

palindromo :: String -> Bool
palindromo a = (==) (minusculas a) (voltear $ minusculas a)

data Cond a = a :? a

infixl 1 :?
infixl 0 ?

(?) :: Bool -> Cond a -> a
True ? (x :? _) = x
False ? (_ :? x) = x

main :: IO ()
main = do
    let predicados = [divisor 13, divisor 7]
        numeros = tomarTantosCuando (verdadParaFunciones predicados) 20 [1..1000]

    putStrLn "Numeros divisibles entre 13 y 7 del 1 al 1000"
    putStrLn $ show $ numeros

    putStrLn "Introduzca una palabra: "
    palabra <- getLine
    putStrLn $ (++) "Palabra volteada: " $ voltear palabra

    putStrLn "Introduzca un palindromo: "
    pal <- getLine
    putStrLn $ "La palabra introducida " ++
        ((palindromo pal) ? "es un" :? "no es un") ++ " palindromo"
