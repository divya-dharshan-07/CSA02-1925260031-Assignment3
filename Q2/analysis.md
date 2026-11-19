# Q2 – Sorting the Examination Hall Seating Register

The source instruments comparisons and element moves for bubble sort (early exit), selection sort and insertion sort. Run it on sorted, nearly sorted, reverse and random data.

| Algorithm | Best | Average | Worst | Stable? |
|---|---:|---:|---:|---|
| Bubble (early exit) | O(n) | O(n²) | O(n²) | Yes |
| Selection | O(n²) | O(n²) | O(n²) | No (standard swap version) |
| Insertion | O(n) | O(n²) | O(n²) | Yes |

Insertion sort is appropriate for a mostly sorted register with a small number of late entries: only nearby shifts may be needed. Counting sort is O(n+k) time and O(k) auxiliary space when keys are integers in a reasonably small known range; it is unsuitable when k is huge relative to n or keys are not discrete bounded integers. The run counters count three assignments for a swap and one assignment per insertion shift/key placement; state this convention when comparing measurements.
