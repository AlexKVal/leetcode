# @param {Integer[]} nums
# @return {Integer}
def remove_duplicates(nums)
  return 0 if nums.size.zero?

  curr_index = 0
  for next_index in 1...nums.size
    if nums[next_index] != nums[curr_index]
      curr_index += 1
      nums[curr_index] = nums[next_index]
    end
  end

  curr_index + 1
end

# nums = []
# nums = [1]
# nums = [1,1,3]
nums = [0,0,1,1,1,2,2,3,3,4]
puts "#{remove_duplicates(nums)} #{nums}"
