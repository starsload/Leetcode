/*有一堆石头，用整数数组 stones 表示。其中 stones[i] 表示第 i 块石头的重量。

每一回合，从中选出任意两块石头，然后将它们一起粉碎。假设石头的重量分别为 x 和 y，且 x <= y。那么粉碎的可能结果如下：

如果 x == y，那么两块石头都会被完全粉碎；
如果 x != y，那么重量为 x 的石头将会完全粉碎，而重量为 y 的石头新重量为 y-x。
最后，最多只会剩下一块 石头。返回此石头 最小的可能重量 。如果没有石头剩下，就返回 0。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/last-stone-weight-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

思路：单纯从数学角度考虑的话，本题要求出迭代差的最小值，那么我们可以考虑将石头重量排序然后取小的一半和大的一半组合相减，迭代至只有一个。
      有点类似贪心算法。看来这种方法行不通。

      动态规划，这个月全是动态规划啊，周末就得好好看看复习下了
*/

#include"all_in.h"

using namespace std;

class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        sort(stones.begin(), stones.end());
        while (stones.size() > 1) {
            int i = 0;
            int len = stones.size();
            while (i < len / 2) {
                stones[i] = stones.back() - stones[i];
                stones.pop_back();
                i++;
            }
            vector<int>::iterator it = stones.begin();
            while (it != stones.end()) {
                if (*it == 0)
                    stones.erase(it);
                it++;
            }
            sort(stones.begin(), stones.end());
        }
        return stones[0];
    }
};

class Solution2 {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int sum = accumulate(stones.begin(), stones.end(), 0);
        int m = sum / 2;
        vector<int> dp(m + 1);
        dp[0] = true;
        for (int weight : stones) {
            for (int j = m; j >= weight; --j) {
                dp[j] = dp[j] || dp[j - weight];
            }
        }
        for (int j = m;; --j) {
            if (dp[j]) {
                return sum - 2 * j;
            }
        }

    }
};