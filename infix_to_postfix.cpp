#include <bits/stdc++.h>
using namespace std;

string infix_to_postfix(string exp);
int precedence(char c);


int main(){
    string exp = "a+b*(c^d-e)^(f+g*h)-i";
    string ans = infix_to_postfix(exp);
    cout << ans << "\n";
}

string infix_to_postfix(string exp){
    string res = "";
    stack<char> st;
    for(char c:exp){
        if(isalnum(c))
            res += c;
        else if(c == '(')
            st.push(c);
            
    }
}

int precedence(char c){
    switch (c)
    {
    case '+':
        return 1;
        break;
    case '-':
        return 1;
        break;
    case '*':
        return 2;
        break;
    case '/':
        return 2;
        break;
    case '^':
        return 3;
        break;
    
    default:
        return -1;
        break;
    }
}