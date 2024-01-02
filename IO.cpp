#include <bits/stdc++.h>

using namespace std;

void evenlyDivides(int N)
{
    int count = 0;
    int value = N;
    while (N != 0)
    {
        int rem = N % 10;
        if (rem != 0)
        {
            if (value % (rem) == 0)
            {
                count++;
            }
        }
        N /= 10;
    }
    cout << count << endl;
}

string reverseStr(string s)
{
    string res = "";
    for (int i = s.length(); i >= 0; i--)
    {
        res += s[i];
    }
    return res;
}

int main(int argc, char const *argv[])
{
    // int: 10 power 8
    // long: 10 power 12
    // long long: 10 power 18
    // cout << 'A' - '0';

    /*
    int num;
    cin >> num;
    evenlyDivides(num);
    */

    // int octalDecimal();

    long long X = 00000000000000000000000000000001;
    bitset<32> bitS1(X);
    string s = bitS1.to_string();
    reverse(s.begin(), s.end());
    bitset<32> set2(s);
    cout << set2.to_ullong();
    // string r = reverseStr(s);
    // cout << r << endl;
    // char *arr = new char[s.length() + 1];
    // strcpy(arr, r.c_str());
    // for (int i = 0; i < s.length(); i++)
    // {
    //     cout << i << "hii" << arr[i] << " ";
    // }

    return 0;
}
