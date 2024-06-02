{-
-- EPITECH PROJECT, 2024
-- Paradigms Seminar
-- File description:
-- Day03
-}

data Tree a = Empty | Node (Tree a) a (Tree a) deriving (Eq, Show)

addInTree :: Ord a => a -> Tree a -> Tree a
addInTree x Empty = Node Empty x Empty
addInTree x (Node left value right)
  | x < value = Node (addInTree x left) value right
  | otherwise = Node left value (addInTree x right)

instance Functor Tree where
  fmap f Empty = Empty
  fmap f (Node left value right) = Node (fmap f left) (f value) (fmap f right)

listToTree :: Ord a => [a] -> Tree a
listToTree [] = Empty
listToTree (x:xs) = addInTree x (listToTree xs)

treeToList :: Ord a => Tree a -> [a]
treeToList Empty = []
treeToList (Node l value r) = (treeToList l) ++ [value] ++ (treeToList r)

treeSort :: Ord a => [a] -> [a]
treeSort tree = treeToList $ (listToTree tree)

instance Foldable Tree where
  foldl f acc Empty = acc
  foldl f acc (Node l value r) = foldl f (f (foldl f acc l) value) r
  foldr f acc Empty = acc
  foldr f acc (Node l value r) = foldr f (f value (foldr f acc r)) l
