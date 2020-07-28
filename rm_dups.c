#import <stdio.h>

// clang rm_dups.c && ./a.out
int removeDuplicates(int* nums, int numsSize){
  if (numsSize == 0) return 0;

  int currIndex = 0;
  for (int nextIndex = 0; nextIndex < numsSize; ++nextIndex){
    if (nums[nextIndex] != nums[currIndex]){
      currIndex++;
      nums[currIndex] = nums[nextIndex];
    }
  }

  return currIndex + 1;
}

int main(int argc, char const *argv[]){
  // int nums[] = {};
  // int nums[] = {1};
  // int nums[] = {1,1,3};
  int nums[] = {0,0,1,1,1,2,2,3,3,4};
  int numsSize = sizeof(nums) / sizeof(int);
  printf("numsSize: %d\n", numsSize);

  int newLength = removeDuplicates(nums, numsSize);
  printf("%d [ ", newLength);
  for (int i = 0; i < numsSize; ++i){
    printf("%d ", nums[i]);
  }
  printf("]\n");

  return 0;
}
