main :: IO ()
main = do
        ns <- fmap (map read . words) getLine :: IO [Int]
        print $ calcSquare ns


data Point = Point Int Int deriving Show 

sub :: Point -> Point -> Point
sub (Point x1 y1) (Point x2 y2) = Point (x2-x1) (y2-y1)

det :: Point -> Point -> Int
det (Point a b) (Point c d) = abs (a*d - b*c)

calcSquare :: [Int] -> Float
calcSquare ns = (fromIntegral d) / 2
        where 
            p0 = Point (ns!!0) (ns!!1)
            p1 = Point (ns!!2) (ns!!3)
            p2 = Point (ns!!4) (ns!!5)
            d = det (p1 `sub` p0) (p2 `sub` p0)
