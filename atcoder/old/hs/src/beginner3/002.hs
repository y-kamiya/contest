import Control.Applicative
import Control.Monad
import Data.List

charList :: String
charList = "atcoder"

main :: IO ()
main = do
        ss <- replicateM 2 getLine
        let win = isWin ss
        if win 
            then putStrLn "You can win"
            else putStrLn "You will lose"
    
isWin :: [String] -> Bool
isWin ss = and $ zipWith compareChar (ss!!0) (ss!!1)

compareChar :: Char -> Char ->  Bool
compareChar a b 
    | a == b = True
    | a == '@' = b `elem` charList
    | b == '@' = a `elem` charList
    | otherwise = False
