{-
-- EPITECH PROJECT, 2024
-- Rush 1
-- File description:
-- Instructions.hs
-}

module Instructions where

pushElem :: ([Int], [Int]) -> ([Int], [Int])
pushElem ([], b) = ([], b)
pushElem ((x:xs), b) = (xs, x:b)

swapElem :: [Int] -> [Int]
swapElem [] = []
swapElem [a] = [a]
swapElem (x:y:xs) = y:x:xs

rotateBack :: [Int] -> [Int]
rotateBack [] = []
rotateBack list = last list : init list

rotateFront :: [Int] -> [Int]
rotateFront [] = []
rotateFront (x:xs) = xs ++ [x]
