#include <bits/stdc++.h>
using namespace std;

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
