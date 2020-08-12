# @param {Integer[]} nums
# @return {Integer}
def majority_element(nums)
  half = nums.size / 2
  num_occurrences = Hash.new(0)
  nums.each do |num|
    num_occurrences[num] += 1
    return num if (num_occurrences[num] > half)
  end
  nums[0] # for the 2 elements arrays
end

# nums = [2,2,1,1,1,2,2] # 2
# nums = [3,2,3] # 3
nums = [3,2] # 3
# nums = [2] # 2

res = majority_element(nums)
puts res.inspect
