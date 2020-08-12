#include <stdio.h>
#include <stdlib.h>

int majorityElement(int* nums, int numsSize){
  int half = numsSize / 2;

  // find max
  int maxValue = nums[0];
  for(int i = 1; i < numsSize; i++){
    if (maxValue < nums[i]) maxValue = nums[i];
  }

  //an array instead of HashMap
  int *numOccurrences = calloc(maxValue+1, sizeof(int));

  // solution
  for(int i = 1; i < numsSize; i++){
    int num = nums[i];
    if (numOccurrences[num] == 0)
      numOccurrences[num] = 1;
    else
      numOccurrences[num] += 1;
    if (numOccurrences[num] > half) return num;
  }

  return nums[0]; // for 2 elements arrays
}

// clang majel.c && ./a.out
int main(int argc, char const *argv[]){
  // int nums[] = {2,2,1,1,1,2,2}; // 2
  // int nums[] = {3,2,3}; // 3
  // int nums[] = {3,2}; // 3
  // int nums[] = {2}; // 2
  // int nums[] = {}; //
  int nums[] = {-1,-1,2147483647}; // -1
  int numsSize = sizeof(nums)/sizeof(int);

  int res = majorityElement(nums, numsSize);

  printf("%d\n", res);

  return 0;
}