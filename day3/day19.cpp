#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        stack<ListNode> mys;
        ListNode* result = head;
        /*不能用栈，栈是复制，每个next指针指向的都是原品
        while (head!= nullptr) {
            mys.push(*head);
            head = head->next;
        }
        int cn = 1;
        while (!mys.empty()) {
            if (cn == n) {
                ListNode* n = mys.top().next;
                mys.pop();
                mys.top().next = n;
                break;
            }
            mys.pop();
        }*/
        int len = 0;
        while (head != nullptr) {
            len++;
            head = head->next;
        }
        len = len - n ;
        head = result;
        if (len == 0) {
            result = head->next;
            delete head;
            return result;
        }
        
        int r = 1;
        while (head!=nullptr&&head->next != nullptr) {
            if (r==len) {
                ListNode* deone = head->next;
                head->next = head->next->next;
                delete deone;
                break;
            }
            head = head->next;
            r++;
        }
        return result;
    }
};