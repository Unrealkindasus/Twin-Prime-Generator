#include <iostream>
#include <vector>

bool isPrime(int num) {
    if (num <= 1) {
        return false;
    }

    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return false;
        }
    }

    return true;
}

std::vector<int> generatePrimes(int limit) {
    std::vector<int> primes;

    for (int i = 2; i <= limit; i++) {
        if (isPrime(i)) {
            primes.push_back(i);
        }
    }

    return primes;
}

std::vector<std::pair<int, int>> generateTwinPrimes(const std::vector<int>& primes) {
    std::vector<std::pair<int, int>> twinPrimes;

    for (int i = 0; i < primes.size() - 1; i++) {
        if (primes[i + 1] - primes[i] == 2) {
            twinPrimes.push_back(std::make_pair(primes[i], primes[i + 1]));
        }
    }

    return twinPrimes;
}

void visualizeTwinPrimes(const std::vector<std::pair<int, int>>& twinPrimes) {
    std::cout << "Twin Primes:\n";

    for (const auto& twinPrime : twinPrimes) {
        std::cout << twinPrime.first << " and " << twinPrime.second << "\n";
    }
}

int main() {
    int limit;
    std::cout << "Enter the limit to generate twin primes: ";
    std::cin >> limit;

    std::vector<int> primes = generatePrimes(limit);
    std::vector<std::pair<int, int>> twinPrimes = generateTwinPrimes(primes);

    visualizeTwinPrimes(twinPrimes);

    return 0;
}
