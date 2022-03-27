import Foundation

func dailyRateFrom(hourlyRate: Int) -> Double {
  return Double(hourlyRate) * 8.0
}

func monthlyRateFrom(hourlyRate: Int, withDiscount discount: Double) -> Double {
  return round(
    22 * dailyRateFrom(hourlyRate: hourlyRate) * (1 - (discount / 100.0)))
}

func workdaysIn(budget: Double, hourlyRate: Int, withDiscount discount: Double)
  -> Double
{
  return floor(
    (budget / (1 - (discount / 100.0))) / dailyRateFrom(hourlyRate: hourlyRate))
}
