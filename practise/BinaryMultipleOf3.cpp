//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:	
		
	int isDivisible(string s){
	    //complete the function here
	    /*
	    int n = stoi(s), dec = 0, i = 0;
	    while(n > 0){
	        int r = n%10;
	        dec += r*pow(2, i++);
	        n /= 10;
	    }
	    return (dec%3 == 0);
	    */
	    int remSum = 0;
	    for(int i = 0; i < s.length(); i++){
	        if(s[i] == '1'){
	            if(i%2 == 0) remSum += 1;
	            else remSum += 2;
	        }
	    }
	    return (remSum%3 == 0) ? 1:0;

        /*
        for multiple of four 
        if 'n' bit number is given e.g. 1: 11100 => 28%4 == 0, and 2: 101011 => 43%4 != 1
        ***
        logic:  the last two bits needs to be checked, if any of them is one then it's modulo will be 
                either 2 or 1 therefore that number will not be divisible by 4
        ***
        // code:
        int n = s.length();
        if(s[n-1] == 1 || s[n-2] == 1) return 0; // not divisible
        else return 1;
        */
	}

};

//{ Driver Code Starts.
int main(){
    
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        Solution ob;
        cout << ob.isDivisible(s) << endl;
    }
return 0;
}


// } Driver Code Ends