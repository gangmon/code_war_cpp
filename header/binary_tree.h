//
// Created by kemi on 2024/4/16.
//

#ifndef CODEWAR_BINARY_TREE_H
#define CODEWAR_BINARY_TREE_H

#endif //CODEWAR_BINARY_TREE_H


#include <iostream>
#include <vector>

using namespace std;



struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {};
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {};
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {};
};

/*
     *   1
     * 2   3
    4  5  6  7
*/
// passed
TreeNode* invertTree(TreeNode* root) {
    if (root == nullptr) return nullptr;
    TreeNode* left = invertTree(root->left);
    TreeNode* right = invertTree(root->right);
    root->left = right;
    root->right = left;
    return root;
}

void level_by_recursion(TreeNode* head, int level, vector<vector<int>> &res);


//
void traverse(TreeNode* root) {
    if (root == nullptr) return;
    traverse(root->left);
    std::cout << root->val << " ";
    traverse(root->right);
}

// level_traverse
vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> res;
    if (root == nullptr) return res;
    vector<TreeNode*> queue;
    queue.push_back(root);
    while (!queue.empty()) {
        vector<int> level;
        int size = queue.size();
        for (int i = 0; i < size; i++) {
            TreeNode* node = queue.front();
            queue.erase(queue.begin());
            level.push_back(node->val);
            if (node->left != nullptr) queue.push_back(node->left);
            if (node->right != nullptr) queue.push_back(node->right);
        }
        res.push_back(level);
    }
    return res;
}
// level_traverse
// passed
vector<vector<int>> level_order(TreeNode* root) {
    vector<vector<int>> res;
    if (root == nullptr) return res;
    vector<TreeNode*> queue;
    vector<TreeNode*> pre_queue;

    queue.push_back(root);
    while (pre_queue.size() < queue.size()) {

        vector<int> level;
        size_t q_size = queue.size();
        for (size_t i = pre_queue.size(); i < q_size; i++) {
            level.push_back(queue[i]->val);
            pre_queue.push_back(queue[i]);
            if (queue[i]->left != nullptr) queue.push_back(queue[i]->left);
            if (queue[i]->right != nullptr) queue.push_back(queue[i]->right);
        }
        res.push_back(level);
    }
    return res;
}


vector<vector<int>> lever_order_by_recursion(TreeNode* head) {
    vector<vector<int>> res;
    if (head == nullptr) return res;
    level_by_recursion(head, 1, res);

    return res;
}



void level_by_recursion(TreeNode* head, int level, vector<vector<int>> &res) {

    if (head == nullptr) return ;
    if (level == res.size()) {
        res[level-1].push_back(head->val);
    } else {
        vector<int> level;
        level.push_back(head->val);
        res.push_back(level);
    }
    level_by_recursion(head->left, level + 1, res);
    level_by_recursion(head->right, level + 1, res);

    return ;
}