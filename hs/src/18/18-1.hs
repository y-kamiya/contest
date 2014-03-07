main = do
    line <- getLine
    let a = words $ line
    let height = read (a!!0)::Float
    let bmi = read (a!!1)::Float
    let weight = bmi * (height*0.01)^2
    print $ (fromIntegral $ round (weight * 1000)) / 1000 
