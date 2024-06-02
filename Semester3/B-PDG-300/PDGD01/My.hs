{-
-- EPITECH PROJECT, 2024
-- Paradigms Seminar
-- File description:
-- Day01
-}

mySucc :: Int -> Int
mySucc x = x + 1

myIsNeg :: Int -> Bool
myIsNeg x = x < 0

myAbs :: Int -> Int
myAbs x
  | x < 0 = x * (-1)
  | otherwise = x

myMin :: Int -> Int -> Int
myMin x y
  | x < y = x
  | otherwise = y

myMax :: Int -> Int -> Int
myMax x y
  | x > y = x
  | otherwise = y

myTuple :: a -> b -> (a, b)
myTuple x y = (x, y)

myTruple :: a -> b -> c -> (a, b, c)
myTruple a b c = (a, b, c)

myFst :: (a, b) -> a
myFst (x, y) = x

mySnd :: (a, b) -> b
mySnd (x, y) = y

mySwap :: (a, b) -> (b, a)
mySwap (a, b) = (b, a)

myHead :: [a] -> a
myHead [] = error "empty list"
myHead (x:xs) = x

myTail :: [a] -> [a]
myTail [] = error "empty list"
myTail (x:xs) = xs

myLength :: [a] -> Int
myLength [] = 0
myLength (x:xs) = 1 + myLength(xs)

myNth :: [a] -> Int -> a
myNth [] _ = error "empty list or index out of range"
myNth (x:xs) 0 = x
myNth (x:xs) n = myNth xs (n - 1)

myTake :: Int -> [a] -> [a]
myTake 0 (x:xs) = []
myTake _ [] = []
myTake n (x:xs) = x : (myTake (n - 1) xs)

myDrop :: Int -> [a] -> [a]
myDrop _ [] = []
myDrop 0 list = list
myDrop n (x:xs) = myDrop (n - 1) xs

myAppend :: [a] -> [a] -> [a]
myAppend [] ys = ys
myAppend (x:xs) ys = x : (myAppend xs ys)

myReverse :: [a] -> [a]
myReverse [] = []
myReverse (x:xs) = myAppend (myReverse xs) [x]

myInit :: [a] -> [a]
myInit [] = error "empty list"
myInit [_] = []
myInit (x:xs) = myAppend [x] (myInit xs)

myLast :: [a] -> a
myLast [] = error "empty list"
myLast (x:[]) = x
myLast (x:xs) = myLast xs

myZip :: [a] -> [b] -> [(a, b)]
myZip _ [] = []
myZip [] _ = []
myZip (x:xs) (y:ys) = myAppend [(x, y)] (myZip xs ys)

myUnzip :: [(a, b)] -> ([a], [b])
myUnzip [] = ([], [])
myUnzip ((x, y):xs) = (x:first, y:second)
    where (first, second) = myUnzip xs

myMap :: (a -> b) -> [a] -> [b]
myMap _ [] = []
myMap f (x:xs) = f x : (myMap f xs)

myFilter :: (a -> Bool) -> [a] -> [a]
myFilter _ [] = []
myFilter f (x:xs)
  | (f x) == True = myAppend [x] (myFilter f xs)
  | otherwise = myFilter f xs

myFoldl :: (b -> a -> b) -> b -> [a] -> b
myFoldl f start (x:[]) = f start x
myFoldl f start (x:xs) = myFoldl f (f start x) xs

myFoldr :: (a -> b -> b) -> b -> [a] -> b
myFoldr f start (x:[]) = f x start
myFoldr f start (x:xs) = f x (myFoldr f start xs)

myPartition :: (a -> Bool) -> [a] -> ([a], [a])
myPartition _ [] = ([], [])
myPartition f (x:xs)
  | f x == True = (x : leftList, rightList)
  | otherwise = (leftList, x : rightList)
    where (leftList, rightList) = myPartition f xs

myQuickSort :: (a -> a -> Bool) -> [a] -> [a]
myQuickSort _ [] = []
myQuickSort f (x:u) = myQuickSort f b `myAppend` [x] `myAppend` myQuickSort f a
    where (a, b) = myPartition (f x) u
