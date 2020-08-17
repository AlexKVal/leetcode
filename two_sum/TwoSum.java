import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;

class TwoSum {
  public static int[] twoSum(int[] nums, int target) {
    Map<Integer, Integer> complements = new HashMap<Integer, Integer>(nums.length);

    for (int i = 0; i < nums.length; i++){
      int num = nums[i];
      int complement = target - num;

      if (!complements.containsKey(complement))
        complements.put(complement, i);

      if (complements.containsKey(num)){
        int firstIndex = complements.get(num);
        if (firstIndex != i)
          return new int[]{firstIndex, i};
      }
    }
    return new int[0];
  }

  public static void main(String[] args){
    // int[] nums = {2,5,5,11}; int target = 10; // [ 1, 2 ]
    int[] nums = {3,2,4}; int target = 6;     // [ 1, 2 ]
    // int[] nums = {3,3}; int target = 6;       // [ 0, 1 ]

    int[] resPair = twoSum(nums, target);

    System.out.println(Arrays.toString(resPair));
  }
}
