{-
-- EPITECH PROJECT, 2024
-- ImageCompressor
-- File description:
-- Main.hs
-}

module Main (main) where

import System.Environment
import System.Exit
import System.IO
import Lib (getOpts, defaultConf, Conf(..), Pixel(..))
import Sort (sortPixels, getRandomHeads, extractData, getFirsts)
import Math (averagePixel)

checkConvergence :: [Pixel] -> [Pixel] -> Float -> Bool
checkConvergence _ _ (-1.0) = False
checkConvergence [] _ _ = True
checkConvergence _ [] _ = True
checkConvergence (cluster:xs) (aver:ys) conv
  | r > conv || g > conv || b > conv = False
  | otherwise = checkConvergence xs ys conv
    where
      r = fromIntegral $ (_r cluster) - (_r aver)
      g = fromIntegral $ (_g cluster) - (_g aver)
      b = fromIntegral $ (_b cluster) - (_b aver)

printAver :: Pixel -> IO ()
printAver p = putStr $ "(" ++ show r ++ "," ++ show g ++ "," ++ show b ++ ")"
  where
    r = (_r p)
    g = (_g p)
    b = (_b p)

printPixel :: Pixel -> IO ()
printPixel p = (putStr $ "(" ++ show (_x p) ++ "," ++ show (_y p) ++ ") ") >>
  printAver p >> putStrLn ""

printKmeans :: [[Pixel]] -> [Pixel] -> IO ()
printKmeans [] _ = return ()
printKmeans _ [] = return ()
printKmeans (rs:xs) (a:ys) = putStrLn "--" >> printAver a >>
  putStrLn "\n-" >> mapM_ printPixel rs >> printKmeans xs ys

kmeans :: Conf -> [[Pixel]] -> [Pixel] -> IO ()
kmeans conf heads firsts =
  case isConv of
    True -> printKmeans sorted average
    False -> kmeans conf (map (\d -> [d]) average) (getFirsts sorted)
  where
    sorted = sortPixels heads (_data conf) firsts
    average = map averagePixel sorted
    isConv = checkConvergence (getFirsts sorted) average (_limit conf)

run2 :: Conf -> [String] -> IO ()
run2 conf splitted = case traverse extractData splitted of
  Just dat -> do
    heads <- getRandomHeads (_number conf) dat
    let firsts = getFirsts heads
    kmeans (conf { _data = dat }) heads firsts
  Nothing -> exitWith (ExitFailure 84)

run :: Conf -> IO ()
run conf = do
      handle <- openFile (_path conf) ReadMode
      content <- hGetContents handle
      let splitted = lines content
      case length splitted < (_number conf) of
        False -> (run2 conf splitted) >> hClose handle
        True -> hClose handle >> exitWith (ExitFailure 84)

errorHandling :: Conf -> IO ()
errorHandling (Conf (-1) _ _ _ _) = exitWith (ExitFailure 84)
errorHandling (Conf _ (-1.0) _ _ _) = exitWith (ExitFailure 84)
errorHandling (Conf _ _ "" _ _) = exitWith (ExitFailure 84)
errorHandling (Conf _ _ _ _ _) = return ()

main :: IO ()
main = do
    args <- getArgs
    case getOpts defaultConf args of
      Just conf -> (errorHandling conf) >> run conf
      Nothing -> exitWith (ExitFailure 84)
