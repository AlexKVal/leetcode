#include <iostream>
#include <vector>
#include <numeric>

int singleNumber(std::vector<int>& nums) {
  return std::accumulate(std::next(nums.begin()), nums.end(), nums[0], std::bit_xor<int>{});
}

// c++ -std=c++11 singnum.cpp && ./a.out
int main(){
  // std::vector<int> nums = {2,2,1}; // 1
  std::vector<int> nums = {4,1,2,1,2}; // 4

  int res = singleNumber(nums);

  std::cout << "res:" << res << std::endl;
  return 0;
}

