#include <iostream>
#include <vector>
#include <unordered_map>

// more than ⌊ n/2 ⌋ times
int majorityElement(std::vector<int>& nums) {
  int n = nums.size();
  int half = n / 2;
  // std::cout << "half:" << half << '\n';
  std::unordered_map<int, int> numOccurrences;
  for(int i = 0; i < n; i++){
    int num = nums[i];
    if (numOccurrences.find(num) != numOccurrences.end()){
      numOccurrences[num] += 1;
    } else {
      numOccurrences[num] = 1;
    }
    if (numOccurrences[num] > half) return num;
    // std::cout << "numOccurrences[" << num << "]:" << numOccurrences[num] << '\n';
  }

  return nums[0]; // for 2 elements arrays
}

// c++ -std=c++11 majel.cpp && ./a.out
int main(int argc, char const *argv[]){
  // std::vector<int> nums{3,2,3}; // 3
  std::vector<int> nums{2,2,1,1,1,2,2}; // 2
  // std::vector<int> nums{2}; // 2
  // std::vector<int> nums{3, 2}; // 3

  int res = majorityElement(nums);

  std::cout << res << std::endl;

  return 0;
}