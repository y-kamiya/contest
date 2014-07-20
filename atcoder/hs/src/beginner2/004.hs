import Data.List
import Control.Applicative
import Control.Monad

main :: IO ()
main = do
        (n:m:_) <- fmap (map read . words) getLine :: IO [Int]
        relations <- fmap sort $ fmap (fmap (map read . words)) $ replicateM m getLine :: IO [[Int]]
        print $ maxGroup n n relations

comb :: Int -> [Int] -> [[Int]]
comb 0 _ = [[]]
comb _ [] = [[]]
comb n l@(x:xs) 
    | length l <= n = map (x:) (comb (n-1) xs)
    | otherwise = map (x:) (comb (n-1) xs) ++ comb n xs


maxGroup :: Int -> Int -> [[Int]] -> Int
maxGroup _ _ [] = 1
maxGroup _ 1 _ = 1
maxGroup n m relations = 
        case (checkGroupN n m relations) of 
            False -> maxGroup n (m-1) relations
            True  -> m
                
checkGroupN :: Int -> Int -> [[Int]] -> Bool
checkGroupN n m relations = any (\x -> x) $ map (checkPattern relations) patterns 
        where patterns = comb m [1..n]

checkPattern :: [[Int]] -> [Int] -> Bool
checkPattern relations pattern = (intersect relations c) == c
        where c = comb 2 pattern


combination :: (Ord a) => Int -> [a] -> [[a]]
combination n xs = filter isDesc $ nub $ sequenceA $ take n $ tails xs 

sequenceA :: Applicative f => [f a] -> f [a]
sequenceA [] = pure []
sequenceA (x:xs) = (:) <$> x <*> sequenceA xs

isDesc :: Ord a => [a] -> Bool
isDesc xs = case isDesc' xs of
                Just _ -> True
                Nothing -> False
    where 
        isDesc' :: Ord a => [a] -> Maybe Bool
        isDesc' [] = Nothing
        isDesc' (x0:x1:xs) = guard (x0 < x1) >> isDesc' (x1:xs) 
        isDesc' _ = return True


