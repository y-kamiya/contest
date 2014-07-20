import Control.Applicative
import Control.Monad
import Data.List

main :: IO ()
main = do
        (n:k:_) <- fmap (map read . words) getLine :: IO [Int]
        rateList <- fmap (sort . map read . words) getLine :: IO [Int]
        print $ calcMax n k rateList
        
calcMax :: Int -> Int -> [Int] -> Double
calcMax n k rates = (sum $ zipWith (\x y -> 2^x * y) coefs list) / 2^k
    where list = map fromIntegral $ drop (n-k) rates
          coefs = [0..(k-1)]
