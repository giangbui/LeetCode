//Given an integer n, generate all structurally unique BST's (binary search trees) that store values 1...n.
//Solution: Dynamic programming
// 

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    TreeNode * clone(TreeNode * root){
        if(NULL == root) return NULL;
        TreeNode * newRoot = new TreeNode(root->val);
        newRoot->left = clone(root->left);
        newRoot->right = clone(root->right);
        return newRoot;
    }
    void addToLeft(TreeNode * oldRoot, TreeNode * newRoot, vector<TreeNode *> & results){
        TreeNode * cloneRoot = clone(oldRoot);
        newRoot->left = cloneRoot;
        results.push_back(newRoot);
    }
    void addRight(TreeNode * oldRoot, TreeNode * cur, TreeNode * newNode, vector<TreeNode *> & results){
        TreeNode *cloneRoot = clone(oldRoot);
        TreeNode *newCur = cloneRoot;
        while(NULL != newCur){
            if(newCur->val == cur->val) break;
            else newCur = newCur->right;
        }
        assert(NULL != newCur);
        TreeNode * temp = newCur->right;
        newCur->right = newNode;
        newNode->left = temp;
        results.push_back(cloneRoot);
    }
public:
    vector<TreeNode *> generateTrees(int n) {
        // DP:
        // for n-1 to n , for each n -1
        // 1) left to n
        // 2) for each right child down
        //    n replace right and right will be n left
        vector<TreeNode *> results;
        vector<TreeNode *> preResults(1, NULL);
        for(int i = 1; i <=n; i ++){
            for(int j = 0; j < preResults.size(); j++){
                // add n-1 left to n 
                TreeNode * oldRoot = preResults[j];
                TreeNode * newRoot = new TreeNode(i);
                addToLeft(oldRoot, newRoot, results);
                TreeNode * cur = oldRoot;
                while(NULL != cur){
                    TreeNode *newNode = new TreeNode(i);
                    addRight(oldRoot, cur, newNode, results);
                    cur = cur->right;
                }
            }
            swap(results, preResults);
            results.clear();
        }
        return preResults;
    }
};
