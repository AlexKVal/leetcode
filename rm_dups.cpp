#import <iostream>
#import <vector>

int removeDuplicates(std::vector<int>& nums) {
  if (nums.size() == 0) return 0;

  int currIndex = 0;
  for (int nextIndex = 1; nextIndex < nums.size(); ++nextIndex){
    if (nums[nextIndex] != nums[currIndex]){
      currIndex++;
      nums[currIndex] = nums[nextIndex];
    }
  }

  return currIndex + 1;
}

// c++ -std=c++11 rm_dups.cpp && ./a.out
int main(int argc, char const *argv[]){
  // std::vector<int> nums{};
  // std::vector<int> nums{1};
  // std::vector<int> nums{1,1,3};
  std::vector<int> nums{0,0,1,1,1,2,2,3,3,4};
  std::cout << "size: " << nums.size() << '\n';

  auto newLength = removeDuplicates(nums);
  std::cout << newLength << " [ ";
  for (auto i = nums.begin(); i != nums.end(); ++i)
    std::cout << *i << ' ';
  std::cout << "]\n";

  return 0;
}
