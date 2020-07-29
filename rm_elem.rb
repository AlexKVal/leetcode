# @param {Integer[]} nums
# @param {Integer} val
# @return {Integer}
def remove_element(nums, val)
  return 0 if nums.size.zero?

  replace_i = 0

  # for num in nums
  #   if num != val
  #     nums[replace_i] = num
  #     replace_i += 1
  #   end
  # end

  nums.each do |num|
    if num != val
      nums[replace_i] = num
      replace_i += 1
    end
  end

  # for i in (0...nums.size)
  #   if nums[i] != val
  #     nums[replace_i] = nums[i]
  #     replace_i += 1
  #   end
  # end

  return replace_i
end

# nums = []; val = 3
# nums = [3,2,2,3]; val = 3
nums = [0,1,2,2,3,0,4,2]; val = 2 # => [0,1,3,0,4]

res = remove_element(nums, val)
puts("#{res} #{nums.inspect} #{val}")
