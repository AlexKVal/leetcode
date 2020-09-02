import java.util.Arrays;

// javac Rotate.java && java Rotate
class Rotate {
	// cyclic replacement O(n)/O(1)
	static void rotate(int[] nums, int k) {
		k %= nums.length;

		int steps = 0;
		for(int startIdx=0; steps < nums.length; startIdx++){
			int currIdx = startIdx;
			int prev = nums[currIdx];
			do {
				int nextIdx = (currIdx + k) % nums.length;
				System.out.println(String.format("[%d]=>[%d]", currIdx, nextIdx));
				int tmp = nums[nextIdx];
				nums[nextIdx] = prev;
				prev = tmp;
				currIdx = nextIdx;
				steps++;
			} while(currIdx != startIdx);
		}
	}

	public static void main(String[] args) {
		// int[] nums = {1,2,3,4,5,6,7}; int k = 3; // [5,6,7,1,2,3,4]
		// int[] nums = {1,2,3,4,5}; int k = 4; // [2,3,4,5,1]
		// int[] nums = {1,2,3,4}; int k = 2; // [3,4,1,2]
		int[] nums = {1,2,3,4,5,6}; int k = 3; // [4,5,6,1,2,3]
		// int[] nums = {1,2}; int k = 3; // [2,1]
		// int[] nums = {1,2}; int k = 1; // [2,1]

		rotate(nums, k);

		System.out.println(Arrays.toString(nums));
	}
}

//       c    prev n
// [0]=>[4]=>[3]=>[2]=>[1]=>[0] (5 steps == 5 length)->stop
// startIdx = 0
// nextIdx = startIdx
//
// tmp = [nextIdx]
// [nextIdx] = prev
// prev = tmp
// nextIdx = (nextIdx + k) % size
// if nextIdx == startIdx, then finish



