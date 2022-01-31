class Solution {
    func uniqueOccurrences(_ arr: [Int]) -> Bool {
		var ca = [Int : Int]()
		var ac = [Int : Int]()

		for i in arr {
			if ac[i] == nil {
				ac[i] = 0
			}
			ac[i] += 1
		}

		for (k, v) in ac {
			ca[v] += 1
			if ca[v] > 1 {
				return false
			}
		}

		return true
    }
}
