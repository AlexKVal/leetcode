using System;

// csc mv_zeroes.cs && mono mv_zeroes.exe
class Solution {
  static void MoveZeroes(int[] nums) {
    for (int i = 0, j = 1; j < nums.Length; j++){
      if (nums[i] != 0){
        i++;
      } else if (nums[j] != 0){
        nums[i] = nums[j];
        nums[j] = 0;
        i++;
      }
    }
  }

  static int Main(){
    // int[] nums = {};
    int[] nums = {0,1,0,3,12};

    MoveZeroes(nums);

    Console.WriteLine($"[{string.Join(", ", nums)}]");

    return 0;
  }
}
