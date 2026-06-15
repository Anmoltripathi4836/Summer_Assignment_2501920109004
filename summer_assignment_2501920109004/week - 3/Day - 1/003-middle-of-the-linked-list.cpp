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
    ListNode* middleNode(ListNode* head) {
        int count = 0;
        ListNode* temp = head;

        while(temp != nullptr){
            count++;
            temp = temp -> next;
        }

        int mid = count / 2;

        temp = head;

        while(mid--){
            temp = temp->next;
        }
        return temp;
    }
};