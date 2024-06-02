import System.Environment
import System.Exit
import Instructions
import Utils

moveLowestAtFront :: Int -> [Int] -> IO [Int]
moveLowestAtFront lowest (x:xs)
    | lowest == x = return (x:xs)
    | otherwise = putStr "ra " >> moveLowestAtFront lowest (rotate (x:xs))

comebackElem :: [Int] -> IO [Int]
comebackElem [] = putStrLn "" >> return ([])
comebackElem (x:[]) = putStrLn "pa" >> return ([])
comebackElem (x:xs) = putStr "pa " >> comebackElem xs

sortNumbers :: ([Int], [Int]) -> IO [Int]
sortNumbers (l_a, l_b) = case isSorted l_a of
    False -> do
      new_l_a <- moveLowestAtFront lower l_a
      putStr "pb "
      sortNumbers $ pushElem (new_l_a, l_b)
    True -> comebackElem l_b >> return (l_a)
    where
        lower = minimum l_a

main :: IO ()
main = do
  args <- getArgs
  case parseAll args of
    Nothing -> exitWith (ExitFailure 84)
    Just a -> sortNumbers (a, []) >> return ()
