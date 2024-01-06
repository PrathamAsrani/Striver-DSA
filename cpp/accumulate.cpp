#include <bits/stdc++.h>
using namespace std;

string patterns(string input, int num);

int main() {
    // Vector definition.
    vector<int> v1{10, 20, 30, 40};

    // Calling the accumulate() function.
    int productValue = accumulate(v1.begin(), v1.end(), 1, multiplies < int > ());

    // Printing the result.
    cout << "The value of the product is " << productValue << endl;

    // Calling the accumulate function to calculate the sum.
    int sumValue = accumulate(v1.begin(), v1.end(), 0);

    // printing the sum.
    cout << "The sum of the series is " << sumValue << endl;


    // Defining the vector.
    vector<int> v2{10, 20, 30, 40, 50, 60, 70, 80};

    // Calling the accumulate() function.
    string patternValue = accumulate(v2.begin(), v2.end(), string(), patterns);

    // Printing the result.
    cout << "The pattern returned is : " << patternValue << endl;
    return 0;
}

string patterns(string input, int num) {
    if (num > 30) {
        input += "c";
    } else {
        input += "+";
    }
    return input;
}
