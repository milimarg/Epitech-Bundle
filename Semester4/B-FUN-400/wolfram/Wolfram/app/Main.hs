{-
-- EPITECH PROJECT, 2024
-- Wolfram
-- File description:
-- Main.hs
-}

module Main (main) where

import Lib
import Getters (getRule, getLines, getStart, getWindow, getMove)
import Generator (genNextLine, genLeft, genRight)
import Binary (decimalToBinary)
import System.Environment
import System.Exit

mover :: String -> Int -> String
mover line move
  | move >= 0 = spaceFiller ++ take (length line - move) line
  | otherwise = drop (abs move) line ++ spaceFiller
  where
    spaceFiller = replicate (abs move) ' '

mergeParts :: String -> Int -> String
mergeParts line width = genLeft len width ++ line ++ genRight len width
  where
    len = length line

printer :: String -> Int -> Int -> Int -> IO ()
printer line start width move
  | start > 0 = return ()
  | otherwise = putStrLn $ mover (take width $ drop uselessPart merged) move
  where
    merged = mergeParts line width
    uselessPart = (length merged - width) `div` 2

gen :: Int -> String -> Int -> Int -> Int -> [Int] -> IO ()
gen 0 _ _ _ _ _ = exitWith ExitSuccess
gen _lines line start window move binary =
  printer line start window move >>
  gen nextLinesValue nextLine (start - 1) window move binary
  where
    nextLinesValue = if start > 0 then _lines else _lines - 1
    nextLine = genNextLine ("  " ++ line ++ "  ") binary

cRule :: Int -> IO ()
cRule rule
  | rule < 0 || rule > 255 = exitWith (ExitFailure 84)
  | otherwise = return ()

cStart :: Int -> IO ()
cStart start
  | start < 0 = exitWith (ExitFailure 84)
  | otherwise = return ()

cWindow :: Int -> IO ()
cWindow window
  | window < 0 = exitWith (ExitFailure 84)
  | otherwise = return ()

main :: IO ()
main = do
  argv <- getArgs
  case getOpts defaultConf argv of
    Just o -> cRule (getRule o) >> cStart (getStart o) >> cWindow (getWindow o)
      >> gen (getLines o) "*" (getStart o) (getWindow o) _move fullBinary
      where
        _move = getMove o
        binary = decimalToBinary $ getRule o
        fullBinary = replicate (8 - (length binary)) 0 ++ binary
    Nothing -> exitWith (ExitFailure 84)
