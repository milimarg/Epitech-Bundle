{-
-- EPITECH PROJECT, 2024
-- Rush 1
-- File description:
-- Main.hs
-}

import System.Environment
import System.Exit
import Instructions
import Utils

run :: ([Int], [Int]) -> [String] -> IO ()
run (a, b) [] = if isSorted a && null b
    then putStrLn "OK"
    else putStr "KO: " >> print (a, b)
run (a, b) ("sa":xs) = run (swapElem a, b) xs
run (a, b) ("sb":xs) = run (a, swapElem b) xs
run (a, b) ("sc":xs) = run (swapElem a, swapElem b) xs
run (a, b) ("pa":xs) = run (mySwap $ pushElem (b, a)) xs
run (a, b) ("pb":xs) = run (pushElem (a, b)) xs
run (a, b) ("ra":xs) = run (rotateFront a, b) xs
run (a, b) ("rb":xs) = run (a, rotateFront b) xs
run (a, b) ("rr":xs) = run (rotateFront a, rotateFront b) xs
run (a, b) ("rra":xs) = run (rotateBack a, b) xs
run (a, b) ("rrb":xs) = run (a, rotateBack b) xs
run (a, b) ("rrr":xs) = run (rotateBack a, rotateBack b) xs
run (a, b) (_) = exitWith (ExitFailure 84)

main :: IO ()
main = do
  args <- getArgs
  instructions <- getLine
  case parseAll args of
    Nothing -> exitWith (ExitFailure 84)
    Just a -> run (a, []) $ words instructions
