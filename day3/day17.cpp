#include<bits/stdc++.h>
using namespace std;
class Solution {
private:
    vector<vector<char>> gra;
    vector<string> result;
    int len;
    void dfs(int i,int j, string res) {
        if (i < len) {
            if (j < gra[i].size()) {
                res.push_back(gra[i][j]);
                dfs(i + 1, 0, res);
                res.pop_back();
                dfs(i, j + 1, res);
            }
        }
        else result.push_back(res);
        
    }
public:
    vector<string> letterCombinations(string digits) {
        len = digits.size();
        if (len == 0)return{};
        for (const char &dig:digits) {
            switch (dig)
            {
            case '2':
                gra.push_back({ 'a','b','c' });
                break;
            case '3':
                gra.push_back({ 'd','e','f' });
                break;
            case '4':
                gra.push_back({ 'g','h','i' });
                break;
            case '5':
                gra.push_back({ 'j','k','l' });
                break;
            case '6':
                gra.push_back({ 'm','n','o' });
                break;
            case '7':
                gra.push_back({ 'p','q','r','s' });
                break;
            case '8':
                gra.push_back({ 't','u','v' });
                break;
            case '9':
                gra.push_back({ 'w','x','y','z' });
                break;
            default:
                break;
            }
        }
        string res;
        dfs(0, 0, res);
        return result;
    }
};