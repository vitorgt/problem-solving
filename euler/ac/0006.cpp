#define ll long long

ll sumSquareDifference(int n = 100) {
    ll squareOfSum = n * n * (n + 1) * (n + 1) / 4;
    ll sumOfSquares = (2 * n + 1) * (n + 1) * n / 6;
    return squareOfSum - sumOfSquares;
}
