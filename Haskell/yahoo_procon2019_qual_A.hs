main = do
  [n, k] <- map read . words <$> getLine
  putStrLn $ if (n+1)/2 >= k then "YES" else "NO"
