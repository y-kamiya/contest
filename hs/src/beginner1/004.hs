import Control.Monad
import Control.Applicative
import Data.List

main :: IO ()
main = do
    n <- readLn
    ss <- replicateM n getLine
    let list = map hwords ss
    let arrangedTimes = sort $ zipWith (\x y -> Schedule x y)  (map (arrangeStartTime . fst) list) (map (arrangeEndTime . snd) list)
    let schedule = foldr reduceSchedule [] arrangedTimes
    putStr $ unlines $ map show schedule

data Schedule = Schedule { start :: String, end :: String }

instance Show Schedule where
        show x = start x ++ "-" ++ end x

instance Eq Schedule where
        x == y = (start x == start y) && (end x == end y)

instance Ord Schedule where
        compare x y = compare (start x) (start y)

reduceSchedule :: Schedule -> [Schedule] -> [Schedule]
reduceSchedule sche [] = [sche]
reduceSchedule sche (s:ss) = ( uniteSchedule sche s ) ++ ss

uniteSchedule :: Schedule -> Schedule -> [Schedule]
uniteSchedule s1 s2 
    | end s1 < start s2 = [s1, s2]
    | otherwise = [Schedule (start s1) (max (end s1) (end s2))]


hwords :: String -> (String,String)
hwords s = (take 4 s, drop 5 s)

arrangeStartTime :: String -> String
arrangeStartTime s = to4Digit $ timeFloor s

arrangeEndTime :: String -> String
arrangeEndTime s = to4Digit $ moveUpTime $ timeCeil s

to4Digit :: Int -> String
to4Digit n = zeroStr ++ show n
        where digitNum = length $ show n
              zeroStr = take (4 - digitNum) $ repeat '0'

moveUpTime :: Int -> Int
moveUpTime n 
    | n `mod` 100 >= 60 = arrangeInt ceiling n 2
    | otherwise = n


timeFloor :: String -> Int
timeFloor s = 
        let n = read s :: Int 
        in floorBy5 n

timeCeil :: String -> Int
timeCeil s =
        let n = read s :: Int 
        in ceilingBy5 n

arrangeInt :: (RealFrac a) => (a -> Int) -> Int -> Int -> Int
arrangeInt f n d = 10^d * (f $ (fromIntegral n) / (fromIntegral $ 10^d))

floorBy5 :: Int -> Int
floorBy5 n 
    | (n `mod` 10) < 5 = arrangeInt floor n 1
    | otherwise = 5 + (arrangeInt floor n 1)

ceilingBy5 :: Int -> Int
ceilingBy5 n 
    | 1 <= m && m <= 4 =  (arrangeInt ceiling n 1) - 5 
    | otherwise = (arrangeInt ceiling n 1)
        where m = n `mod` 10



