import Control.Applicative
import Control.Monad
import Data.List

data Input = Input { row::Int, col::Int, x::Int, y::Int, desk::Int, lack::Int } deriving Show

main :: IO ()
main = do
        input <- fmap list2Input $ replicateM 3 $ fmap (map read . words :: String -> [Int]) getLine
        let n = count input
        print $ n `mod` (10^9 + 7)

count :: Input -> Integer
count input = places * patterns
        where places = countPlaces input
              patterns = countPatterns input

countPlaces :: Input -> Integer
countPlaces input = fromIntegral $ (row input - x input + 1) * (col input - y input + 1)

countPatterns :: Input -> Integer 
countPatterns input = 
        let xx = x input
            yy = y input
            d = desk input
            l = lack input 
        in  fromIntegral $ fact (xx*yy) `div` ((fact d) * (fact l))



fact :: Int -> Integer
fact n 
    | n <= 1 = 1
    | otherwise = (fromIntegral n) * (fact (n-1))


list2Input :: [[Int]] -> Input
list2Input ns = Input { row = head $ head ns
                      , col = last $ head ns
                      , x = head $ ns!!1
                      , y = last $ ns!!1
                      , desk = head $ last ns
                      , lack = last $ last ns }


