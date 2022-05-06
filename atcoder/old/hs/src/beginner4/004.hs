import Control.Applicative
import Control.Monad
import Data.List

main :: IO ()
main = do
        [r,g,b] <- (map read . words) <$> getLine :: IO [Int]
        print $ ((count r) + (count g) + (count b))

count :: Int -> Int
count n = sum $ take (n-1) makeList
    where 
        makeList :: [Int]
        makeList = concat $ map (replicate 2) [1..] 

count' :: Int -> Int
count' n = sum $ take n [1..]

restLeft :: Int -> Int
restLeft g = 
        where used = n `div` 2
