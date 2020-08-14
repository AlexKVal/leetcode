import java.util.HashMap;
import java.util.Map;
import java.util.Arrays;

class Majel {
  public static int majorityElement(int[] nums) {
    int half = nums.length / 2;
    Map<Integer, Integer> numOccurrences = new HashMap<Integer, Integer>();

    for (int num: nums){
      numOccurrences.compute(num, (k, v) -> (v == null) ? 1 : v + 1);
      if (numOccurrences.get(num) > half) return num;
    }

    return nums[0];
  }

  public static void main(String[] args){
    int[] nums = {3,2,3}; // 3
    // int[] nums = {3,2}; // 3
    // int[] nums = {3}; // 3
    // int[] nums = {-1,-1,2147483647}; // -1

    int res = majorityElement(nums);

    String output = String.format("%s => %d", Arrays.toString(nums), res);
    System.out.println(output);
  }
}
