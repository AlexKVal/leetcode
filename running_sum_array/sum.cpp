#include <vector>
#include <iostream>

std::vector<int> runningSum(std::vector<int>& nums) {
  for(int acc=0, i=0; i < nums.size(); ++i){
    acc += nums[i];
    nums[i] = acc;
  }
  return nums;
}

void printVector(std::vector<int>& nums){
  std::cout << "[ ";
  for (int i = 0, last = nums.size() - 1; i < nums.size(); ++i){
    std::cout << nums[i];
    if (i != last) std::cout << ", ";
  }
  std::cout << " ]\n";
}

// c++ -std=c++11 sum.cpp && ./a.out
int main(int argc, char const *argv[]){
  // std::vector<int> nums{1,2,3,4}; // [1,3,6,10]
  // std::vector<int> nums{1,1,1,1,1}; // [1,2,3,4,5]
  // std::vector<int> nums{3,1,2,10,1}; // [3,4,6,16,17]
  // std::vector<int> nums;

  auto results = runningSum(nums);
  printVector(results);

  return 0;
}


