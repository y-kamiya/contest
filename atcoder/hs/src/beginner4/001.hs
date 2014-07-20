import Control.Applicative
import Control.Monad
import Data.List


main :: IO ()
main = do
        n <- read <$> getLine :: IO Integer
        print $ n * 2


