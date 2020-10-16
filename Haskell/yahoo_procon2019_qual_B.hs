import Control.Monad

main = do
  xy <- map (map read . words) <$> replicateM 3 getLine
  putStrLn $ solve xy

solve :: [[Int]] -> String
solve xy =
    let one = length . filter (\x -> elem 1 x) $ xy
        two = length . filter (\x -> elem 2 x) $ xy
        thr = length . filter (\x -> elem 3 x) $ xy
        fou = length . filter (\x -> elem 4 x) $ xy in
    if one >= 3 || two >= 3 || thr >= 3 || fou >= 3 then "NO"
    else "YES"

