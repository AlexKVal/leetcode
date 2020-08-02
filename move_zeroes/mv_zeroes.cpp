#include <iostream>
#include <vector>

// i j
// 1,0,2
void moveZeroes(std::vector<int>& nums) {
  int i = 0;
  for (int j=1; j < nums.size(); ++j){
    if (nums[i] != 0){
      i++;
    } else if (nums[j] != 0){
      // std::cout << "swap " << nums[i] << "<->" << nums[j] << "\n";
      nums[i] = nums[j];
      nums[j] = 0;
      i++;
    }
    // std::cout << "i:" << i << " j:" << j << std::endl;
  }
}

//   int i = 0;
//   for (int j=1; j < nums.size(); ++j){
//     if (nums[i] == 0){
//       if (nums[j] != 0){
//         std::cout << "swap " << nums[i] << "<->" << nums[j] << "\n";
//         nums[i] = nums[j];
//         nums[j] = 0;
//         i++;
//       }
//     } else {
//       i++;
//     }

// c++ -std=c++11 mv_zeroes.cpp && ./a.out
int main(int argc, char const *argv[]){
  // std::vector<int> nums {};
  // std::vector<int> nums {0};
  // std::vector<int> nums {12};
  // std::vector<int> nums {0,12};
  // std::vector<int> nums {0,0,0,1};
  // std::vector<int> nums {1,0,0,0};
  std::vector<int> nums {1,0,2};
  // std::vector<int> nums {0,1,0,3,12};
  // std::vector<int> nums {1,0,1,0,3,0};

  moveZeroes(nums);

  for (std::vector<int>::iterator i = nums.begin(); i != nums.end(); ++i)
    std::cout << *i << ' ';
  std::cout << std::endl;

  return 0;
}

// -2--------------------------
//  ! !
// [0,1,0,3,12] if first == 0 && second != 0
// [1,0,0,3,12] swap, i++, j++
//    ! !
// [1,0,0,3,12] if first == 0 && second != 0, else
//    !   !     j++
// [1,0,0,3,12] if first == 0 && second != 0
// [1,3,0,0,12] swap, i++, j++
//      !    !
// [1,3,0,0,12] if first == 0 && second != 0
// [1,3,12,0,0] swap, i++, j++
//         !   !
// [1,3,12,0,0] if j > last, finish
// ----------------------------


// ---------------------------
// does not maintain the relative order
//  !        !
// [0,1,0,3,12] 0 <-> 12
//     !   !    i++, j--
// [12,1,0,3,0]
//       ! !    i++
// [12,1,0,3,0] 0 <-> 3
//      !!      j--
// [12,1,3,0,0] i = j => finish
// ----------------------------
// void moveZeroes(std::vector<int>& nums) {
//   if (nums.size() == 0) return;
//   int i = 0;                // start
//   int j = nums.size() - 1;  // end
//   while (i != j){
//     if (nums[i] == 0){
//       nums[i] = nums[j];
//       nums[j] = 0;
//       j--;
//     } else {
//       i++;
//     }
//   }
// }