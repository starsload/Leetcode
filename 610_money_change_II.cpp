/*给定不同面额的硬币和一个总金额。写出函数来计算可以凑成总金额的硬币组合数。假设每一种面额的硬币有无限个。

思路：一开始看错题了，本来以为是回溯结果还是动态规划。
      这道题应该是那种比较偏简单的动态规划，状态转移方程只需要一个dp[i] += dp[i-coin]即可 ，dp数组表示选择的种数，i为总金额
*/

#include"all_in.h"

using namespace std;

class Solution {
public:
   
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount + 1, 0);
        dp[0] = 1;
        for (int coin : coins) {
            for (int i = coin; i <= amount; i++) {
                dp[i] += dp[i - coin];
            }
        }
        return dp[amount];
    }
};
