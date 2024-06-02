{-
-- EPITECH PROJECT, 2024
-- ImageCompressor
-- File description:
-- Main.hs
-}

module Lib
    ( getOpts,
    defaultConf,
    Conf (..),
    defaultPixel,
    Pixel(..)
    ) where

data Conf = Conf {
    _number :: Int,
    _limit :: Float,
    _path :: String,
    _data :: [Pixel],
    _limitIdx :: Int
} deriving (Show)

defaultConf :: Conf
defaultConf = Conf {
    _number = -1,
    _limit = -1.0,
    _path = "",
    _data = [],
    _limitIdx = 1
}

data Pixel = Pixel {
  _x :: Int,
  _y :: Int,
  _r :: Int,
  _g :: Int,
  _b :: Int
} deriving (Show, Eq)

defaultPixel :: Pixel
defaultPixel = Pixel {
  _x = 0,
  _y = 0,
  _r = 0,
  _g = 0,
  _b = 0
}

getOpts :: Conf -> [String] -> Maybe Conf
getOpts obj [] = Just obj
getOpts _ (_:[]) = Nothing
getOpts obj ("-n":n:xs) = getOpts obj { _number = read n } xs
getOpts obj ("-l":n:xs) = getOpts obj { _limit = read n } xs
getOpts obj ("-f":n:xs) = getOpts obj { _path = n } xs
getOpts _ (_:_) = Nothing
