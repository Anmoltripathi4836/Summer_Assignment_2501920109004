#include<iostream>
#include<list>
using namespace std;

class ListNode {
public:
    int val;
    ListNode* next;

    ListNode(int x) {
        val = x;
        next = nullptr;
    }
};

class Solution {
public:
    int getSize(ListNode* head) {
        ListNode* temp = head;
        int size = 0;

        while(temp != nullptr) {
            temp = temp->next;
            size++;
        }

        return size;
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int size = getSize(head);

        if(size == n) {
            ListNode* del = head;
            head = head->next;
            delete del;
            return head;
        }

        ListNode* prev = head;

        for(int i = 1; i < (size - n); i++) {
            prev = prev->next;
        }

        ListNode* del = prev->next;
        prev->next = prev->next->next;

        delete del;

        return head;
    }
};