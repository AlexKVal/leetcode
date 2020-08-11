#include <stdio.h>
#include <stdlib.h>

void printArray(int* arr, int size){
  printf("[ ");
  int last = size - 1;
  for(int i=0; i<size; i++){
    printf("%d", arr[i]);
    if (i != last) printf(", ");
  }
  puts(" ]");
}

/**
 * Note: The returned array must be malloced
 */
int* runningSum(int* nums, int numsSize, int* returnSize){
  *returnSize = numsSize;
  int* res = malloc(sizeof(int) * numsSize);
  // runningSum[i] = sum(nums[0]…nums[i])
  for (int i = 0; i < numsSize; i++) {
    res[i] = sum;
  }
  return res;
}

// clang sum.c && ./a.out
int main(int argc, char const *argv[]){
  int nums[] = {1, 2, 3, 4}; // [1,3,6,10]

  int size = sizeof(nums)/sizeof(int);
  int retSize = 0;
  int* res = runningSum(nums, size, &retSize);

  printArray(res, retSize);

  return 0;
}
