#include <iostream>
#include <fstream>
#include <queue>
using namespace std;

/**
 * Definition for a binary tree node.
 */
*struct TreeNode
{
    *int val;
    *TreeNode *left;
    *TreeNode *right;
    *TreeNode() : val(0), left(nullptr), right(nullptr){} * TreeNode(int x) : val(x), left(nullptr), right(nullptr){} * TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right){}
                                                                                                                                                                                                   *
};

class Solution
{
public:
    vector<int> rightSideView(TreeNode *root)
    {
        vector<int> right;
        if (root == NULL)
            return right;
        queue<TreeNode *> q;
        if (root != NULL)
        {
            q.push(root);
            vector<int> level;
            while (!q.empty())
            {
                int len = q.size();
                for (int i = 0; i < len; i++)
                {
                    TreeNode *temp = q.front();
                    q.pop();
                    int val = temp->val;
                    level.push_back(val);
                    if (temp->left != NULL)
                    {
                        q.push(temp->left);
                    }
                    if (temp->right != NULL)
                    {
                        q.push(temp->right);
                    }
                }
                right.push_back(level.at(level.size() - 1));
                level.clear();
            }
        }
        return right;
    }
};

main()
{
}