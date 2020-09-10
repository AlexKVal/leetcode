import java.util.Arrays;

class Plus {
	public static int[] plusOne(int[] digits) {
		int carryover = 0;
		for(int i=digits.length-1; i>=0; i--){
			if (digits[i] == 9){
				carryover = 1;
				digits[i] = 0;
			} else {
				carryover = 0;
				digits[i]++;
				break;
			}
		}

		int[] result = new int[digits.length + carryover];
		System.arraycopy(digits, 0, result, carryover, digits.length);
		if (carryover == 1) result[0] = 1;
		return result;
	}

	public static void main(String[] args){
		int[] digits = {4,3,9};
		// int[] digits = {9,9,9};
		int[] res = plusOne(digits);
		System.out.println(Arrays.toString(res));
	}
}
