# @param {Integer[]} nums
# @param {Integer} k
# @return {Void} Do not return anything, modify nums in-place instead.
def rotate(nums, k)
	k %= nums.size

	steps = 0
	start_idx = 0
	while steps < nums.size
		curr_idx = start_idx
		prev = nums[curr_idx]

		loop do
			next_idx = (curr_idx + k) % nums.size

			# puts "[#{curr_idx}]=>[#{next_idx}]"
			tmp = nums[next_idx]
			nums[next_idx] = prev
			prev = tmp

			steps += 1
			curr_idx = next_idx
			break if curr_idx == start_idx
		end

		start_idx += 1
	end
end

# nums = [1,2,3,4,5,6,7]; k = 3; # [5,6,7,1,2,3,4]
# nums = [1,2,3,4,5]; k = 4; # [2,3,4,5,1]
# nums = [1,2,3,4]; k = 2; # [3,4,1,2]
nums = [1,2,3,4,5,6]; k = 3; # [4,5,6,1,2,3]
# nums = [1,2]; k = 3; # [2,1]
# nums = [1,2]; k = 1; # [2,1]

rotate(nums, k)

p nums
