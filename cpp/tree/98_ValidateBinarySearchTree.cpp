#define TREENODE
#include "../common.hpp"
using std::vector;
using std::stack;

/**
* 注意：
* 1. 边界溢出问题，int 类型最小值 -2147483648(巨坑)
* 2. 注意等于的情况视为 false 情况
* 扩展：
* 如果左树小于，右树大于等于？
*/
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        stack<TreeNode*> s_n;
        int first = std::numeric_limits<int>::min();
        // 第一个值为 MIN 情况
        int flag = true;

        while (root != nullptr || !s_n.empty()) {
            if (root != nullptr) {
                s_n.push(root);
                // pre-order travel
                // re.push_back(root->val);
                root = root->left;
            } else {
                TreeNode* tmp = s_n.top();
                // in-order travel
                // re.push_back(tmp->val);
                if (tmp->val <= first && !flag) {
                    return false;
                }
                if (flag) {
                    flag = false;
                }

                first = tmp->val;
                root = tmp->right;
                s_n.pop();
            }
        }
        return true;
    }
};
