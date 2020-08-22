#include <stdio.h>

// it's guaranteed that nums[i] fits in a 32 bit-signed integer
// rotate right >>
// brute force O(n^2)
void rotate(int* nums, int numsSize, int k){
  for(int r = 0; r < k; r++){
    // printf("r:%d\n", r);
    int lastNum = nums[numsSize - 1];
    // printf("last:%d\n", lastNum);
    for(int i = (numsSize - 1); i != 0; i--){
      // printf("%d:%d %d=>%d\n", i, i-1, nums[i], nums[i - 1]);
      nums[i] = nums[i - 1];
    }
    nums[0] = lastNum;
  }
}

void printArray(int* arr, int size){
  printf("[ ");
  for(int i = 0; i < size; i++){
    printf("%d ", arr[i]);
  }
  printf("]\n");
}

// clang rotate.c && ./a.out
int main(int argc, char const *argv[]){
  int nums[] = {1,2,3,4,5,6,7}; int k = 3; // [5,6,7,1,2,3,4]
  int numsSize = sizeof(nums)/sizeof(int);

  rotate(nums, numsSize, k);

  printArray(nums, numsSize);
  return 0;
}
