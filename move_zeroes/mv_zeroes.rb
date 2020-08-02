# @param {Integer[]} nums
# @return {Void} Do not return anything, modify nums in-place instead.
def move_zeroes(nums)
  i = 0
  for j in (1...nums.size)
    if !nums[i].zero?
      i += 1
    elsif !nums[j].zero?
      nums[i] = nums[j]
      nums[j] = 0
      i += 1
    end
  end
end

# nums = [];
# nums = [0];
# nums = [12];
# nums = [0,12];
# nums = [0,0,0,1];
# nums = [1,0,0,0];
# nums = [1,0,2];
# nums = [0,1,0,3,12];
nums = [1,0,1,0,3,0]

move_zeroes(nums)

puts(nums.inspect)
