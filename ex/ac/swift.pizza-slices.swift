import Foundation

func sliceSize(diameter: Double?, slices: Int?) -> Double? {
  guard diameter != nil, slices != nil else { return nil }
  guard diameter! >= 0, slices! > 0 else { return nil }
  return Double.pi * pow(diameter! / 2, 2) / Double(slices!)
}

func biggestSlice(
  diameterA: String, slicesA: String, diameterB: String, slicesB: String
) -> String {
  let A = sliceSize(diameter: Double(diameterA), slices: Int(slicesA))
  let B = sliceSize(diameter: Double(diameterB), slices: Int(slicesB))
  if A != nil && B != nil {
    if A! > B! {
      return "Slice A is bigger"
    } else if A! < B! {
      return "Slice B is bigger"
    } else {
      return "Neither slice is bigger"
    }
  } else if A != nil {
    return "Slice A is bigger"
  } else if B != nil {
    return "Slice B is bigger"
  } else {
    return "Neither slice is bigger"
  }
}
