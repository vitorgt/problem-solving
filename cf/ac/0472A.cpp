#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int INF = 0x3f3f3f3f;

class PrimeSieve {
  private:
    vector<bool> sieve;
    vector<int> primes;

  public:
    PrimeSieve(int max = INT_MAX) {
        if (max <= 0)
            throw invalid_argument("Max must be greater than 0.");
        if (max < INT_MAX)
            max++;

        this->sieve = vector<bool>(max, true);
        this->sieve[0] = false;
        this->primes.push_back(1);
        this->primes.push_back(2);

        long long i = 0, j = 0;

        for (i = 4; i < max; i += 2)
            this->sieve[i] = false;

        for (i = 3; i * i < max; i += 2)
            if (this->sieve[i]) {
                this->primes.push_back(i);
                for (j = i * i; j < max; j += i)
                    this->sieve[j] = false;
            }

        for (; i < max; i += 2)
            if (this->sieve[i])
                this->primes.push_back(i);
    }

    bool isPrime(int n) { return this->sieve[n]; }
    vector<int> getPrimes() { return this->primes; }
};

int main(int argc, const char **argv) {
    std::ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    PrimeSieve *ps = new PrimeSieve(1000000);
    int n = 0;
    cin >> n;

    for (int i = 4; i < n; i++)
        if (!ps->isPrime(i) && !ps->isPrime(n - i)) {
            cout << i << " " << n - i << endl;
            return 0;
        }

    return 0;
}
