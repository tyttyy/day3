#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int longestValidParentheses(string s) {
        int len = s.size();
        stack<int> msk;
        int cur = 0;
        int result = 0;
        msk.push(-1);
        for (int i = 0; i < len; i++) {
            if (s[i] == '(') {
                msk.push(i);
            }
            else {
                msk.pop();

                if (msk.empty())msk.push(i);
                else {
                    cur = i - msk.top();
                    result = cur > result ? cur : result;
                }
            }

        }
        return result;
    }
};