#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr && l2 == nullptr)return nullptr;
        else if (l1 == nullptr)return l2;
        else if (l2 == nullptr)return l1;
        else {
            ListNode* hresult = new ListNode(-1);
            if (l1->val < l2->val) {
                hresult->val = l1->val;
                l1 = l1->next;
            }
            else
            {
                hresult->val = l2->val;
                l2 = l2->next;
            }
            while (l1 != nullptr && l2 != nullptr) {
                if (l1->val < l2->val) {
                    hresult->next = new ListNode(l1->val);
                    l1 = l1->next;
                }
                else
                {
                    hresult->next = new ListNode(l2->val);
                    l2 = l2->next;
                }
                hresult = hresult->next;
            }
            return hresult;
        }
        
    }
};