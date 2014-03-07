main = do
    i <- getLine
    let input = (read i :: Float) / 1000
    putStr $ (getVV input ++ "\n")

getVV :: Float -> String
getVV input 
    | input < 0.1 = "00"
    | input < 1   = "0" ++ (show $ truncate $ input * 10)
    | input <= 5  = show $ truncate $ input * 10
    | input <= 30 = show $ truncate $ input + 50
    | input <= 70 = show $ truncate $ (input - 30) / 5 + 80
    | otherwise   = show 89
