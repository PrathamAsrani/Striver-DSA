
#include <bits/stdc++.h>
using namespace std;

void sieve(int n, vector<int> &prime)
{
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (prime[i] == i)
        {
            for (int j = i; j < prime.size(); j += i)
            {
                if(prime[j] == j) 
                    prime[j] = i;
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    vector<int> prime(100, 0);

    for (int i = 0; i < 100; prime[i] = i, i++)
        ;

    sieve(100, prime);

    for(int i = 0; i < 100; i++){
        cout << i << " smallest prime factor of i is: " << prime[i] << "\n";
    }
    return 0;
}
