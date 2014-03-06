import Control.Monad
import Control.Applicative
import Data.List

getLineToInt :: IO [Int]
getLineToInt = map read <$> words <$> getLine

main :: IO ()
main = do
        (n:m:_) <- getLineToInt
        (x0:a:p:_) <- getLineToInt
        {-
        print $ pointList (n*m-1) x0 a p
        print $ sort $ pointList (n*m-1) x0 a p
        let ps = pointList (n*m-1) x0 a p
        print $ map (\x -> getColumnNum ps x m) $ sort ps
        -}
        print $ calcDistance n m x0 a p

makePointList :: Int -> Int -> Int -> Int -> Int -> [Int]
makePointList n m x0 a p = reverse $ foldl (\z _ -> (((head z) + a) `mod` p):z) [x0] [1..(n*m-1)]

calcDistance :: Int -> Int -> Int -> Int -> Int -> Int 
calcDistance n m x0 a p 
    | a == p && (head points) <= (last points) = 0
    | a == p && (head points) > (last points) = (m-1)*2
    | otherwise = (lineDistance m points) + (columnDistance m points)
        where points = makePointList n m x0 a p
              
lineDistance :: Int -> [Int] -> Int
lineDistance m op = sum lineDis 
        where sp = {-#SCC "sort" #-}sort op
              lineDis :: [Int]
              lineDis = map (\x -> abs $ getLineNum op x m - getLineNum sp x m) op

columnDistance :: Int -> [Int] -> Int
columnDistance m op = sum $ map lineToDistance sps
        where sps = filter (not . null) $ groupAt $ sort op

              groupAt :: [Int] -> [[Int]]
              groupAt [] = [[]]
              groupAt list =  take m list : (groupAt $ drop m list)

              lineToDistance :: [Int] -> Int
              lineToDistance sp = foldl1 (\z x -> z + (abs x)) $ zipWith (-) (sort columnList) [0..(m-1)]
                where columnList = map (\x -> getColumnNum op x m) sp

getLineNum :: [Int] -> Int -> Int -> Int
getLineNum list x m = {-#SCC "div" #-}index `div` m
        where (Just index) = {-#SCC "elemIndex" #-}elemIndex x list 

getColumnNum :: [Int] -> Int -> Int -> Int
getColumnNum list x m = index `mod` m
        where (Just index) = elemIndex x list 
