class Solution {
  func search(_ nums: [Int], _ target: Int) -> Int {
    var l = 0
    var r = nums.count - 1
    var m = 0
    while l <= r {
      m = l + (r - l) / 2
      if nums[m] == target {
        return m
      } else if nums[m] < target {
        l = m + 1
      } else {
        r = m - 1
      }
    }
    return -1
  }
}
