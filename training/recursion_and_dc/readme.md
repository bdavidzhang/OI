# Recursion and dividing and conquering
**todo: implmeent merge sort in mergesort.cpp**

The idea is that recursion is self-referencial. I am, in fact, incredibly familiar with this topic, so not much further epxlaination is required on identifying recursion. The harder part is to implemen. Which, surprisinly, is the harder part. Typically, recursion tends to be easier to implement than its iterative counterpart (a solution that requirs loops). 

Recursion is implemented using a *recursion stack*, which operates a bit slower than the iterative counterpart.

DC is a strategy that divides a problem into various sub-problems, and calculates the solution by merging them together. A great example is the case with merge-sort, where the process is iterative on splitting the array in half, sorting either array recursively, and merging them together.

