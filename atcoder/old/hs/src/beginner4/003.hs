import Control.Applicative
import Control.Monad
import Data.List

patterns = ["123456","234561","345612","456123","561234","612345"]

main :: IO ()
main = do
        n <- read <$> getLine :: IO Int
        let (q,r) = n `divMod` 5
        putStrLn $ forS [0..(r-1)] (patterns!!(q `mod` 6)) 

forS :: [Int] -> String -> String
forS [] s = s
forS (n:ns) s = 
        let i = (n `mod` 5) + 1
            swapped = swap i s
        in  forS ns swapped 

swap :: Int -> String -> String
swap n s =  (take (n-1) s) ++ (reverse $ drop (n-1) $ take (n+1) s) ++ (drop (n+1) s)



