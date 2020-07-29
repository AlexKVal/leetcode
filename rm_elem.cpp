#include <iostream>
#include <vector>

int removeElement(std::vector<int>& nums, int val){
  if (nums.size() == 0) return 0;

  int index_for_replace = 0;
  for(int i = 0; i < nums.size(); ++i){
    // std::cout << "============\n";
    if (nums[i] != val){
      // std::cout << "nums[i]:" << nums[i] << " != val:" << val << "\n";
      nums[index_for_replace] = nums[i];
      ++index_for_replace;
    }
  }

  return index_for_replace;
}

// c++ -std=c++11 rm_elem.cpp && ./a.out
int main(int argc, char const *argv[]){
  // std::vector<int> nums{}; int val = 3;
  // std::vector<int> nums{3,2,2,3}; int val = 3;
  std::vector<int> nums{0,1,2,2,3,0,4,2}; int val = 2; // => [0,1,3,0,4]

  auto newLength = removeElement(nums, val);
  std::cout << newLength << " [ ";
  for(auto el = nums.begin(); el != nums.end(); ++el)
    std::cout << *el << ' ';
  std::cout << "] " << val << '\n';

  return 0;
}

// ||
// 0, 1, 2, 2, 3, 0, 4, 2
// 0 != 2

//   ||
// 0, 1, 2, 2, 3, 0, 4, 2
// 1 != 2

//      ||
// 0, 1, 2, 2, 3, 0, 4, 2
// 2 == 2 -> move only next_index

//       |  |
// 0, 1, 2, 2, 3, 0, 4, 2
// 2 == 2 -> move only next_index

//       |     |
// 0, 1, 2, 2, 3, 0, 4, 2
// 3 != 2 -> put, move put_index,
//          |     |
// 0, 1, 3, 2, 3, 0, 4, 2
// 0 != 2 -> put, move put_index,
//             |     |
// 0, 1, 3, 0, 3, 0, 4, 2
// 4 != 2
//                |     |
// 0, 1, 3, 0, 4, 0, 4, 2
// 2 == 2
// last => finish: first_index as newLength
