#include<bits/stdc++.h>
using namespace std;
class Solution {
private:
    bool jpair(char a, char b) {
        if (a == '[' && b == ']')return true;
        else if (a == '{' && b == '}') return true;
        else if (a == '(' && b == ')') return true;
        else return false;
    }
public:
    bool isValid(string s) {
        int len = s.size();
        stack<char> myc;
        int i = 0;
        while (!myc.empty() || i < len) {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
                myc.push(s[i]);
            }
            else {
                if (!myc.empty()) {
                    if (jpair(myc.top(), s[i])) myc.pop();
                    else return false;
                }
                else return false;

            }
            i++;
        }
        if (myc.empty())
            return true;
        else return false;
    }
};