import Data.List

main = do
  [n, x] <- map read . words <$> getLine
  a <- map read . words <$> getLine
  putStrLn $ show (max (solve n x a) 0)

solve :: Int -> Int -> [Int] -> Int
solve n x a =
  if (last b) == x then (length b) - 1
  else (length b) - 2
  where b = filter (\s -> s<=x) . scanl (+) 0 . sort $ a
