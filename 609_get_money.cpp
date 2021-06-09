/*集团里有 n 名员工，他们可以完成各种各样的工作创造利润。

第 i 种工作会产生 profit[i] 的利润，它要求 group[i] 名成员共同参与。如果成员参与了其中一项工作，就不能参与另一项工作。

工作的任何至少产生 minProfit 利润的子集称为 盈利计划 。并且工作的成员总数最多为 n 。

有多少种计划可以选择？因为答案很大，所以 返回结果模 10^9 + 7 的值。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/profitable-schemes
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

思路：动态规划，这个月就跟动归和背包杠上了是吧

*/

class Solution {
public:
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        vector<vector<int>> dp(n + 1, vector<int>(minProfit + 1));
        for (int i = 0; i <= n; i++) {
            dp[i][0] = 1;
        }
        int len = group.size(), MOD = (int)1e9 + 7;
        for (int i = 1; i <= len; i++) {
            int members = group[i - 1], earn = profit[i - 1];
            for (int j = n; j >= members; j--) {
                for (int k = minProfit; k >= 0; k--) {
                    dp[j][k] = (dp[j][k] + dp[j - members][max(0, k - earn)]) % MOD;
                }
            }
        }
        return dp[n][minProfit];
    }
};
