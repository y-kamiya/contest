import Control.Monad
import Control.Applicative
import Data.List

data Point = Point Int Int deriving Show

sub :: Point -> Point -> Point
sub (Point a b) (Point c d) = Point (c-a) (d-b)

main :: IO ()
main = do
        n <- readLn
        ss <- replicateM n getLine
        let ps = toPoint ss
        let comb = makeComination 3 ps
        let list = map (\ x -> if (x /= 0) && (x `mod` 2 == 0) then 1 else 0) $ map helon comb
        let count = foldl (+) 0 list
        print count

toPoint :: [String] -> [Point]
toPoint []   = []
toPoint (s:ss) = p : toPoint ss
    where (x:y:_) = words s
          p = Point (read x) (read y)

makeComination :: Int -> [Point] -> [[Point]]
makeComination _ [] = [] 
makeComination n xs 
    | n == 0 = [[]]
    | n == 1 = [[x] | x <- xs]
    | n == 2 = [[head xs, x] | x <- tail xs] ++ makeComination n (tail xs)
    | n == 3 = (map ((head xs):) (makeComination (n-1) (tail xs)))  ++ (makeComination n (tail xs))

helon :: [Point] -> Int
helon ps = abs $ (a * d) - (b * c) 
        where (Point a b) = sub (ps!!1) (ps!!0)
              (Point c d) = sub (ps!!2) (ps!!0)

