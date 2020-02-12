#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int romanToInt(string s) {
        int result=0;
        int i = 0;
        while (s[i++] == 'M')result += 1000;
        i--;
        if (s.substr(i, 2) == "CM"){
            result += 900;
            i += 2;
        }
        else if (s.substr(i, 2) == "CD") {
            result += 400;
            i += 2;
        }
        else if (s[i] == 'D') {
            i++;
            result += 500;
        }
        while (s[i++] == 'C') result += 100;
        i--;
        if (s.substr(i, 2) == "XC") {
            result += 90;
            i += 2;
        }
        else if (s.substr(i, 2) == "XL") {
            result += 40;
            i += 2;
        }
        else if (s[i] == 'L') {
            i++;
            result += 50;
        }
        while (s[i++] == 'X') result += 10;
        i--;
        if (s.substr(i, 2) == "IX") {
            result += 9;
            i += 2;
        }
        else if (s.substr(i, 2) == "IV") {
            result += 4;
            i += 2;
        }
        else if (s[i] == 'V') {
            i++;
            result += 5;
        }
        while (s[i++] == 'I')result += 1;

        return result;
    }
};