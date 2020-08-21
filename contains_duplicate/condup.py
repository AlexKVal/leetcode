def containsDuplicate(nums):
    numsOccurred = set()
    for num in nums:
        if num in numsOccurred:
            return True
        else:
            numsOccurred.add(num)
    return False

# [1,2,3,1] # true

print(containsDuplicate([1,2,3,1]))
