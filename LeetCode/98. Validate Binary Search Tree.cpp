class Solution {
public:
    
    
    void in_order(TreeNode* node, vector<int>& arr){
        if(node == NULL)
            return;
        if(node->left)
            in_order(node->left,arr);
        arr.push_back(node->val);
        if(node->right)
            in_order(node->right,arr);
    }
    bool isValidBST(TreeNode* root) {
        bool vaild =  true;
        vector<int> arr;
        in_order(root,arr);
        
        set<int> n;
        for(auto a:arr){
            if(n.count(a))
                return false;
            else
                n.insert(a);
        }
        vector<int> test = arr;
        sort(test.begin(),test.end());
        if(arr == test)
            return true;
        return false;
    }
};
