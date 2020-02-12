#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isPalindrome(int x) {
        
        if (x < 0 || x % 10 == 0 && x != 0)return 0;

        int num = 0;
        while (x > num) {
            num = 10 * num + x % 10;
            x /= 10;
        }
        return x == num||x==num/10;
    }
};