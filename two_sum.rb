def two_sum(nums, target)
    complement_to_index = {}
    nums.each_with_index do |num, index|
        # puts "============="
        # puts "num: #{num}"

        complement = target - num
        # puts "complement: #{complement}"

        complement_to_index[complement] = index unless complement_to_index[complement]
        # puts "complement_to_index: #{complement_to_index.inspect}"

        other_index = complement_to_index[num]
        # puts "other_index: #{other_index}"

        if other_index && (other_index != index)
          return [other_index, index]
        end
    end

    return []
end

p two_sum([3,3], 6)


    # second_i_map = {}
    # for first_i in (0..end_index)
    #     first_number = nums[first_i]
    #     puts "first_number: #{first_number}"

    #     complement = target - first_number
    #     puts "complement: #{complement}"

    #     second_i_map[complement] = first_i
    #     puts "second_i_map: #{second_i_map.inspect}"

    #     second_i = second_i_map[first_number]
    #     puts "second_i: #{second_i}"

    #     if second_i && (second_i != first_i)
    #       return [second_i, first_i]
    #     end
    # end

# second_i_map[complement] = first_i
# 6-3 3 => 0
# 6-2 4 => 1
# 6-4 2 => 2

# 3 => 0 != 0
# 2 => none
# 4 => [1, 2]

    # 1
    # for i in (0...end_index)
    #     first = nums[i]
    #     for y in ((i + 1)..end_index)
    #         second = nums[y]
    #         return [i, y] if (first + second) == target
    #     end
    # end

    # 2
    # second_i_map = {}
    # for i in (0...end_index)
    #     first_number = nums[i]
    #     complement = target - first_number
    #     second_i_map[complement] = i
    # end

    # for first_i in (0...end_index)
    #     first_n = nums[first_i]
    #     second_i = second_i_map[first_n]
    #     if second_i && (second_i != first_i)
    #       return [first_i, second_i]
    #     end
    # end
    #
    # [2, 5, 5, 11]
    # 10
    # 8 => 0
    # 5 => 2
    # -1 => 3
