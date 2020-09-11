from typing import List

def removeDuplicates(nums: List[int]) -> int:
  if len(nums) == 0: return 0

  curr_index = 0
  for next_index in range(1, len(nums)):
    if nums[curr_index] != nums[next_index]:
      curr_index += 1
      nums[curr_index] = nums[next_index]

  return curr_index + 1

# nums = []
# nums = [1]
# nums = [1,1,3]
nums = [0,0,1,1,1,2,2,3,3,4]
print( removeDuplicates(nums), nums )


# submitted 1
# def removeDuplicates(nums: List[int]) -> int:
#   if len(nums) == 0:
#     return 0

#   curr_num = nums[0]
#   next_index = replace_position = 1

#   while next_index < len(nums):
#     next_num = nums[next_index]

#     if curr_num != next_num:
#       if replace_position != next_index:
#         nums[replace_position] = next_num
#       replace_position += 1
#       curr_num = next_num

#     next_index += 1

#   return replace_position # new length


# working 'while' 2 with debug
#   curr_num = nums[0]
#   next_index = replace_position = 1

#   while next_index < len(nums):
#     next_num = nums[next_index]
#     print(f"curr:{curr_num} next:{next_num} next_idx:{next_index} repl_pos:{replace_position}")

#     if curr_num != next_num:
#       print("curr != next")
#       if replace_position != next_index:
#         print("repl_pos != next_index")
#         nums[replace_position] = next_num
#       replace_position += 1
#       curr_num = next_num

#     print(f"end:{nums}")
#     next_index += 1

#   return replace_position # new length


# working 'for' with debug
# if len(nums) <= 1: # edge cases
    # return len(nums)
#   for next_index, next_num in enumerate(nums):
#     if next_index == 0:
#       print("skip 0")
#       continue # skip next_index = 0
#     print(f"curr:{curr_num} next:{next_num} next_idx:{next_index} repl_pos:{replace_position}")
#     if curr_num != next_num:
#       print("curr != next")
#       if replace_position != next_index:
#         print("repl_pos != next_index")
#         nums[replace_position] = next_num
#       replace_position += 1
#       curr_num = next_num
#     if next_index == last_index:
#       print("next_index == last_index; break")
#       break

#     print(f"end:{nums}")

#   return replace_position # new length


# before_last_index = len(nums)-2

#   for index, num in enumerate(nums):
#     if index == 0:
#       continue
#     if nums[index-1] == num:
#       indexes_to_remove.append(index)

# last_index = len(nums) - 1
# curr_num = nums[0]
# replace_position = 1
# next_index = 0

#   ||
# [1,2,3,3,3,4]
# != # 1 2
# next_index += 1
# next_num = nums[next_index]
# if curr_num != next_num:
#   if replace_position != next_index:
#     nums[replace_position] = next_num
#   replace_position += 1
#   curr_num = next_num
# if next_index == last_index:
#   return replace_position + 1 # new length

#     ||
# [1,2,3,3,3,4]
# != # 2 3

#       ||
# [1,2,3,3,3,4]
# == # 3 3

#        | |
# [1,2,3,3,3,4]
# == # 3 3

#        |   |
# [1,2,3,3,3,4]
# != # 3 4

# # ========================
# replace_position = 1
# curr_num = 1
#   ||
# [1,1,2,3,3,3,4]
# next_num = 1
# ==
# if next_index == last_index:
#   return
# else:
#   next_index += 1

#    | |
# [1,1,2,3,3,3,4]
# curr_num = 1
# next_num = 2
# !=
# curr_num = nums[replace_position] = next_num
# if next_index == last_index:
#   return
# else:
#   replace_position += 1
#   next_index += 1

#      | |
# [1,2,2,3,3,3,4]
# curr_num = 2
# next_num = 3
# !=
# curr_num = nums[replace_position] = next_num
#   replace_position += 1
#   next_index += 1

#        | |
# [1,2,3,3,3,3,4]
# curr_num = 3
# next_num = 3
# ==
# if next_index == last_index:
#   return
# else:
#   next_index += 1

#        |   |
# [1,2,3,3,3,3,4]
# curr_num = 3
# next_num = 3
# ==
#   next_index += 1

#        |     |
# [1,2,3,3,3,3,4]
# curr_num = 3
# next_num = 4
# !=
# curr_num = nums[replace_position] = next_num
# if next_index == last_index:
#   return replace_position + 1
# [1,2,3,4,3,3,4]
