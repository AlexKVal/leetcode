from typing import List

def rotate(nums: List[int], k: int) -> None:
	length = len(nums)
	k %= length

	startIdx = 0
	steps = 0
	while steps < length:
		prevIdx = startIdx
		prev = nums[prevIdx]

		while True:
			nextIdx = (prevIdx + k) % length
			print(f"[{prevIdx}]=>[{nextIdx}]")
			tmp = nums[nextIdx]
			nums[nextIdx] = prev
			prev = tmp
			steps += 1
			prevIdx = nextIdx
			if prevIdx == startIdx: break

		startIdx += 1


# nums = [1,2,3,4,5,6,7]; k = 3; # [5,6,7,1,2,3,4]
# nums = [1,2,3,4,5]; k = 4; # [2,3,4,5,1]
# nums = [1,2,3,4]; k = 2; # [3,4,1,2]
nums = [1,2,3,4,5,6]; k = 3; # [4,5,6,1,2,3]
# nums = [1,2]; k = 3; # [2,1]
# nums = [1,2]; k = 1; # [2,1]

rotate(nums, k)

print(nums)
