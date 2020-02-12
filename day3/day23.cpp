#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
private:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr && l2 == nullptr)return nullptr;
        else if (l1 == nullptr)return l2;
        else if (l2 == nullptr)return l1;
        else {
            ListNode* hresult = new ListNode(-1);
            ListNode* result = hresult;
            if (l1->val < l2->val) {
                hresult->val = l1->val;
                l1 = l1->next;
            }
            else
            {
                hresult->val = l2->val;
                l2 = l2->next;
            }
            while (l1 != nullptr || l2 != nullptr) {
                if (l1 == nullptr) {
                    hresult->next = new ListNode(l2->val);
                    l2 = l2->next;
                    hresult = hresult->next;
                    continue;
                }
                else if (l2 == nullptr) {
                    hresult->next = new ListNode(l1->val);
                    l1 = l1->next;
                    hresult = hresult->next;
                    continue;
                }
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

            return result;
        }

    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<ListNode*> nlists;
        int len = lists.size();
        if (len == 0)return nullptr;
        if (len == 1) return lists[0];
        int nlen = len / 2 ;
        for (int i = 0; i < nlen; i++) {
            nlists.push_back(mergeTwoLists(lists[2*i],lists[2*i+1]));
        }
        if (len % 2 == 1) nlists.push_back(lists[len - 1]);
        return mergeKLists(nlists);
    }
};