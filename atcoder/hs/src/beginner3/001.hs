import Control.Applicative

main :: IO ()
main = do
        n <- read <$> getLine :: IO Int
        let ns = [1..n]
        print $ (sum ns) * 10000 `div` length ns
