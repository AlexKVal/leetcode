/**
 * @param {number[]} nums
 * @return {void} Do not return anything, modify nums in-place instead.
 */
function moveZeroes(nums) {
  for (i = 0, j = 1; j < nums.length; j++) {
    if (nums[i] != 0) {
      i++
    } else if (nums[j] != 0) {
      nums[i] = nums[j]
      nums[j] = 0
      i++
    }
  }
}

// nums = []
nums = [1,0,1,0,3,0,12]

moveZeroes(nums)

console.log(nums.join())
