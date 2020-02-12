#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* node = head;
        ListNode* result = head;
        ListNode* cur = nullptr;
        for (int i = 0; i < k; i++) {
            if (head == nullptr)return result;
            if (head != nullptr && i == k - 1) result = head;
            head = head->next;
        }
        //此时head指向下一个k的段首
        for (int i = 0; i < k; i++) {
            cur = node->next;
            node->next = head;
            head = node;
            node = cur;
        }
        for (int i = 0; i < k; i++) {
            head = head->next;
        }
        head->next = reverseKGroup(node, k);
    }
};