import Foundation

func splitOnNewlines(_ poem: String) -> [String] {
  return poem.components(separatedBy: "\n")
}

func firstLetter(_ line: String) -> Character {
  if let i = line.first { return i } else { return Character("_") }
}

func capitalize(_ phrase: String) -> String { return phrase.capitalized }

func trimFromEnd(_ line: String) -> String {
  return line.trimmingCharacters(in: .whitespaces)
}

func lastLetter(_ line: String) -> Character {
  if let i = line.last { return i } else { return Character("_") }
}

func backDoorPassword(_ phrase: String) -> String {
  return capitalize(trimFromEnd(phrase)) + ", please"
}

func ithLetter(_ line: String, i: Int) -> Character {
  guard i >= 0, i < line.count else { return Character(" ") }
  return line[line.index(line.startIndex, offsetBy: i)]
}

func secretRoomPassword(_ phrase: String) -> String {
  return phrase.uppercased() + "!"
}
