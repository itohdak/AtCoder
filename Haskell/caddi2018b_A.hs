main = do
  n <- getLine
  putStrLn $ show (length . filter (\c -> c=='2') $ n)
