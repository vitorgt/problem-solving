func getCard(at index: Int, from stack: [Int]) -> Int {
  return stack[index]
}

func setCard(at index: Int, in stack: [Int], to newCard: Int) -> [Int] {
  var s = stack
  if 0 <= index && index < s.count {
    s[index] = newCard
  }
  return s
}

func insert(_ newCard: Int, atTopOf stack: [Int]) -> [Int] {
  var s = stack
  s.append(newCard)
  return s
}

func removeCard(at index: Int, from stack: [Int]) -> [Int] {
  var s = stack
  if 0 <= index && index < s.count {
    s.remove(at: index)
  }
  return s
}

func removeTopCard(_ stack: [Int]) -> [Int] {
  var s = stack
  if s.count > 0 {
    s.removeLast(1)
  }
  return s
}

func insert(_ newCard: Int, atBottomOf stack: [Int]) -> [Int] {
  var s = stack
  s.insert(newCard, at: 0)
  return s
}

func removeBottomCard(_ stack: [Int]) -> [Int] {
  var s = stack
  if s.count > 0 {
    s.remove(at: 0)
  }
  return s
}

func checkSizeOfStack(_ stack: [Int], _ size: Int) -> Bool {
  return stack.count == size
}

func evenCardCount(_ stack: [Int]) -> Int {
  var count = 0
  for card in stack {
    if card.isMultiple(of: 2) {
      count += 1
    }
  }
  return count
}
