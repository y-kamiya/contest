main = do
    line <- getLine
    let a = words $ line
    let power = getPower (a!!1)
    let dir = getDir ((a!!0), power)
    putStr dir
    putStr " "
    putStr $ show power
    putStr "\n"

getDir :: (String, Int) -> String
getDir (deg, pow)
    | pow == 0 = "C"
    | degree < 11.25 = "N"
    | degree < 33.75 = "NNE"
    | degree < 56.25 = "NE"
    | degree < 78.75 = "ENE"
    | degree < 101.25 = "E"
    | degree < 123.75 = "ESE"
    | degree < 146.25 = "SE"
    | degree < 168.75 = "SSE"
    | degree < 191.25 = "S"
    | degree < 213.75 = "SSW"
    | degree < 236.25 = "SW"
    | degree < 258.75 = "WSW"
    | degree < 281.25 = "W"
    | degree < 303.75 = "WNW"
    | degree < 326.25 = "NW"
    | degree < 348.75 = "NNW"
    | otherwise = "N"
        where degree = (read deg::Float) / 10

getPower :: String -> Int
getPower w
    | v <= 2 = 0
    | v <= 15 = 1
    | v <= 33 = 2
    | v <= 54 = 3
    | v <= 79 = 4
    | v <= 107 = 5
    | v <= 138 = 6
    | v <= 171 = 7
    | v <= 207 = 8
    | v <= 244 = 9
    | v <= 284 = 10
    | v <= 326 = 11
    | otherwise = 12
        where v = fromIntegral $ floor $ (read w / 60) * 10
