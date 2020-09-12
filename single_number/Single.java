import java.util.Arrays;

class Single{
	public static int singleNumber(int[] nums) {
		return Arrays.stream(nums).reduce(0, (res, num) -> res ^ num);
	}

	public static void main(String[] args){
		int[] nums = {2,2,1};
		System.out.println(singleNumber(nums));
	}
}
