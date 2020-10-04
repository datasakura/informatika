class Solution {
public:
    bool isEvenOddTree(TreeNode* root) {
        vector<TreeNode*> odd, even;
        odd.push_back(root);
    
        int o = 0, e = 0;

        bool work = true;
        
        while (work) {
            work = false;
            
            int oc = -1e7;
            
            while (o < odd.size()) {
                if (odd[o]->val % 2 == 0)
                    return false;
                if (odd[o]->val <= oc)
                    return false;
                oc = odd[o]->val;
                
                work = true;
                if (odd[o]->left)
                    even.push_back(odd[o]->left);
                if (odd[o]->right)
                    even.push_back(odd[o]->right);
                o++;
            }

            int ec = 1e7;           
            while (e < even.size()) {
                if (even[e]->val % 2 == 1)
                    return false;
                if (even[e]->val >= ec)
                    return false;
                ec = even[e]->val;

                work = true;
                if (even[e]->left)
                    odd.push_back(even[e]->left);
                if (even[e]->right)
                    odd.push_back(even[e]->right);
                e++;
            }
        }
                
        return true;
    }
};