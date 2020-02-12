#include<bits/stdc++.h>
using namespace std;
class Solution {
    string alstr(string pre, int n, int i);
public:
    string countAndSay(int n) {
        return alstr("1", n, 2);
    }
};

string Solution::alstr(string pre, int n, int i)
{
    if (n == 1)return pre;
    string cur;
    char prec = '.';
    int count = 0;
    for (char curc : pre) {
        if (prec == '.' || prec == curc) {
            count++;
        }
        else {
            cur += to_string(count) + prec;
            count = 1;
        }
        prec = curc;
    }
    cur += to_string(count) + prec;
    if (i < n)
        return alstr(cur, n, i + 1);
    else return cur;
}