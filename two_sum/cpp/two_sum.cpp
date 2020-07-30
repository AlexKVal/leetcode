#include <vector>
#include <iostream>
#include <unordered_map>

// brute-force
// std::vector<int> twoSum(std::vector<int>& nums, int target) {
//   auto last_index = nums.size() - 1;
//
//   for(auto i = 0; i < last_index; i++) {
//     auto first = nums[i];
//     for(auto y = i + 1; y <= last_index; y++) {
//       auto second = nums[y];
//
//       if ((first + second) == target)
//         return std::vector<int>{i, y};
//     }
//   }
//
//   return std::vector<int>();
// }

std::vector<int> twoSum(std::vector<int>& nums, int target) {
  std::unordered_map<int, int> complement_to_index;

  for(auto index = 0; index < nums.size(); ++index) {
    // std::cout << "================\n";
    // std::cout << "index: " << index << '\n';

    auto num = nums[index];
    auto complement = target - num;

    if (complement_to_index.find(complement) == complement_to_index.end()) { // !contains
      complement_to_index[complement] = index;
    }

    // std::cout << "complement_to_index: ";
    // for (const auto &pair : complement_to_index) {
    //   std::cout << '{' << pair.first << ": " << pair.second << "} ";
    // }
    // std::cout << '\n';

    auto other_pair = complement_to_index.find(num);
    bool other_found = other_pair != complement_to_index.end();
    if (other_found) {
      auto other_index = other_pair->second;
      if (other_index != index)
        return std::vector<int>{other_index, index};
    }
  }

  return std::vector<int>();
}

void print_results(std::vector<int>& results) {
  std::cout << "result: ";
  if (results.empty())
    std::cout << "[]" << std::endl;
  else
    std::cout << "[" + std::to_string(results[0]) + ", " + std::to_string(results[1]) + "]" << std::endl;
}

// c++ -std=c++11 -o auto auto.cpp
int main(void) {
  std::vector<int> nums{ 2, 5, 5, 11 };
  auto results = twoSum(nums, 10);
  print_results(results);

  nums = { 3, 3 };
  results = twoSum(nums, 6);
  print_results(results);

  nums = { 2, 3, 3 };
  results = twoSum(nums, 6);
  print_results(results);

  return 0;
}
