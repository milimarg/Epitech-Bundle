{-
-- EPITECH PROJECT, 2024
-- ImageCompressor
-- File description:
-- Main.hs
-}

module Math
    ( distance,
    closest,
    averagePixel
    ) where

import Lib (defaultPixel, Pixel(..))

distance :: Pixel -> Pixel -> Float
distance p1 p2 = sqrt(xp ** 2 + yp ** 2 + zp ** 2)
  where
    xp = fromIntegral $ (_r p1) - (_r p2)
    yp = fromIntegral $ (_g p1) - (_g p2)
    zp = fromIntegral $ (_b p1) - (_b p2)

d :: Pixel -> Pixel -> Float
d p1 p2 = distance p1 p2

closest :: [Pixel] -> Pixel -> Pixel
closest [] _ = defaultPixel
closest refs test = foldr (\b a -> if d b test < d a test then b else a) h refs
  where
    h = (head refs)

average :: [Int] -> Double
average xs = fromIntegral (sum xs) / fromIntegral (length xs)

averagePixel :: [Pixel] -> Pixel
averagePixel pixels = Pixel {
    _x = round (average $ map _x pixels),
    _y = round (average $ map _y pixels),
    _r = round (average $ map _r pixels),
    _g = round (average $ map _g pixels),
    _b = round (average $ map _b pixels)
}
