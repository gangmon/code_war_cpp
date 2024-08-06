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
    if (level <= res.size()) {
        res[level-1].push_back(head->val);
    } else {
        vector<int> vec;
        vec.push_back(head->val);
        res.push_back(vec);
    }
    level_by_recursion(head->left, level + 1, res);
    level_by_recursion(head->right, level + 1, res);

    return ;
}


vector<vector<int>> level_order_from_button_by_gpt(TreeNode* root){
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
        res.insert(res.begin(), level);
    }
    return res;
}

vector<vector<int>> level_order_from_bottom(TreeNode* root) {
    vector<vector<int>> res;
    if (root == nullptr) return res;
    vector<vector<TreeNode*>> tower;
    vector<TreeNode*> level;
    level.push_back(root);
    tower.push_back(level);
    for (size_t i = 0; i < tower.size(); i++) {
        vector<TreeNode*> cur_level;
        for (size_t j = 0; j < tower[i].size(); j++) {
            if (tower[i][j]->left != nullptr) cur_level.push_back(tower[i][j]->left);
            if (tower[i][j]->right != nullptr) cur_level.push_back(tower[i][j]->right);
        }
        tower.push_back(cur_level);
    }

    for (size_t i = tower.size(); i > 0; i -- ) {
        vector<int> l;
        for (size_t j = 0; j < tower[i-1].size(); j++) {
            l.push_back(tower[i-1][j]->val);
        }
        res.push_back(l);
    }
    return res;
}

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

TreeNode* mirrorTree(TreeNode* root) {
    if (root == nullptr) return nullptr;
    TreeNode* left = mirrorTree(root->left);
    TreeNode* right = mirrorTree(root->right);
    root->left = right;
    root->right = left;
    return root;
}


TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (root == nullptr) return nullptr;
    if (root == p || root == q) return root;
    TreeNode* left = lowestCommonAncestor(root, p, q);
    TreeNode* right = lowestCommonAncestor(root, p, q);

    if (left && right) return root;
    return left == nullptr ? right : left;
}
int treeDepth(TreeNode* root) {
    if (root == nullptr) return 0;
    int left = treeDepth(root->left);
    int right = treeDepth(root->right);
    return max(left, right) + 1;
}

// 输入一棵二叉树的根节点，判断该树是不是平衡二叉树。如果某二叉树中任意节点的左右子树的深度相差不超过1，那么它就是一棵平衡二叉树。
bool isBalanced(TreeNode* root) {
    if (root == nullptr) return true;
    if (abs(treeDepth(root->left) - treeDepth(root->right)) > 1) return false;
    return isBalanced(root->left) && isBalanced(root->right);
}


TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
    if (nums.empty()) return nullptr;
    int max_val = INT_MIN;
    int max_index = 0;
    for (size_t i = 0; i < nums.size(); i++) {
        if (nums[i] > max_val) {
            max_val = nums[i];
            max_index = i;
        }
    }
    TreeNode* root = new TreeNode(max_val);
    vector<int> left(nums.begin(), nums.begin() + max_index);
    vector<int> right(nums.begin() + max_index + 1, nums.end());
    root->left = constructMaximumBinaryTree(left);
    root->right = constructMaximumBinaryTree(right);
    return root;
}

TreeNode* pruneTree(TreeNode* root) {

}

int maxPathSumFromRoot(TreeNode* root) {
    if (root == nullptr) return 0;
    int left = maxPathSumFromRoot(root->left);
    int right = maxPathSumFromRoot(root->right);
    return max(left, right) + root->val;
}

int maxPathSumOne(TreeNode* root) {
    if (root == nullptr) return 0;
    int left = maxPathSumFromRoot(root->left);
    int right = maxPathSumFromRoot(root->right);

    return root->val + left + right;
}

int maxPathSum(TreeNode* root) {
    if (root == nullptr) return INT_MIN;
    int left = maxPathSumOne(root->left);
    int right = maxPathSumOne(root->right);


    return max(left+right+root->val,max(maxPathSum(root->left), maxPathSum(root->right)));
}



class Solution2 {
private:
    int maxSum = INT_MIN;

public:
    int maxGain(TreeNode* node) {
        if (node == nullptr) {
            return 0;
        }

        // 递归计算左右子节点的最大贡献值
        // 只有在最大贡献值大于 0 时，才会选取对应子节点
        int leftGain = max(maxGain(node->left), 0);
        int rightGain = max(maxGain(node->right), 0);

        // 节点的最大路径和取决于该节点的值与该节点的左右子节点的最大贡献值
        int priceNewpath = node->val + leftGain + rightGain;

        // 更新答案
        maxSum = max(maxSum, priceNewpath);

        // 返回节点的最大贡献值
        return node->val + max(leftGain, rightGain);
    }

    int maxPathSum(TreeNode* root) {
        maxGain(root);
        return maxSum;
    }
};

int josephus(int n, int k) {
    if (n == 1) return 0;

    return (josephus(n-1, k) + k) % n;
}

int josephus2(int n, int k) {
    vector<int> people;
    for (int i = 1; i <= n; i ++){
        people.push_back(i);
    }
    while (people.size() > 1){
        while (people.size() > k) {
            people.erase(people.begin() + k -1 );
        }
        people.erase(people.begin() + k % people.size() -1 );
    }
    return people[0];
}

int findTheWinner(int n, int k) {
    vector<int> people;
    for (int i = 1; i <= n; i ++){
        people.push_back(i);
    }
    int count = 0;

    while (people.size() > 1) {
        for (int p = 1; p <= people.size() && people.size() > 1; p++) {
            count++;
            if (count % k == 0) {
                people.erase(people.begin() + p - 1);
                p--;
            }
        }
    }
    return people[0];
}

int findTheWinner2(int n, int k) {
    vector<int> people;
    for (int i =1; i <= n; i ++)
    {
        people.push_back(i);
    }
    int count = 0;

    while (people.size() > 1) {

        for (int pos = 1; pos <= people.size(); pos ++) {
            count ++;
            if (count % k == 0) {
                people.erase(people.begin() + pos - 1);
                pos --;
            }
        }
    }
    return people[0];
}


int findTheWinner3(int n, int k) {
    ListNode *head = new ListNode(0);

    ListNode *current = head;
    for (int i = 1; i <= n; i ++) {
        current->next = new ListNode(i);
        current = current->next;
    }
    current->next = head->next;
    ListNode *run = current;
    for (int i = 1; run->next != run ; i ++) {
        if (i % k == 0) {
            run->next = run->next->next;
        }
        run = run->next;
    }
    return run->val;
}

vector<int> findPeaks(vector<int>& mountain) {
    vector<int> res;
    for (size_t i = 1; i < mountain.size() - 1; i ++ ) {
        if (mountain[i] > mountain[i-1] && mountain[i] > mountain[i+1]){
            res.push_back(i);
        }
    };

    return res;
}


