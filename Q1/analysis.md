# Q1 – Searching a Library Catalogue

- Linear search pseudocode: scan i from 0 to n−1; compare a[i] with key; return i on match; otherwise return −1.
- Binary search pseudocode: low=0, high=n−1; while low≤high, mid=low+(high−low)/2; compare a[mid], then discard half the interval.
- Linear comparisons: best 1, worst n, average successful approximately (n+1)/2 for equally likely positions; unsuccessful n.
- Binary comparisons: best 1, worst and unsuccessful O(log₂n); exact counts depend on n and key.
- Binary search requires sorted input. The midpoint expression avoids possible overflow in (low+high).
- For 100,000 elements, linear worst case is 100,000 comparisons; binary search needs at most about 17 comparisons.
- Missing keys may require the full search path to establish that the insertion interval is empty.
- Hash table alternative: expected O(1) lookup with extra table space and collision handling; interpolation search can average O(log log n) on uniformly distributed numeric keys but degrades to O(n).
- Sorted insertion costs O(n) shifts in an array; whether sorting is worthwhile depends on lookup frequency, insertion frequency, and update cost.
