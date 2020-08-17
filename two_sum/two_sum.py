def twoSum(nums, target):
    """
    :type nums: List[int]
    :type target: int
    :rtype: List[int]
    """
    numToIndex = {}
    for index, num in enumerate(nums):
      complement = target - num
      if complement in numToIndex:
        return [numToIndex[complement], index]
      numToIndex[num] = index
    return []

print(twoSum([2,5,5,11], 10)) # [ 1, 2 ]
print(twoSum([3,2,4], 6))     # [ 1, 2 ]
print(twoSum([3,3], 6))       # [ 0, 1 ]
