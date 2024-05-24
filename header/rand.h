//
// Created by kemi on 2024/5/6.
//

#pragma once

#include <random>
#include <iostream>

using namespace std;


void randn() {
    int n = 10; // 假设我们想生成一个 [0, 10) 范围内的随机数

    // 创建随机数引擎，使用系统时钟为其种子
    std::random_device rd;
    std::mt19937 gen(rd());

    // 创建分布，在 [0, n) 之间均匀分布
    std::uniform_int_distribution<> dis(0, n - 1);

    // 生成随机数
    int random_number = dis(gen);
    int random_number2 = dis(gen);
    std::cout << "Random number: " << random_number << "," << random_number2 << std::endl;
}

//class ListNode {
//    int val;
//    ListNode* next;
//    ListNode(int x) : val(x), next(nullptr) {}
//    ListNode(int x, ListNode* next) : val(x), next(next) {}
//};

int find_one(int n, int k) {
    ListNode *head = new ListNode(0);
    ListNode *current = head;
    for (int i = 1; i <= n ; i ++ ){
        current->next = new ListNode(i);
        current = current->next;
    }
    current->next = head->next;
    ListNode *counting = head->next;
    for (int i = 1; current != counting; i ++) {
        if (i == k) {
            i = 0;
            current->next = counting->next;
        } else {
            counting = counting->next;
            current = current->next;
        }
    }
    return counting->val;
}

