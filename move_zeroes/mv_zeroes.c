#include <stdio.h>

void moveZeroes(int* nums, int numsSize){
  for (int i = 0, j = 1; j < numsSize; j++){
    if (nums[i] != 0) {
      i++;
    } else if (nums[j] != 0){
      nums[i] = nums[j];
      nums[j] = 0;
      i++;
    }

    // if (nums[i] == 0 && (nums[j] == 0) ) continue;
    // if (nums[i] == 0 && (nums[j] != 0) ){
    //   nums[i] = nums[j];
    //   nums[j] = 0;
    // }
    // i++;

    // if (nums[i] != 0) {
    //   i++;
    //   continue;
    // }
    // if (nums[j] != 0){
    //   nums[i] = nums[j];
    //   nums[j] = 0;
    //   i++;
    // }
  }

  return;
}

// clang mv_zeroes.c && ./a.out
int main(int argc, char const *argv[]){
  // int nums[] = {};
  // int nums[] = {0};
  // int nums[] = {12};
  // int nums[] = {0,12};
  // int nums[] = {0,0,0,1};
  // int nums[] = {1,0,0,0};
  // int nums[] = {1,0,2};
  // int nums[] = {0,1,0,3,12};
  int nums[] = {1,0,1,0,3,0};

  int numsSize = sizeof(nums)/sizeof(int);
  moveZeroes(nums, sizeof(nums)/sizeof(int));

  for(int i = 0; i < numsSize; i++)
    printf("%d ", nums[i]);
  printf("\n");

  return 0;
}
