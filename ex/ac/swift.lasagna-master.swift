func remainingMinutesInOven(
  elapsedMinutes: Int, expectedMinutesInOven: Int = 40
) -> Int { return expectedMinutesInOven - elapsedMinutes }

func preparationTimeInMinutes(layers: String...) -> Int {
  return layers.count * 2
}

func quantities(layers: String...) -> (noodles: Int, sauce: Double) {
  var noodles = 0
  var sauce: Double = 0
  for layer in layers {
    if layer == "sauce" {
      sauce += 0.2
    } else if layer == "noodles" {
      noodles += 3
    }
  }
  return (noodles, sauce)
}

func toOz(_ l: inout (noodles: Int, sauce: Double)) { l.sauce *= 33.814 }

func redWine(layers: String...) -> Bool {
  var red = 0
  var white = 0
  for layer in layers {
    if layer == "mozzarella" || layer == "ricotta" || layer == "béchamel" {
      white += 1
    } else if layer == "meat" || layer == "sauce" {
      red += 1
    }
  }
  return red >= white
}
