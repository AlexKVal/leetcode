#include <stdio.h>
#include <stdlib.h>

void printArray(int* arr, int size){
  printf("[ ");
  for(int i = 0; i < size; i++){
    printf("%d ", arr[i]);
  }
  printf("]\n");
}

// it's guaranteed that nums[i] fits in a 32 bit-signed integer
// rotate right >>
void rotate(int* nums, int numsSize, int k){
  if (k > numsSize) k = k % numsSize; // handle over-rotations

  int overflowStart = numsSize-k;
  if (overflowStart <= 0) return;

  int* overflow = calloc(k, sizeof(int));

  for(int oIdx = 0, i = overflowStart; i < numsSize; i++)
    overflow[oIdx++] = nums[i];

  for(int i = overflowStart-1; i >= 0; i--)
    nums[i+k] = nums[i];

  for(int i = 0; i < k; i++)
    nums[i] = overflow[i];

  free(overflow);
}

// clang rotate.c && ./a.out
int main(int argc, char const *argv[]){
  // int nums[] = {1,2,3,4,5,6,7}; int k = 3; // [5,6,7,1,2,3,4]
  int nums[] = {1,2}; int k = 3; // [2,1]
  // int nums[] = {1,2}; int k = 1; // [2,1]
  int numsSize = sizeof(nums)/sizeof(int);

  rotate(nums, numsSize, k);

  printArray(nums, numsSize);
  return 0;
}

// brute force
// for(int r = 0; r < k; r++){
//   // printf("r:%d\n", r);
//   int lastNum = nums[numsSize - 1];
//   // printf("last:%d\n", lastNum);
//   for(int i = (numsSize - 1); i != 0; i--){
//     // printf("%d:%d %d=>%d\n", i, i-1, nums[i], nums[i - 1]);
//     nums[i] = nums[i - 1];
//   }
//   nums[0] = lastNum;
// }
