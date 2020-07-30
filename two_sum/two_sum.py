def twoSum(nums, target):
    """
    :type nums: List[int]
    :type target: int
    :rtype: List[int]
    """
    complement_to_index = {}
    for index, num in enumerate(nums):
      complement = target - num
      if not(complement in complement_to_index):
        complement_to_index[complement] = index

      if num in complement_to_index:
        other_index = complement_to_index[num]
        if other_index != index:
          return [other_index, index]

    return []
    # print(complement_to_index)

print(twoSum([2,5,5,11], 10)) # [ 1, 2 ]
print(twoSum([3,2,4], 6))     # [ 1, 2 ]
print(twoSum([3,3], 6))       # [ 0, 1 ]
