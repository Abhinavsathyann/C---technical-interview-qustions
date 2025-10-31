#include <iostream>
#include <thread>
#include <vector>
#include <cmath>
using namespace std;

bool isPrime(int n) {
    if (n < 2) return false;
    for (int i = 2; i <= sqrt(n); i++)
        if (n % i == 0) return false;
    return true;
}

void findPrimes(int start, int end) {
    cout << "Primes between " << start << " and " << end << ": ";
    for (int i = start; i <= end; i++)
        if (isPrime(i)) cout << i << " ";
    cout << endl;
}

int main() {
    thread t1(findPrimes, 1, 50);
    thread t2(findPrimes, 51, 100);

    t1.join();
    t2.join();

    return 0;
}
