from typing import List

def majorityElement(nums: List[int]) -> int:
  half = len(nums) // 2
  numOccurrences = {}
  for num in nums:
    if (num in numOccurrences):
      numOccurrences[num] += 1
    else:
      numOccurrences[num] = 1
    if (numOccurrences[num] > half):
      return num;
  return nums[0] # for 2 size arrays

# nums = [3,2,3] # 3
# nums = [-1,-1,2147483647] # -1
# nums = [3,2] # 3
nums = [3] # 3

res = majorityElement(nums)

print(res)
