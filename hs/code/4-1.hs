import Control.Monad
import Data.Ord
import Data.List

main = do
    n <- readLn
    ps <- replicateM n getLine
    let list = makeDistanceList ps
    print list
--    let a = getPoint $ head ps
--    let b = getPoint $ last ps
--    print $ distance a b

data Point = Point { x :: Float, y :: Float }

distance :: Point -> Point -> Float
distance a b = sqrt $ ((x a) - (x b)) ** 2 + ((y a) - (y b)) **2

getPoint :: String -> Point
getPoint str = 
    let list = words str
        x = read $ (head list) :: Float
        y = read $ (last list) :: Float
    in Point x y
                
maxDistance :: [String] -> Float
maxDistance ps = maximum $ makeDistanceList ps
    where
        makeDistanceList :: [String] -> [Float]
        makeDistanceList ps =
            let x:xs = 
