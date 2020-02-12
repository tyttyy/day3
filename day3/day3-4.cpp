#include<bits/stdc++.h>
using namespace std;
//day3
//class Solution {
//public:
//    int lengthOfLongestSubstring(string s) {
//        int sizeS = s.size();
//        if (sizeS == 0)return 0;
//        int maxlength(1), reclength (1),posiS (0);
//        for (int posiE = posiS + reclength; posiE < sizeS; posiE++) {
//            char charE = s[posiE];
//            for (int curpos = posiS; curpos < posiE; curpos++) {
//                if (charE == s[curpos]) {
//                    reclength = posiE - curpos;
//                    posiS = curpos + 1;
//                    break;
//                }
//            }
//            maxlength = max(posiE - posiS + 1, maxlength);
//        }
//        return maxlength;
//    }
//};


//day4
//class Solution {
//public:
//    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
//        int p1(0), p2(0);
//        double midNum = 0.0;
//        int sumSize = nums1.size() + nums2.size();
//        int curp = 0;
//        int curnum[2] = { 0 , 0 };
//        if (sumSize < 2) {
//            if (p1 < nums1.size()) {
//                curnum[1] = nums1[0];
//            }
//            else {
//                curnum[1] = nums2[0];
//            }
//        }
//        while (curp<sumSize/2) {
//            if (p1 < nums1.size() && p2 < nums2.size()) {
//                curnum[0] = nums1[p1] <= nums2[p2] ? nums1[p1] : nums2[p2];
//                nums1[p1] <= nums2[p2] ? p1++ : p2++;
//                if (p1 < nums1.size() && p2 < nums2.size()) {
//                    curnum[1] = nums1[p1] <= nums2[p2] ? nums1[p1] : nums2[p2];
//                }
//                else if (p1 < nums1.size()) {
//                    curnum[1] = nums1[p1];
//                }
//                else {
//                    curnum[1] = nums2[p2];
//                }
//                
//            }
//            else if (p1 < nums1.size()) {
//                curnum[0] = nums1[p1];
//                p1++;
//                curnum[1] = nums1[p1];
//            }
//            else {
//                curnum[0] = nums2[p2];
//                p2++;
//                curnum[1] = nums2[p2];
//            }
//            curp++;
//        }
//        if (sumSize % 2)midNum = curnum[1];
//        else midNum = (curnum[0] + curnum[1]) / 2.0;
//        return midNum;
//    }
//};
//day3
//class Solution
//{
//public:
//    int lengthOfLongestSubstring(string s)
//    {
//        //s[start,end) 前面包含 后面不包含
//        int start(0), end(0), length(0), result(0);
//        int sSize = int(s.size());
//        unordered_map<char, int> hash;
//        while (end < sSize)
//        {
//            char tmpChar = s[end];
//            //仅当s[start,end) 中存在s[end]时更新start
//            if (hash.find(tmpChar) != hash.end() && hash[tmpChar] >= start)
//            {
//                start = hash[tmpChar] + 1;
//                length = end - start;
//            }
//            hash[tmpChar] = end;
//
//            end++;
//            length++;
//            result = max(result, length);
//        }
//        return result;
//    }
//};

//int main() {
//	list<int> l1;
//	l1.push_front(4);
//	l1.push_front(5);
//	l1.push_front(6);
//	l1.push_front(7);
//	l1.push_front(8);
//	for (list<int>::const_iterator iter = l1.cbegin(); iter != l1.cend(); iter++) {
//		cout << *iter << endl;
//	}
//
//
//
//}