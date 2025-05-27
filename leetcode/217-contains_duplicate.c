#include <stdbool.h>

/*********************************************/

#include <stdlib.h>

int cmp_int(const void *a, const void *b) {
    return *((int *)a) - *((int *) b);
}


bool containsDuplicateSorting(int* nums, int numsSize) {
    qsort(nums, numsSize, sizeof(int), cmp_int);
    for (int i = 1; i < numsSize; i++) {
        if (nums[i] == nums[i-1])
            return true;
    }
    return false;
}
