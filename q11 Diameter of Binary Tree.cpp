#include<bits/stdc++.h>
using namespace std;


  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
class Solution {
public:
    int ans = 0;
    int heightOfBinaryTree(TreeNode* root)
    {
        if(root==NULL)
        {
            return 0;
        }
        int left = heightOfBinaryTree(root->left);
        int right = heightOfBinaryTree(root->right);
        ans = max(ans,left+right);
        return 1+max(left,right);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        heightOfBinaryTree(root);
        return ans;
    }
};