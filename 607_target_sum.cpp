/*给你一个整数数组 nums 和一个整数 target 。

向数组中的每个整数前添加 '+' 或 '-' ，然后串联起所有整数，可以构造一个 表达式 ：

例如，nums = [2, 1] ，可以在 2 之前添加 '+' ，在 1 之前添加 '-' ，然后串联起来得到表达式 "+2-1" 。
返回可以通过上述方法构造的、运算结果等于 target 的不同 表达式 的数目。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/target-sum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

思路：1、使用回溯解决。使用全局变量ret保存结果。这种问方案数的基本都用回溯解决。回溯问题基本有固定模板，多看多练。
      2、动态规划：是0-1背包问题的一个变形，这种解法是参考答案看出来的，修为还远远不够。
         使用动态规划的话，我们需要把问题进行转化，说实话这种解法和昨天很类似，放在一起回顾吧。
*/

#include"all_in.h"

using namespace std;

class Solution {
public:
    int ret = 0;

    void backtrack(vector<int>& nums, int target, int cur,int sum) {
        if (cur == nums.size()) {
            if(sum == target){
                ret++;
            }
            return;
        }
        else {
            backtrack(nums, target, cur + 1, sum + nums[cur]);
            backtrack(nums, target, cur + 1, sum - nums[cur]);
        }
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        backtrack(nums, target, 0, 0);
        return ret;
    }
};


class Solution2 {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        for (int& num : nums) {
            sum += num;
        }
        int diff = sum - target;
        if (diff < 0 || diff % 2 != 0) {
            return 0;
        }
        int neg = diff / 2;
        vector<int> dp(neg + 1);
        dp[0] = 1;
        for (int& num : nums) {
            for (int j = neg; j >= num; j--) {
                dp[j] += dp[j - num];
            }
        }
        return dp[neg];
    }
};