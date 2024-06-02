{-
-- EPITECH PROJECT, 2024
-- Wolfram
-- File description:
-- Binary.hs
-}

module Binary (decimalToBinary, getOutputBit) where

decimalToBinary :: Int -> [Int]
decimalToBinary 0 = [0]
decimalToBinary n = reverse $ decimalToBinary n
  where
    decimalToBinary 0 = []
    decimalToBinary num = num `mod` 2 : decimalToBinary (num `div` 2)

getOutputBit :: [(Char, Char, Char)] -> [Int] -> [Char] -> String
getOutputBit [] [] _ = ""
getOutputBit ((x, y, z):xs) (w:ws) [a, b, c]
  | x == a && y == b && z == c = if (w == 0) then " " else "*"
  | otherwise = getOutputBit xs ws [a, b, c]
