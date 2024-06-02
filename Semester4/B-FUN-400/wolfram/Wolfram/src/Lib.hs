{-
-- EPITECH PROJECT, 2024
-- Wolfram
-- File description:
-- Lib.hs
-}

module Lib
    ( getOpts,
      defaultConf,
      Conf(..)
    ) where

import Text.Read (readMaybe)

data Conf = Conf {
  _rule :: Maybe Int,
  _start :: Maybe Int,
  _lines :: Maybe Int,
  _window :: Maybe Int,
  _move :: Maybe Int
} deriving Show

defaultConf :: Conf
defaultConf = Conf {
  _rule = Nothing,
  _start = Just 0,
  _lines = Nothing,
  _window = Just 80,
  _move = Just 0
}

getOpts :: Conf -> [String] -> Maybe Conf
getOpts obj [] = Just obj
getOpts _ (_:[]) = Nothing
getOpts obj ("--rule":n:xs) = getOpts obj { _rule = readMaybe n } xs
getOpts obj ("--start":n:xs) = getOpts obj { _start = readMaybe n } xs
getOpts obj ("--lines":n:xs) = getOpts obj { _lines = readMaybe n } xs
getOpts obj ("--window":n:xs) = getOpts obj { _window = readMaybe n } xs
getOpts obj ("--move":n:xs) = getOpts obj { _move = readMaybe n } xs
getOpts _ (_:_) = Nothing
