{-
-- EPITECH PROJECT, 2024
-- Wolfram
-- File description:
-- Generator.hs
-}

module Generator (genNextLine, genLeft, genRight) where

import Binary (getOutputBit)

combinations :: [(Char, Char, Char)]
combinations = reverse [(a, b, c) | a <- [' ', '*'], b <- [' ', '*'],
  c <- [' ', '*']]

genNextLine :: String -> [Int] -> String
genNextLine [] _ = ""
genNextLine [_] _ = ""
genNextLine [_, _] _ = ""
genNextLine line binary = getOutputBit combinations binary (take 3 line)
  ++ genNextLine (tail line) binary

genLeft :: Int -> Int -> String
genLeft len width
  | len >= width = ""
  | otherwise = genRight len width ++ replicate ((width - len) `mod` 2) ' '

genRight :: Int -> Int -> String
genRight len width
  | len >= width = ""
  | otherwise = replicate ((width - len) `div` 2) ' '
