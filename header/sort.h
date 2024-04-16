//
// Created by kemi on 2024/4/15.
//

#pragma once

using namespace std;

class ListNode {
public:
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* sortList(ListNode* head){
    if (head == nullptr || head->next == nullptr) return head;
    if (head->next->next == nullptr) {
        if (head->val > head->next->val) {
            int temp = head->val;
            head->val = head->next->val;
            head->next->val = temp;
        }
        return head;
    }
    ListNode* slow = head;
    ListNode* fast = head;
    while (fast != nullptr && fast->next != nullptr && fast->next->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }
    ListNode* right = slow->next;
    slow->next = nullptr;
    ListNode* left = sortList(head);
    right = sortList(right);
    ListNode* dummy = new ListNode(0);
    ListNode* cur = dummy;
    for (;left != nullptr && right != nullptr;) {
        if (left->val < right->val) {
            cur->next = left;
            left = left->next;
        } else {
            cur->next = right;
            right = right->next;
        }
        cur = cur->next;
    }
    if (left != nullptr) {
        cur->next = left;
    }
    if (right != nullptr) {
        cur->next = right;
    }
    return dummy->next;
}

void printList(ListNode* head) {
    for (ListNode* cur = head; cur != nullptr; cur = cur->next) {
        cout << cur->val << " ";
    }
    cout << endl;
}

ListNode* reverse(ListNode* head) {
    ListNode* pre = nullptr;
    ListNode* cur = head;
    for (;cur != nullptr;) {
        ListNode* temp = cur->next;
        cur->next = pre;
        pre = cur;
        cur = temp;
    }
    return pre;
}