{-
-- EPITECH PROJECT, 2024
-- ImageCompressor
-- File description:
-- Sort.hs
-}

module Sort
    ( extractData,
      getRandomHeads,
      sortPixels,
      getFirstPixel,
      getFirsts
    ) where

import Lib (defaultPixel, Pixel(..))
import Random (getRandomElement)
import Math (closest)
import Data.List (elemIndex)
import Text.Read

extractData :: String -> Maybe Pixel
extractData line = case words line of
  [position, color] -> do
    (x, y) <- readMaybe position
    (r, g, b) <- readMaybe color
    Just defaultPixel { _x = x, _y = y, _r = r, _g = g, _b = b }
  _ -> Nothing

removeElement :: Pixel -> [Pixel] -> [Pixel]
removeElement element list = filter (/= element) list

getRandomHeads :: Int -> [Pixel] -> IO [[Pixel]]
getRandomHeads 0 _ = return([])
getRandomHeads n array = do
  pixel <- getRandomElement array
  rest <- getRandomHeads (n - 1) (removeElement pixel array)
  return ([pixel] : rest)

getFirstPixel :: [Pixel] -> Pixel
getFirstPixel [] = defaultPixel
getFirstPixel x = last x

getFirsts :: [[Pixel]] -> [Pixel]
getFirsts arrays = map getFirstPixel arrays

appendData2 :: [Pixel] -> Pixel -> Int -> Int -> [Pixel]
appendData2 heads pixel n i
  | n == i = pixel : heads
  | otherwise = heads

appendData :: [[Pixel]] -> Pixel -> [Pixel] -> [[Pixel]]
appendData heads p firsts = case elemIndex (closest firsts p) firsts of
  Just i -> map (\(d, i2) -> appendData2 d p i i2) (zip heads [0..])
  Nothing -> heads

sortPixels :: [[Pixel]] -> [Pixel] -> [Pixel] -> [[Pixel]]
sortPixels heads [] _ = heads
sortPixels heads (x:pixels) firsts = sortPixels list pixels firsts
  where
    list = (appendData heads x firsts)
