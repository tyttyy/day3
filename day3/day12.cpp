#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string intToRoman(int num) {
        int I;//1             
        int X;//10             
        int C;//100            
        int M;//1000
        M = num / 1000; //ǧλ
        num %= 1000;    //
        C = num / 100;  //��λ
        num %= 100;     //
        X = num / 10;   //ʮλ
        num %= 10;      //
        I = num;        //��λ
        string result;
        while (M-- > 0) result.push_back('M');
        if (C == 9) {
            result+="CM";
        }
        else if (C == 4) {
            result+="CD";
        }
        else {
            if (C >= 5) result.push_back('D');
            C %= 5;
            while (C-- > 0) result.push_back('C');
        }
        if (X == 9) {
            result+="XC";
        }
        else if (X == 4) {
            result+="XL";
        }
        else {
            if (X >= 5) result.push_back('L');
            X %= 5;
            while (X-- > 0) result.push_back('X');
        }
        if (I == 9) {
            result+="IX";
        }
        else if (I == 4) {
            result+="IV";
        }
        else {
            if (I >= 5) result.push_back('V');
            I %= 5;
            while (I-- > 0) result.push_back('I');
        }

        return result;

            
    }
};