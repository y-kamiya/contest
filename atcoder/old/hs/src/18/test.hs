import Data.List
ops :: [Int]
ops  = [10000,9999..1]
ops' :: [Int]
ops'  = [1..10000]

main :: IO ()
main = print $ lineDistance 10 ops

lineDistance :: Int -> [Int] -> Int
lineDistance m op = sum lineDis 
        where sp = {-#SCC "sort" #-}sort op
              lineDis :: [Int]
              lineDis = map (\x -> abs $ getLineNum op x m - getLineNum ops' x m) op
        


getLineNum :: [Int] -> Int -> Int -> Int
getLineNum list x m = {-#SCC "div" #-}index `div` m
        where (Just index) = {-#SCC "elemIndex" #-}elemIndex x list 
