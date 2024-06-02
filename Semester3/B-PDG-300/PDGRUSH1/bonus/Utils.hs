{-
-- EPITECH PROJECT, 2024
-- Rush 1
-- File description:
-- Utils.hs
-}

module Utils where
import Text.Read (readMaybe)

parseAll :: [String] -> Maybe [Int]
parseAll args = traverse readMaybe args

mySwap :: (a , b) -> (b , a)
mySwap (a, b) = (b, a)

isSorted :: [Int] -> Bool
isSorted [] = True
isSorted [_] = True
isSorted (x:y:xs) = x <= y && isSorted (y:xs)
