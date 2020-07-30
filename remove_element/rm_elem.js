/**
 * @param {number[]} nums
 * @param {number} val
 * @return {number}
 */
// function removeElement(nums, val) {
//   let replace_i = 0
//   nums.forEach((num) => {
//     if (num != val){
//       nums[replace_i] = num
//       replace_i++
//     }
//   })
//   return replace_i
// }

// "less writings" variant
function removeElement(nums, val) {
  let newSize = nums.length
  let i = 0
  while (i < newSize){
    // console.log("==============")
    // console.log(`i:${i} num:${nums[i]} newSize:${newSize}`)
    if (nums[i] == val){
      newSize--
      // console.log(`== newSize:${newSize} nums[newSize]:${nums[newSize]}`)
      nums[i] = nums[newSize]
    } else {
      i++
    }
    // console.log(nums)
  }
  return newSize
}

// "condensed" "less writings" variant
function removeElement(nums, val) {
  let i = 0
  let newSize = nums.length
  while (i < newSize){
    if (nums[i] == val)
      nums[i] = nums[--newSize]
    else
      i++
  }
  return newSize
}

// !
// 0,1,2,2,3,0,4,2 8
//   !
// 0,1,2,2,3,0,4,2 8
//     !
// 0,1,2,2,3,0,4,2 8
//     !
// 0,1,2,2,3,0,4,2 7
//       !
// 0,1,2,2,3,0,4,2 7
//       !
// 0,1,2,4,3,0,4,2 6
//         !
// 0,1,2,4,3,0,4,2 6
//           !
// 0,1,2,4,3,0,4,2 6

// nums = []; val = 3
// nums = [3,2,2,3]; val = 3
nums = [0,1,2,2,3,0,4,2]; val = 2 // => [0,1,3,0,4]

res = removeElement(nums, val)

console.log(`${res} [${nums}] ${val}`)
