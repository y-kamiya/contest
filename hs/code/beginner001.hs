main = do
    h1 <- getLine
    h2 <- getLine
    let hh1 = read h1 ::Int
    let hh2 = read h2 ::Int
    print $ (hh1-hh2)
