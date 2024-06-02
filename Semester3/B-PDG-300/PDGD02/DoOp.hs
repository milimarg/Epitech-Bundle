{-
-- EPITECH PROJECT, 2024
-- Paradigms Seminar
-- File description:
-- Day02
-}

import Data.Char (isDigit)
import Data.List
import System.Environment
import System.Exit

myElem :: Eq a => a -> [a] -> Bool
myElem _ [] = False
myElem n (x:xs)
  | n == x = True
  | otherwise = myElem n xs

safeDiv :: Int -> Int -> Maybe Int
safeDiv x 0 = Nothing
safeDiv x y = Just (x `div` y)

safeNth :: [a] -> Int -> Maybe a
safeNth [] _ = Nothing
safeNth (x:xs) 0 = Just (x)
safeNth (x:xs) n = safeNth xs (n - 1)

safeSucc :: Maybe Int -> Maybe Int
safeSucc Nothing = Nothing
safeSucc (Just (x)) = Just (x + 1)

myLookup :: Eq a => a -> [(a, b)] -> Maybe b
myLookup _ [] = Nothing
myLookup check ((x, y):xs)
  | check == x = Just (y)
  | otherwise = myLookup check xs

maybeDo :: (a -> b -> c) -> Maybe a -> Maybe b -> Maybe c
maybeDo _ Nothing (Just (y)) = Nothing
maybeDo _ (Just (x)) Nothing = Nothing
maybeDo f (Just (x)) (Just (y)) = Just (f x y)

readInt :: [Char] -> Maybe Int
readInt str
  | (str !! 0 == '-') && all isDigit (tail str) = Just (read str :: Int)
  | (str !! 0 /= '-') && all isDigit (str) = Just (read str :: Int)
  | otherwise = Nothing

getLineLength :: IO Int
getLineLength = do
  str <- getLine
  return (length str)

printAndGetLength :: String -> IO Int
printAndGetLength str = putStrLn str >> return (length str)

getBox :: Int -> String
getBox n = "|" ++ replicate ((n - 1) * 2) ' ' ++ "|"

printBox :: Int -> IO ()
printBox 1 = putStrLn "++"
printBox 2 = putStrLn "+--+" >> putStrLn "+--+"
printBox n
  | n <= 0 = return ()
printBox n = putStr "+" >> putStr (replicate ((n - 1) * 2) '-') >> putStrLn "+"
             >> putStrLn (intercalate "\n" (replicate (n - 2) (getBox n))) >>
             putStr "+" >> putStr (replicate ((n - 1) * 2) '-') >> putStrLn "+"

concatLines :: Int -> IO String
concatLines n
  | n <= 0 = return ("")
concatLines n = do
  str <- getLine
  buffer <- concatLines (n - 1)
  return (str ++ buffer)

getInt :: IO (Maybe Int)
getInt = do
  str <- getLine
  return (readInt str)

safeModulo :: Int -> Int -> Maybe Int
safeModulo x 0 = Nothing
safeModulo x y = Just (x `mod` y)

doOpMagicOperator :: [Maybe Int] -> String -> (Maybe Int)
doOpMagicOperator (Nothing:_) _ = Nothing
doOpMagicOperator (_:Nothing:_) _ = Nothing
doOpMagicOperator (Just num1:Just num2:_) "+" = Just (num1 + num2)
doOpMagicOperator (Just num1:Just num2:_) "-" = Just (num1 - num2)
doOpMagicOperator (Just num1:Just num2:_) "*" = Just (num1 * num2)
doOpMagicOperator (Just num1:Just num2:_) "/" = safeDiv num1 num2
doOpMagicOperator (Just num1:Just num2:_) "%" = safeModulo num1 num2

doOpParser :: [String] -> [Maybe Int]
doOpParser (x1:x2:x3:xs) = [readInt x1, readInt x3]

printMaybeInt :: (Maybe Int) -> IO ()
printMaybeInt (Just x) = print x
printMaybeInt Nothing = exitWith (ExitFailure 84)

main :: IO ()
main = do
  argv <- getArgs
  if ((length argv) /= 3)
    then exitWith (ExitFailure 84)
    else return ()
  case safeNth argv 1 of
    Just n -> printMaybeInt (doOpMagicOperator (doOpParser argv) n)
    Nothing -> exitWith (ExitFailure 84)
