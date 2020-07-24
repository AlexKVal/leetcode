/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
function twoSum(nums, target) {
  const complement_to_index = {}
  for(let index = 0; index < nums.length; index++) {
    // console.log("=============")
    // console.log(`index: ${index}`)

    const num = nums[index]
    // console.log(`num: ${num}`)

    const complement = target - num
    // console.log(`complement: ${complement}`)

    if (!(complement in complement_to_index)) {
      complement_to_index[complement] = index
      // console.log(`complement_to_index[${complement}] = ${index}`)
    }
    // console.log(complement_to_index)

    const other_index = complement_to_index[num]
    // console.log(`other_index: ${other_index}`)
    if ((other_index != undefined) && (other_index != index)) {
      return [other_index, index]
    }
  }

  return []
};

console.log(twoSum([2,5,5,11], 10)) // [ 1, 2 ]
console.log(twoSum([3,2,4], 6))     // [ 1, 2 ]
console.log(twoSum([3,3], 6))       // [ 0, 1 ]

// 1
// let end_index = nums.length - 1
// for(let i = 0; i < end_index; i++) {
//   let first = nums[i]
//   for(let y = i + 1; y <= end_index; y++) {
//     let second = nums[y]
//     if ((first + second) == target) {
//       return([i, y])
//     }
//   }
// }