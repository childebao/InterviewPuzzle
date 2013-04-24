/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        TreeLinkNode *curr = root;
        
        // Remember to check if (root == NULL)
        while (curr && curr->left) {
            curr->left->next = curr->right;
            
            TreeLinkNode *tmpCurr = curr->next;
            TreeLinkNode *tmpTail = curr->right;
            while (tmpCurr) {
                tmpTail->next = tmpCurr->left;
                tmpCurr->left->next = tmpCurr->right;
                
                tmpTail = tmpCurr->right;
                tmpCurr = tmpCurr->next;
            }
            
            curr = curr->left;
        }
    }
};