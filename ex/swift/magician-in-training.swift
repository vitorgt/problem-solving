func getCard(at index: Int, from stack: [Int]) -> Int {
  return stack[index]
}

func setCard(at index: Int, in stack: [Int], to newCard: Int) -> [Int] {
  var stack = stack
  if index < stack.count && index >= 0 {
    stack[index] = newCard
  }
  return stack
}

func insert(_ newCard: Int, atTopOf stack: [Int]) -> [Int] {
  var stack = stack
  stack.append(newCard)
  return stack
}

func removeCard(at index: Int, from stack: [Int]) -> [Int] {
  var stack = stack
  if index < stack.count && index >= 0 {
    stack.remove(at: index)
  }
  return stack
}

func removeTopCard(_ stack: [Int]) -> [Int] {
  var stack = stack
  if stack.count >= 0 {
    stack.removeLast(1)
  }
  return stack
}

func insert(_ newCard: Int, atBottomOf stack: [Int]) -> [Int] {
  var stack = stack
  stack.insert(newCard, at: 0)
  return stack
}

func removeBottomCard(_ stack: [Int]) -> [Int] {
  var stack = stack
  if stack.count >= 0 {
    stack.remove(at: 0)
  }
  return stack
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
