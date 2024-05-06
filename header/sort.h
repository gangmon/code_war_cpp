//
// Created by kemi on 2024/4/15.
//

#pragma once
#include <random>
#include <vector>
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

vector<int> q_sort(vector<int> nums) {
    if (nums.size() <= 1) return nums;
    int pivot = nums[nums.size() / 2];
    vector<int> left;
    vector<int> right;
    for (size_t i = 0; i < nums.size(); i++) {
        if (i == nums.size() / 2) continue;
        if (nums[i] <= pivot) {
            left.push_back(nums[i]);
        } else {
            right.push_back(nums[i]);
        }
    }
    left = q_sort(left);
    right = q_sort(right);
    left.push_back(pivot);
    left.insert(left.end(), right.begin(), right.end());
    return left;
}

vector<int> qk_sort(vector<int> nums) {
    if (nums.size() <= 1) return nums;
    if (nums.size() == 2) {
        if (nums[0] > nums[1]) {
            int temp = nums[0];
            nums[0] = nums[1];
            nums[1] = temp;
        }
        return nums;
    }
    int pivot = nums[0];
    vector<int> left;
    vector<int> right;
    for (size_t i = 1; i < nums.size(); i ++){
        if (nums[i] < pivot) {
            left.push_back(nums[i]);
        } else {
            right.push_back(nums[i]);
        }
    }
    left = qk_sort(left);
    right = qk_sort(right);
    left.push_back(pivot);
    left.insert(left.end(), right.begin(), right.end());
    return left;
}

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        if (nums.size() <= 1) return nums;
        if (nums.size() == 2) {
            if (nums[0] > nums[1]) {
                int temp = nums[0];
                nums[0] = nums[1];
                nums[1] = temp;
            }
            return nums;
        }

        int pivot = nums[rand()%nums.size()];

        vector<int> left;
        vector<int> right;
        vector<int> mid;

        for (size_t i = 0; i < nums.size(); i ++){
            if (nums[i] == pivot) {
                mid.push_back(nums[i]);
                continue;
            }
            if (nums[i] < pivot) {
                left.push_back(nums[i]);
            } else {
                right.push_back(nums[i]);
            }
        }
        left = sortArray(left);
        right = sortArray(right);
        left.insert(left.end(), mid.begin(), mid.end());
        left.insert(left.end(), right.begin(), right.end());
        return left;
    }
};

bool binary_search(int target, vector<int> nums) {
    if (nums.size() == 0) return false;
    if (nums.size() == 1) return nums[0] == target;
    int left = 0;
    int right = nums.size() - 1;
    int mid = nums.size()/2 - 1;
    for (;left <= right;) {
        if (nums[mid] == target) return true;
        if (nums[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
        mid = (left + right) / 2;
    }
}