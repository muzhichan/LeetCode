#define TREENODE
#include "../common.hpp"
using std::vector;
using std::queue;

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (root == nullptr) {
            return vector<vector<int>> ();
        }
        vector<vector<int>> re;
        queue<TreeNode*> q;
        q.push(root);
        bool flag = true;  // left to right
        while (!q.empty()) {
            int q_sz = q.size();
            vector<int> level_nodes(q_sz);
            for (int i = 0; i < q_sz; ++i) {
                TreeNode* cur = q.front();
                if (flag) {
                    level_nodes[i] = cur->val;
                } else {
                    level_nodes[q_sz - i - 1] = cur->val;
                }
                if (cur->left != nullptr) {
                    q.push(cur->left);
                }
                if (cur->right != nullptr) {
                    q.push(cur->right);
                }
                q.pop();
            }
            re.push_back(level_nodes);
            flag = !flag;
        }
        return re;
    }

    //TODO 双端队列实现
};