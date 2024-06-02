{-
-- EPITECH PROJECT, 2024
-- Wolfram
-- File description:
-- Getters.hs
-}

module Getters (getRule, getLines, getStart, getWindow, getMove) where

import Lib

getRule :: Conf -> Int
getRule conf = case (_rule conf) of
  Just _rule -> _rule
  Nothing -> -1

getLines :: Conf -> Int
getLines conf = case (_lines conf) of
  Just _lines -> _lines
  Nothing -> -1

getStart :: Conf -> Int
getStart conf = case (_start conf) of
  Just _start -> _start
  Nothing -> -1

getWindow :: Conf -> Int
getWindow conf = case (_window conf) of
  Just _window -> _window
  Nothing -> -1

getMove :: Conf -> Int
getMove conf = case (_move conf) of
  Just _move -> _move
  Nothing -> -1
