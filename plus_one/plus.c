#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Note: The returned array must be malloced, assume caller calls free().
int* plusOne(int* digits, int digitsSize, int* returnSize){
	*returnSize = digitsSize;

	bool carryover = false;
	for(int i = digitsSize-1; i >= 0; --i){
		if (digits[i] != 9){
			carryover = false;
			digits[i] += 1;
			break;
		}
		carryover = true;
		digits[i] = 0;
	}

	if (carryover) *returnSize += 1;
	int* retDigits = calloc(*returnSize, sizeof(int));
	memcpy( retDigits, digits, digitsSize * sizeof(int) );
	if (carryover) retDigits[0] = 1;

	return retDigits;
}

// clang plus.c && ./a.out
int main(int argc, char const *argv[]){
	// int digits[] = {4,3,2,9}; // [4,3,3,0]
	// int digits[] = {1,9}; // [2,0]
	int digits[] = {9,9,9,9}; // [1,0,0,0,0]

	int size = sizeof(digits)/sizeof(int);

	int retSize = 0;
	int* retDigits = plusOne(digits, size, &retSize);

	printf("[ ");
	for(int i=0; i<retSize; i++){
		printf("%d ", retDigits[i]);
	}
	printf("]\n");

	return 0;
}

// possible optimization
// detect if an additional digit would be needed: O(n) one, possibly full traverse


// won't work, b/c 1 <= digits.length <= 100, greater than int
// int num = 0;
// for(int i=0; i<digitsSize; i++){
//   num *= 10;
//   num += digits[i];
// }
// printf("num:%d\n", num);

// alt
// int carryover = 1;
// for(int i = digitsSize-1; i >= 0; --i){
//   digits[i] += carryover;
//   if (digits[i] > 9){
//     carryover = digits[i] - 9;
//     digits[i] -= 10;
//   } else {
//     carryover = 0;
//     break;
//   }
// }
