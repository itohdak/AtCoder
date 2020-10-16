import Control.Monad

main = do
  [n, h, w] <- map read . words <$> getLine
  ab <- map (map read . words) <$> replicateM n getLine
  putStrLn $ show (length . filter (\[x, y] -> x >= h && y >= w) $ ab)
