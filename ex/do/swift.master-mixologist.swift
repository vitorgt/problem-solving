func timeToPrepare(drinks: [String]) -> Double {
  let timePerDrink = [
    "beer": 0.5, "soda": 0.5, "water": 0.5, "shot": 1, "mixed drink": 1.5,
    "fancy drink": 2.5, "frozen drink": 3,
  ]
  var sum: Double = 0
  for drink in drinks { sum += timePerDrink[drink] ?? 0 }
  return sum
}

func makeWedges(needed: Int, limes: [String]) -> Int {
  let wedgesPerSize = ["small": 4, "medium": 8, "large": 10]
  var count = 0
  var n = needed
  for lime in limes where n > 0 {
    n -= wedgesPerSize[lime] ?? 0
    count += 1
  }
  return count
}

func finishShift(minutesLeft: Int, remainingOrders: [[String]]) -> [[String]] {
  var ml = Double(minutesLeft)
  var willRemain: [[String]] = []
  for ro in remainingOrders {
    if ml > 0 { ml -= timeToPrepare(drinks: ro) } else { willRemain.append(ro) }
  }
  return willRemain
}

func orderTracker(orders: [(drink: String, time: String)]) -> (
  beer: (first: String, last: String, total: Int)?,
  soda: (first: String, last: String, total: Int)?
) { fatalError("Please implement the orderTracker(orders:) function") }
