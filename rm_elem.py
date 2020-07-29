from typing import List

def removeElement(nums: List[int], val: int) -> int:
  if len(nums) == 0: return 0

  replace_i = 0

  for num in nums:
    if num != val:
      nums[replace_i] = num
      replace_i += 1

  return replace_i


# nums = []; val = 3
# nums = [3,2,2,3]; val = 3
nums = [0,1,2,2,3,0,4,2]; val = 2 # => [0,1,3,0,4]

res = removeElement(nums, val)

print(f"{res} {nums} {val}")
