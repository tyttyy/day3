#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isMatch(string s, string p) {
        int sp = 0, pp = 0,sl=s.size(),pl=p.size(),sstar=-1,pstar=-1;
        while (sp < sl) {
            if (pp < pl && s[sp] == p[pp] || p[pp] == '?') {
                sp++;
                pp++;
            }
            else if (pp < pl && p[pp] == '*') {
                sstar = sp;
                pstar = ++pp;
            }
            else if (sstar >= 0) {
                sp = ++sstar;
                pp = pstar;
            }
            else return false;
        }
        while (pp < pl && p[pp] == '*') pp++;

        return pp == pl;
        
    }
};