//
// Created by kemi on 2024/5/9.
//

#ifndef CODEWAR_LRU_H
#define CODEWAR_LRU_H

#endif //CODEWAR_LRU_H

#include <iostream>
#include <unordered_map>
#include <map>
#include <list>
#include <set>

class DoubleLinkedList {
public:
    int key;
    int val;
    DoubleLinkedList* prev;
    DoubleLinkedList* next;
    DoubleLinkedList(int key, int val) : val(val),key(key), prev(nullptr), next(nullptr) {}
    DoubleLinkedList() : key(0), val(-1), prev(nullptr), next(nullptr) {}
    DoubleLinkedList(int val, DoubleLinkedList* prev, DoubleLinkedList* next) : val(val), prev(prev), next(next) {}
    int getVal() {
        return val;
    }
};

class LRUCache {
private:
    int maxCapacity;
    DoubleLinkedList* head;
    DoubleLinkedList* tail;
    std::unordered_map<int, DoubleLinkedList*> cache;
public:
    LRUCache(int capacity) {
        maxCapacity = capacity;
        head = new DoubleLinkedList();
        tail = new DoubleLinkedList();
        head->next = tail;
        tail->prev = head;
        cache = std::unordered_map<int, DoubleLinkedList*>();
    }

    int get(int key) {
        if (cache.find(key) == cache.end()) {
            return -1;
        }
        DoubleLinkedList* node = cache[key];
        int val = node->getVal();
        // move the node to the head
        move_to_head(node);

        return val;
    }

    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            cache[key]->val = value;
            move_to_head(cache[key]);
            return;
        }
        DoubleLinkedList* node = new DoubleLinkedList(key, value);
        node->next = head->next;
        node->next->prev = node;

        node->prev = head;
        head->next = node;
        cache[key] = node;
        if (cache.size() > maxCapacity) {
            DoubleLinkedList* del = tail->prev;
            del->prev->next = tail;
            tail->prev = del->prev;
            cache.erase(del->key);
        }
    }

    void move_to_head(DoubleLinkedList* node){
        node->prev->next = node->next;
        node->next->prev = node->prev;

        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */


class LFUCache {
private:
    int maxCapacity;
    int minFreq;
    std::unordered_map<int, std::pair<int, int>> cache;
    std::unordered_map<int, std::list<int>> freqMap;
public:
    LFUCache(int capacity) {
        maxCapacity = capacity;
        minFreq = 0;
    }

    int get(int key) {
        if (cache.find(key) == cache.end()) {
            return -1;
        }
        int val = cache[key].first;
        int freq = cache[key].second;
        freqMap[freq].erase(key);
        if (freqMap[freq].empty()) {
            freqMap.erase(freq);
            if (freq == minFreq) {
                minFreq++;
            }
        }
        freqMap[freq + 1].insert(key);
        cache[key].second++;
        return val;
    }

    void put(int key, int value) {
        if (maxCapacity <= 0) return;
        if (cache.find(key) != cache.end()) {
            cache[key].first = value;
            get(key);
            return;
        }
        if (cache.size() >= maxCapacity) {
            int delKey = *freqMap[minFreq].begin();
            freqMap[minFreq].erase(delKey);
            if (freqMap[minFreq].empty()) {
                freqMap.erase(minFreq);
            }
            cache.erase(delKey);
        }
        cache[key] = {value, 1};
        freqMap[1].insert(key);
        minFreq = 1;
    }
};


class LFUCache2 {
private:
    int maxCapacity;
    std::map<int, int> cache;
    std::set<int> freq;
public:
    int get(int key) {
        if (cache.find(key) == cache.end()) {
            return -1;
        }
        int val = cache[key];
        freq.erase(key);
        freq.insert(key);
        return val;
    }

    void put(int key) {
        if (cache.find(key) != cache.end()) {
            get(key);
            return;
        }
        if (cache.size() >= maxCapacity) {
            int delKey = *freq.begin();
            freq.erase(delKey);
            cache.erase(delKey);
        }
        cache[key] = 1;
        freq.insert(key);
    }

};