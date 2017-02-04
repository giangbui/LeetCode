//Given an integer n, generate all structurally unique BST's (binary search trees) that store values 1...n.
//Solution: Dynamic programming
// The basic idea is that we can construct the result of n node tree just from the result of n-1 node tree.
//Here's how we do it: only 2 conditions: 1) The nth node is the new root, so newroot->left = oldroot;
//the nth node is not root, we traverse the old tree, every time the node in the old tree has a right child, we can perform: old node->right = nth node, nth node ->left = right child; and when we reach the end of the tree, don't forget we can also add the nth node here.
//One thing to notice is that every time we push a TreeNode in our result, I push the clone version of the root, and I recover what I do to the old node immediately. This is because you may use the old tree for several times.

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
