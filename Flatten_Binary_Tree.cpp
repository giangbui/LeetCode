//Given a binary tree, flatten it to a linked list in-place.
//Solution: Recursively flatten the tree from the root. 

class Solution {
public:
    void flatten(TreeNode* root) {
        TreeNode *head = nullptr;
        flattenWorker(root, head);
    }
private:
    void flattenWorker(TreeNode* root, TreeNode*& head) {
        if (root == nullptr) {
            return;
        }
        flattenWorker(root->right, head);
        flattenWorker(root->left, head);
        root->left = nullptr;
        root->right = head;
        head = root;
    }
};
