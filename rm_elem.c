#include <stdio.h>

int removeElement(int* nums, int numsSize, int val){
  if (numsSize == 0) return 0;

  int replace_i = 0;
  for (int i = 0; i < numsSize; ++i){
    if (nums[i] != val){
      nums[replace_i] = nums[i];
      ++replace_i;
    }
  }

  return replace_i;
}

// clang rm_elem.c && ./a.out
int main(int argc, char const *argv[]){
  // int nums[] = {}; int val = 3;
  // int nums[] = {3,2,2,3}; int val = 3;
  int nums[] = {0,1,2,2,3,0,4,2}; int val = 2; // => [0,1,3,0,4]
  int numsSize = sizeof(nums) / sizeof(int);

  int newLength = removeElement(nums, numsSize, val);

  printf("%d [ ", newLength);
  for(int i = 0; i < numsSize; ++i){
    printf("%d ", nums[i]);
  }
  printf("] %d\n", val);

  return 0;
}
