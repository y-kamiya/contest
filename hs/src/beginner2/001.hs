import Control.Applicative

main :: IO ()
main = do
        ss <- words <$> getLine
        let ns = map read ss :: [Int]
        print $ max (ns!!0) (ns!!1)
