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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        list<int> ans;

        ListNode* i = list1;
        ListNode* j = list2;

        while(i != nullptr && j != nullptr){
            if(i->val <= j->val){
                ans.push_back(i->val);
                i = i->next;
            }
            else{
                ans.push_back(j->val);
                j = j->next;
            }
        }

        while(i != nullptr){
            ans.push_back(i->val);
            i = i->next;
        }

        while(j != nullptr){
            ans.push_back(j->val);
            j = j->next;
        }

        ListNode* dummy = new ListNode(-1);
        ListNode* tail = dummy;

        for(int x : ans){
            tail->next = new ListNode(x);
            tail = tail->next;
        }

        return dummy->next;
    }
};