#include <iostream>
#include <vector>

int removeElement(std::vector<int>& nums, int val){
  //
  return 3;
}

// c++ -std=c++11 rm_elem.cpp && ./a.out
int main(int argc, char const *argv[]){
  std::vector<int> nums{}; int val = 3;
  // std::vector<int> nums{3,2,2,3}; int val = 3;
  // std::vector<int> nums{0,1,2,2,3,0,4,2}; int val = 2;

  auto newLength = removeElement(nums, val);
  std::cout << newLength << " [ ";
  for(auto el = nums.begin(); el != nums.end(); ++el)
    std::cout << *el << ' ';
  std::cout << "] " << val << '\n';

  return 0;
}