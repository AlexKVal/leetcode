from functools import reduce
from operator import xor

def singleNumber(nums):
  return reduce(xor, nums)

print(singleNumber([2,2,1]) == 1)
print(singleNumber([4,1,2,1,2]) == 4)
