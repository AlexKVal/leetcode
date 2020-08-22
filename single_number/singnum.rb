def single_number(nums)
  nums.reduce(:^)
  # acc = nums[0]
  # for i in (1...nums.size)
  #   acc ^= nums[i]
  # end
  # return acc
end

puts(single_number([2,2,1]) == 1)
puts(single_number([4,1,2,1,2]) == 4)


# O(log(n)) b/c of sort
# def single_number(nums)
#   nums.sort!
#   i = 0
#   while(i < nums.size)
#     j = i + 1
#     break if j >= nums.size
#     return nums[i] if (nums[i] != nums[j])
#     i += 2
#   end
#   return nums.last
# end