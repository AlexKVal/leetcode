using System;

// csc rm_elem.cs && mono rm_elem.exe
public class Solution {
    public static int RemoveElement(int[] nums, int val) {
        if (nums.Length == 0) return 0;

        int indexForReplace = 0;
        for (int i = 0; i < nums.Length; ++i){
            if (nums[i] != val) {
                nums[indexForReplace] = nums[i];
                ++indexForReplace;
            }
        }

        return indexForReplace;
    }

    public static int Main(){
        // int[] nums = {}; int val = 3;
        // int[] nums = {3,2,2,3}; int val = 3;
        int[] nums = {0,1,2,2,3,0,4,2}; int val = 2; // => [0,1,3,0,4]

        int newLength = RemoveElement(nums, val);
        Console.WriteLine($"{newLength} [{string.Join(",", nums)}] {val}");

        return 0;
    }
}
