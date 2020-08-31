using System;

// csc rotate.cs && mono rotate.exe
public class Solution {
	static void Reverse(int[] arr, int firstIndex, int lastIndex) {
		int steps = (lastIndex + 1 - firstIndex) / 2;
		for(int i = 0; i < steps; i++){
			(arr[firstIndex], arr[lastIndex]) = (arr[lastIndex], arr[firstIndex]);
			firstIndex++;
			lastIndex--;
		}
	}

	static void Rotate(int[] nums, int k) {
		k %= nums.Length;
		Reverse(nums, 0, nums.Length-1); // rotate all
		Reverse(nums, 0, k - 1); // rotate left
		Reverse(nums, k, nums.Length-1); // rotate right
	}

	static void Main() {
		// int[] nums = {1,2,3,4,5,6,7}; int k = 3; // [5,6,7,1,2,3,4]
		// int[] nums = {1,2,3,4,5}; int k = 4; // [2,3,4,5,1]
		// int[] nums = {1,2}; int k = 3; // [2,1]
		int[] nums = {1,2}; int k = 1; // [2,1]
		// int[] nums = {1,2,3,4}; int k = 2; // [3,4,1,2]

		Rotate(nums, k);

		Console.WriteLine(string.Join(" ", nums));
	}
}
