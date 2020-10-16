main = do
  [a, b, c] <- map read . words <$> getLine
  putStrLn $ solve a b c

solve :: Int -> Int -> Int -> String
solve a b c = case a==b && a==c of
                True -> "Yes"
                False -> "No"
