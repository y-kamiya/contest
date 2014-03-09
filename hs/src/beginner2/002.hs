main :: IO ()
main = do
        s <- getLine
        let ans = [ x  | x <- s, x/='a',x/='i',x/='u',x/='e',x/='o']
        putStr $ ans ++ "\n"



