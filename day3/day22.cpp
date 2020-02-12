#include<bits/stdc++.h>
using namespace std;
class Solution {
private:
    vector<string> result;
    void dfs(string s,int n,int l,int r) {
        if (s.size() == 2 * n) {
            result.push_back(s);
        }
        else {
            if (l == r) {
                s.push_back('(');
                l++;
                dfs(s, n, l, r);
            }
            else if(l<n) {
                string cs = s;
                cs.push_back('(');
                l++;
                dfs(cs, n, l, r);
                l--;
                r++;
                s.push_back(')');
                dfs(s, n, l, r);
            }
            else {
                r++;
                s.push_back(')');
                dfs(s, n, l, r);
            }
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        result.clear();
        
        dfs("",n,0,0);

        return result;
    }
}; 