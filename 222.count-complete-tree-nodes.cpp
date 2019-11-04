/*
 * @lc app=leetcode id=222 lang=cpp
 *
 * [222] Count Complete Tree Nodes
 *
 * https://leetcode.com/problems/count-complete-tree-nodes/description/
 *
 * algorithms
 * Medium (36.98%)
 * Likes:    1318
 * Dislikes: 159
 * Total Accepted:    155.9K
 * Total Submissions: 407.2K
 * Testcase Example:  '[1,2,3,4,5,6]'
 *
 * Given a complete binary tree, count the number of nodes.
 * 
 * Note: 
 * 
 * Definition of a complete binary tree from Wikipedia:
 * In a complete binary tree every level, except possibly the last, is
 * completely filled, and all nodes in the last level are as far left as
 * possible. It can have between 1 and 2^h nodes inclusive at the last level
 * h.
 * 
 * Example:
 * 
 * 
 * Input: 
 * ⁠   1
 * ⁠  / \
 * ⁠ 2   3
 * ⁠/ \  /
 * 4  5 6
 * 
 * Output: 6
 * 
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int pathSum(TreeNode* root, int sum) {
        if(!root) return 0;
        int ans = 0;
        bool flag = true;
        dfs(root, sum, ans, flag);
        return ans;
    }
private:
    void dfs(TreeNode* node, int sum, int& ans, bool flag){
        if(!node) return;
        if(sum == node->val){
            ans++;
        }
        if(flag){
            dfs(node->left, sum, ans, true);
            dfs(node->right, sum, ans, true);
        }
        dfs(node->left, sum - node->val, ans, false);
        dfs(node->right, sum - node->val, ans, false);
        
    }
};
// @lc code=end
