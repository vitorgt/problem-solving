func sumSquareDifference(_ n: Int = 100) -> Int {
  let squareOfSum = n * n * (n + 1) * (n + 1) / 4
  let sumOfSquares = (2 * n + 1) * (n + 1) * n / 6
  return squareOfSum - sumOfSquares
}

// Exercism answering structure
struct Squares {
  var n = 100
  init(_ n: Int) { if n > 0 { self.n = n } }
  var squareOfSum: Int { return n * n * (n + 1) * (n + 1) / 4 }
  var sumOfSquares: Int { return (2 * n + 1) * (n + 1) * n / 6 }
  var differenceOfSquares: Int { return squareOfSum - sumOfSquares }
}
