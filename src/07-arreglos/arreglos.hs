map' :: (a -> b) -> [a] -> [b]
map' f [] = []
map' f (x:xs) = f x : (map' f xs)

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
alguno' f xs = reducir False (||) $ map' f xs

todos' :: (a -> Bool) -> [a] -> Bool
todos' f xs = reducir True (&&) $ map' f xs

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
