#include <iostream>
#include <vector>

// #include <algorithm> // copy
// #include <iterator> // back_inserter
// std::copy(digits.begin(), digits.end(), std::back_inserter(resultArr));

std::vector<int> plusOne(std::vector<int>& digits) {
	int newSize = digits.size();

	bool carryOver = false;
	for(int i=newSize-1; i>=0; i--){
		if(digits[i] == 9){
			carryOver = true;
			digits[i] = 0;
		} else {
			carryOver = false;
			digits[i]++;
			break;
		}
	}

	if (carryOver) newSize++;
	std::vector<int> resultArr(newSize);

	int i = carryOver ? 1 : 0;
	if (carryOver) resultArr[0] = 1;
	for(auto iDgt = digits.begin(); iDgt != digits.end(); iDgt++){
		resultArr[i] = *iDgt;
		i++;
	}

	return resultArr;
}

void printArray(std::vector<int> arr){
	std::cout << "[ ";
	// std::copy(arr.begin(), arr.end(), std::ostream_iterator<int>(std::cout, " "));
	for(auto num : arr) std::cout << num << " ";
	std::cout << "]\n";
}

// c++ -std=c++11 plus.cpp && ./a.out
int main(int argc, char const *argv[]){
	std::vector<int> digits {4,3,2,9}; // [4,3,3,0]
	// std::vector<int> digits {9,9,9,9}; // [1,0,0,0,0]

	auto res = plusOne(digits);

	printArray(res);

	return 0;
}
