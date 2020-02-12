#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int reverse(long int x) {
        if (x >= pow(2, 31)) return 0;
        int tf = 1;
        long int result=0;
        tf = x < 0 ? -1 : 1;
        long int curx = x*tf;
        long int stage = 1;
        stack<long int> xary;
        int curstage = curx % 10;
        curx/= 10;
        while(curx||curstage) {
            xary.push(curstage);
            curstage = curx % 10;
            curx = curx / 10;
        }
        while(!xary.empty()) {
            result += xary.top()*stage;
            xary.pop();
            stage *= 10;
        }
        return result * tf;
    }
};