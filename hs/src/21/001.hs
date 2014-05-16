import Control.Applicative
import Control.Monad
import Data.List

main :: IO ()
main = do
        input <- replicateM 4 $ fmap (map read . words :: String -> [Int]) getLine
       
        if sameToRight input
           then putStrLn "CONTINUE"
           else if sameToUnder input 
                   then putStrLn "CONTINUE"
                   else putStrLn "GAMEOVER" 

sameToRight :: [[Int]] -> Bool
sameToRight [] = False
sameToRight input 
    | canMove == False = sameToRight $ tail input
    | canMove == True  = True
        where canMove = any sameNumber $ makePair $ head input

makePair :: [a] -> [(a,a)]
makePair xs = zip (heads xs) (tail xs)

sameNumber :: (Int,Int) -> Bool
sameNumber pair = fst pair == snd pair


sameToUnder :: [[Int]] -> Bool
sameToUnder input = any sameNumber $ concatMap (\x -> zip (fst x) (snd x)) $ makePair input



heads :: [a] -> [a]
heads xs = take ((length xs)-1) xs
