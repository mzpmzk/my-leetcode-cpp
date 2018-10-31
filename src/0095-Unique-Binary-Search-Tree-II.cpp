/**
 * Given an integer n, generate all structurally unique BST's (binary search trees) that store
 * values 1 ... n.
 * Example:
 * Input: 3
 * Output:
 * [
 *   [1,null,3,2],
 *   [3,2,null,1],
 *   [3,1,null,null,2],
 *   [2,1,3],
 *   [1,null,2,null,3]
 * ]
 * Explanation:
 * The above output corresponds to the 5 unique BST's shown below:
 *    1         3     3      2      1
 *     \       /     /      / \      \
 *      3     2     1      1   3      2
 *     /     /       \                 \
 *    2     1         2                 3
 */

#include "../utils/MyBinaryTreeUtil.h"

#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) return vector<TreeNode *>();
        return generateTrees(1, n);
    }

    vector<TreeNode *> generateTrees(int start, int end) {
        vector<TreeNode *> roots;
        if (start > end) {
            roots.emplace_back(nullptr);
            return roots;
        }
        for (int i = start; i <= end; ++i) {
            auto lefts = generateTrees(start, i-1);
            auto rights = generateTrees(i+1, end);
            for (auto *l : lefts) {
                for (auto *r : rights) {
                    auto *root = new TreeNode(i);
                    root->left = l;
                    root->right = r;
                    roots.emplace_back(root);
                }
            }
        }
        return roots;
    }
};

int main() {
    Solution s;
    int testId = 1;

    vector<int> ns{3, 0};

    for (auto &n : ns) {
        auto roots = s.generateTrees(n);
        std::cout << "Case " << testId++ << ":\n  [\n";
        for (const auto *root : roots) {
            std::cout << "    ";
            myDispTreeByLevel(root);
        }
        std::cout << "  ]" << std::endl;
    }
}