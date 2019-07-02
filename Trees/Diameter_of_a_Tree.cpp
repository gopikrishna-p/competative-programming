//Time Complexity : O(N)
//Space Complexity:O(n) ->Stack Memory
//Url : https://leetcode.com/problems/diameter-of-binary-tree/

class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if (root == NULL) 
            return 0; 
        int ans = INT_MIN; 
        int height_of_tree = height(root, ans); 
        return ans;
    }
    int height(TreeNode* root, int& ans) 
    { 
        if (root == NULL) 
            return 0; 
        int left_height = height(root->left, ans); 
        int right_height = height(root->right, ans); 
        ans = max(ans, left_height + right_height); 
        return 1 + max(left_height, right_height); 
    } 

};
