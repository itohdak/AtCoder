main = do
  n <- readLn
  s <- getLine
  putStrLn $ solve n s

solve :: Integer -> String -> String
solve n s =
    case r > b of
      True -> "Yes"
      False -> "No"
    where r = length . filter (\c -> c=='R') $ s
          b = length . filter (\c -> c=='B') $ s

