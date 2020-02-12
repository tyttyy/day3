#include<bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* result = nullptr;
        if (head == nullptr) return{};
        if (head->next != nullptr) result = head->next;
        else result = head;
        ListNode* pre = nullptr;
        while (head != nullptr) {
            if (head->next != nullptr) {
                ListNode* tmp = head->next;
                if (pre != nullptr) pre->next = tmp;
                head->next = tmp->next;
                tmp->next = head;
                tmp = nullptr;
                pre = head;
                head = head->next;

            }
            else break;

        }
        return result;
    }
};