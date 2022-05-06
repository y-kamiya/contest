import Control.Applicative
import Control.Monad
import Data.List

main :: IO ()
main = getLine >>= putStrLn . show . solve 

solve :: String -> Double
solve s = let n = read s :: Double
          in  9 / 5 * n + 32

