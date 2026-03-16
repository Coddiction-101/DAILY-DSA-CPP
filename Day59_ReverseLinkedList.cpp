/*
 * Problem Statement:
 * Given the head of a singly linked list, reverse the list, and 
 * return the reversed list.
 *
 * Example:
 * Input: 1 -> 2 -> 3 -> 4 -> 5
 * Output: 5 -> 4 -> 3 -> 2 -> 1
 */
#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;  
        ListNode* curr = head;     
        
        while(curr != nullptr) {
            ListNode* next = curr->next;
            curr->next = prev;            
            prev = curr;                
            curr = next;                  
        }
        
        return prev; 
    }
};

ListNode* createList(vector<int>& arr) {
    if(arr.empty()) return nullptr;
    
    ListNode* head = new ListNode(arr[0]);
    ListNode* curr = head;
    
    for(int i = 1; i < arr.size(); i++) {
        curr->next = new ListNode(arr[i]);
        curr = curr->next;
    }
    
    return head;
}

void printList(ListNode* head) {
    while(head != nullptr) {
        cout << head->val;
        if(head->next != nullptr) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main() {
     Solution solution;
    

    {
        vector<int> arr = {1, 2, 3, 4, 5};
        ListNode* head = createList(arr);
        cout << "Test 1: Input:  ";
        printList(head);
        
        head = solution.reverseList(head);
        cout << "        Output: ";
        printList(head);
        cout << "        Expected: 5 -> 4 -> 3 -> 2 -> 1" << endl << endl;
    }
    
    // Test Case 2
    {
        vector<int> arr = {1, 2};
        ListNode* head = createList(arr);
        cout << "Test 2: Input:  ";
        printList(head);
        
        head = solution.reverseList(head);
        cout << "        Output: ";
        printList(head);
        cout << "        Expected: 2 -> 1" << endl << endl;
    }
    
    // Test Case 3
    {
        vector<int> arr = {};
        ListNode* head = createList(arr);
        cout << "Test 3: Input:  (empty)" << endl;
        
        head = solution.reverseList(head);
        cout << "        Output: ";
        if(head == nullptr) cout << "(empty)";
        else printList(head);
        cout << endl << "        Expected: (empty)" << endl << endl;
    }
    
    return 0;
}
