#include <stdio.h>
#include <stddef.h>

static long linear_search(const int a[], size_t n, int key, size_t *comparisons) {
    *comparisons = 0;
    for (size_t i = 0; i < n; ++i) {
        ++*comparisons;
        if (a[i] == key) return (long)i;
    }
    return -1;
}
static long binary_search(const int a[], size_t n, int key, size_t *comparisons) {
    size_t low = 0, high = n;
    *comparisons = 0;
    while (low < high) {
        size_t mid = low + (high - low) / 2;
        ++*comparisons;
        if (a[mid] == key) return (long)mid;
        if (a[mid] < key) low = mid + 1;
        else high = mid;
    }
    return -1;
}
int main(void) {
    int sorted[] = {1021,1048,1103,1190,1222,1305,1377,1402,1460,1533};
    int keys[] = {1021,1305,1533,1400};
    size_t n = sizeof sorted / sizeof sorted[0];
    for (size_t i=0;i<sizeof keys/sizeof keys[0];++i) {
        size_t lc,bc;
        long lp=linear_search(sorted,n,keys[i],&lc);
        long bp=binary_search(sorted,n,keys[i],&bc);
        printf("Book %d -> linear index %ld (%zu comparisons), binary index %ld (%zu comparisons)\n",keys[i],lp,lc,bp,bc);
    }
    return 0;
}