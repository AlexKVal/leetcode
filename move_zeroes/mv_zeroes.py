from typing import List

def moveZeroes(nums: List[int]) -> None:
  i = 0
  for j, num in enumerate(nums):
    if (nums[i] != 0):
      i += 1
    elif (nums[j] != 0):
      nums[i] = num
      nums[j] = 0
      i += 1


# nums = [];
# nums = [0];
# nums = [12];
# nums = [0,12];
# nums = [0,0,0,1];
# nums = [1,0,0,0];
# nums = [1,0,2];
# nums = [0,1,0,3,12];
nums = [1,0,1,0,3,0]

moveZeroes(nums)

print(nums)
