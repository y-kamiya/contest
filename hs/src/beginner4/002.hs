import Control.Applicative
import Control.Monad
import Data.List

main :: IO ()
main = do
        input <- replicateM 4 $ fmap words getLine
        let ss = reverse $ map reverse input
        putStr $ unlines $ map unwords ss


