import Control.Applicative
import Control.Monad
import Data.List

main :: IO ()
main = do
        n <- read <$> getLine :: IO Int
        list <- replicateM n $ map read . words <$> getLine :: IO [[Double]]
        let tupples = list2Tupple list
        let over35 = sum $ map isOver35 tupples
        let over30 = sum $ map isOver30 tupples
        let over25 = sum $ map isOver25 tupples
        let night  = sum $ map isTropicalNight tupples
        let winter = sum $ map isWinterDay tupples
        let ice    = sum $ map isIceDay tupples
        putStrLn $ unwords $ map show [over35,over30,over25,night,winter,ice]

list2Tupple :: [[Double]] -> [(Double,Double)]
list2Tupple [] = []
list2Tupple (d:ds) = (d!!0, d!!1) : list2Tupple ds

isOver35 :: (Double,Double) -> Int
isOver35 dd = check (35<=) $ fst dd

isOver30 :: (Double,Double) -> Int
isOver30 dd = (check (30<=) max) * (check (<35) max)
    where max = fst dd

isOver25 :: (Double,Double) -> Int
isOver25 dd = (check (25<=) max) * (check (<30) max)
    where max = fst dd

isTropicalNight :: (Double,Double) -> Int
isTropicalNight dd = check (25<=) $ snd dd

isWinterDay :: (Double,Double) -> Int
isWinterDay dd = (check (0<=) $ fst dd) * (check (<0) $ snd dd)

isIceDay :: (Double,Double) -> Int
isIceDay dd = check (<0) $ fst dd

check :: (Double -> Bool) -> Double -> Int
check f d 
    | (f d) == True =  1
    | otherwise = 0

