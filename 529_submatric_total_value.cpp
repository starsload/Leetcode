/*给出矩阵 matrix 和目标值 target，返回元素总和等于目标值的非空子矩阵的数量。
子矩阵 x1, y1, x2, y2 是满足 x1 <= x <= x2 且 y1 <= y <= y2 的所有单元 matrix[x][y] 的集合。
如果 (x1, y1, x2, y2) 和 (x1', y1', x2', y2') 两个子矩阵中部分坐标不同（如：x1 != x1'），那么这两个子矩阵也不同。

知识点：二位前缀和（no.304） 一维前缀和（no.560）

思路：采用一维前缀和的想法，首先先枚举上下边界间每列的和，问题化为一维数组问题。
*/

#include"all_in.h"

using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        mp[0] = 1;
        int count = 0, pre = 0;
        for (auto& x : nums) {
            pre += x;
            if (mp.find(pre - k) != mp.end()) {
                count += mp[pre - k];
            }
            mp[pre]++;
        }
        return count;
    }

    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int ret = 0;
        int h = matrix.size(), c = matrix[0].size();
        for (int i = 0; i < h; i++) {
            vector<int> help(c);
            for (int j = i; j < h; j++) {
                for (int n = 0; n < c; n++) {
                    help[n] += matrix[j][n];
                }
                ret += subarraySum(help, target);
            }
        }
        return ret;
    }
};