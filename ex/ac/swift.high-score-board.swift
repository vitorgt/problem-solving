func newScoreBoard() -> [String: Int] { return [String: Int]() }

func addPlayer(_ scores: inout [String: Int], _ name: String, _ score: Int = 0)
{ scores[name] = score }

func removePlayer(_ scores: inout [String: Int], _ name: String) {
  scores.removeValue(forKey: name)
}

func resetScore(_ scores: inout [String: Int], _ name: String) {
  scores[name] = 0
}

func updateScore(_ scores: inout [String: Int], _ name: String, _ delta: Int) {
  scores[name, default: 0] += delta
}

func orderByPlayers(_ scores: [String: Int]) -> [(String, Int)] {
  func players(_ l: (String, Int), _ r: (String, Int)) -> Bool {
    return l.0 < r.0
  }
  return scores.sorted(by: players)
}

func orderByScores(_ scores: [String: Int]) -> [(String, Int)] {
  func highScores(_ l: (String, Int), _ r: (String, Int)) -> Bool {
    return l.1 > r.1
  }
  return scores.sorted(by: highScores)
}

var highScores = newScoreBoard()
print(highScores)

addPlayer(&highScores, "Dave Thomas")
// Adds "Dave Thomas" to the dictionary with a high score of 0.
addPlayer(&highScores, "José Valim", 486_373)
// Adds "José Valim" to the dictionary with a high score of 486_373.
print(highScores)

removePlayer(&highScores, "Dave Thomas")
// Removes "Dave Thomas" from thee dictionary
removePlayer(&highScores, "Rose Fanaras")
// Doesn't alter the dictionary as "Rose Fanaras" is not in the dictionary.
print(highScores)

resetScore(&highScores, "Dave Thomas")
// High score for "Dave Thomas" set to 0
print(highScores)

addPlayer(&highScores, "Freyja Ćirić", 12_771_008)
updateScore(&highScores, "Freyja Ćirić", 73)
// Score for "Freyja Ćirić" updated to 12_771_081
print(highScores)

// updateScore(&highScores, "vitor", 73)
// updateScore(&highScores, "eitor", 73)
// updateScore(&highScores, "zitor", 73)
// print(highScores)

print(orderByPlayers(highScores))
// => [("Dave Thomas", 0), ("Freyja Ćirić", 12_771_091), ("José Valim", 486_373)]

print(orderByScores(highScores))
// => [("Freyja Ćirić", 12_771_091), ("José Valim", 486_373), ("Dave Thomas", 0)]
