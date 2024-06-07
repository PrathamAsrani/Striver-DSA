#include <bits/stdc++.h>
using namespace std;

vector<bool> primes;

void SieveOfEratosthenes(int n);

int main(int argc, char const *argv[])
{
    // The sieve of Eratosthenes is one of the most efficient ways to find all primes smaller than n when n is smaller than 10 million or so.
    int n = 100;
    primes.resize(n+1, true);
    SieveOfEratosthenes(n);
    cout << "All prime numbers are: \n";
    for(int i = 2; i <= n; i++){
        if(primes[i])
            cout << i << " ";
    }
    cout << "\n";
    return 0;
}

void SieveOfEratosthenes(int n){
    for(int p = 2; p <= sqrt(n); p++){
        if(primes[p] == true){
            for(int i = p*p; i <= n; i += p){
                primes[i] = false;
            }
        }
    }
}