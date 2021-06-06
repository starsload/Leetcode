/*525.给定一个二进制数组 nums , 找到含有相同数量的 0 和 1 的最长连续子数组，并返回该子数组的长度。

思路：本质还是在做前缀和问题。我们遍历数组，遇到零就加上-1，遇到1就加1，以此得到前缀和数组，在此过程中用map记录各个前缀和出现的位置。
      计算完前缀和数组后，遍历map，找到相同前缀和中最先出现的位置和最后出现的位置，相减即该前缀和下的最大子数组。比较所有，得出结果。
*/

#include"all_in.h"

using namespace std;

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        map<int, vector<int>> mp;
        int n = nums.size();
        vector<int> help(n, 0);
        help[0] = (nums[0] == 0) ? -1 : 1;
        mp[help[0]].push_back(0);
        for (int i = 1; i < n; i++) {
            help[i] = help[i - 1] + ((nums[i] == 0) ? -1 : 1);
            mp[help[i]].push_back(i);
        }

        int m = 0;
        if (mp.find(0) != mp.end()) {
            m = mp[0].back() + 1;
        }
        map<int, vector<int>>::iterator it = mp.begin();
        while (it != mp.end()) {
            int temp = it->second.back() - it->second[0];
            if (m < temp) {
                m = temp;
            }
            it++;
        }
        return m;
    }
};