/*给你一个下标从 0 开始的正整数数组 candiesCount ，其中 candiesCount[i] 表示你拥有的第 i 类糖果的数目。同时给你一个二维数组 queries ，其中 queries[i] = [favoriteTypei, favoriteDayi, dailyCapi] 。

你按照如下规则进行一场游戏：

你从第 0 天开始吃糖果。
你在吃完 所有 第 i - 1 类糖果之前，不能 吃任何一颗第 i 类糖果。
在吃完所有糖果之前，你必须每天 至少 吃 一颗 糖果。
请你构建一个布尔型数组 answer ，满足 answer.length == queries.length 。answer[i] 为 true 的条件是：在每天吃 不超过 dailyCapi 颗糖果的前提下，你可以在第 favoriteDayi 天吃到第 favoriteTypei 类糖果；否则 answer[i] 为 false 。注意，只要满足上面 3 条规则中的第二条规则，你就可以在同一天吃不同类型的糖果。

请你返回得到的数组 answer 。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/can-you-eat-your-favorite-candy-on-your-favorite-day
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

思路：这道题虽然蛮长的，各种各样的变量也很多，但只要仔细读一读并不是很难。
      我们知道的有糖果种类和数量、喜欢的时间和糖果种类以及每天吃的糖果上下限，问题可以抽象为在第i天能否累积到0-（j-1）
      种糖果，问题就变成了集合包含的问题以及前缀和问题。本题的陷阱是从第零天开始，这一点还挺坑的。
*/

#include"all_in.h"

using namespace std;

class Solution {
public:
    vector<bool> canEat(vector<int>& candiesCount, vector<vector<int>>& queries) {
        int n = candiesCount.size();
        vector<long long>help(n, 0);
        help[0] = candiesCount[0];
        for (int i = 0; i < n - 1; i++) {
            help[i] = help[i - 1] + candiesCount[i];
        }
        int m = queries.size();
        vector<bool> ret(m, false);
        for (int i = 0; i < m; i++) {
            pair<long long, long long> temp(0, 0);
            if (queries[i][0] == 0) {
                temp.first = queries[i][1] + 1;
                temp.second = queries[i][2] * temp.first;
                if (temp.first < help[0] && temp.second>0) {
                    ret[i] = true;
                }
                else ret[i] = false;
            }
            else {
                temp.first = queries[i][1] + 1;
                temp.second = queries[i][2] * temp.first;
                if (temp.first <= help[queries[i][0]] && temp.second > help[queries[i][0] - 1]) {
                    ret[i] = true;
                }
                else ret[i] = false;
            }
        }
        return ret;
    }
};



/*answer*/
class Solution {
private:
    using LL = long long;
public:
    vector<bool> canEat(vector<int>& candiesCount, vector<vector<int>>& queries) {
        int n = candiesCount.size();

        // 前缀和
        vector<LL> sum(n);
        sum[0] = candiesCount[0];
        for (int i = 1; i < n; ++i) {
            sum[i] = sum[i - 1] + candiesCount[i];
        }

        vector<bool> ans;
        for (const auto& q : queries) {
            int favoriteType = q[0], favoriteDay = q[1], dailyCap = q[2];

            LL x1 = favoriteDay + 1;
            LL y1 = (LL)(favoriteDay + 1) * dailyCap;
            LL x2 = (favoriteType == 0 ? 1 : sum[favoriteType - 1] + 1);
            LL y2 = sum[favoriteType];

            ans.push_back(!(x1 > y2 || y1 < x2));
        }
        return ans;
    }
};