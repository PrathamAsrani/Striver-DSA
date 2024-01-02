#include <bits/stdc++.h>

// https://www.programiz.com/cpp-programming/library-function/cstdio/sscanf

using namespace std;

int convertToSeconds(string &timeStamp);

int main(int argc, char const *argv[])
{
    string time = "08:01:13";
    cout << convertToSeconds(time) << "\n";
    return 0;
}

int convertToSeconds(string &timeStamp)
{
    int hrs, mins, secs;
    sscanf(timeStamp.c_str(), "%d:%d:%d", &hrs, &mins, &secs);
    return ((hrs * 3600) + (mins * 60) + secs);
}