{-
-- EPITECH PROJECT, 2024
-- ImageCompressor
-- File description:
-- Main.hs
-}

module Random
    ( getRandomElement
    ) where

import System.Random

getRandomElement :: [a] -> IO a
getRandomElement x = do
    randomIndex <- randomRIO (0, length x - 1)
    return (x !! randomIndex)
