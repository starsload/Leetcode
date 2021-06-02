/*给你一个整数数组 nums 和一个整数 k ，编写一个函数来判断该数组是否含有同时满足下述条件的连续子数组：

子数组大小 至少为 2 ，且
子数组元素总和为 k 的倍数。
如果存在，返回 true ；否则，返回 false 。

如果存在一个整数 n ，令整数 x 符合 x = n * k ，则称 x 是 k 的一个倍数。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/continuous-subarray-sum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

思路：前缀和，虽然想到了前缀和但一开始还是没有太清晰的思路。参考了下题解终于贯通了，还是修为不够。
	  首先我们计算nums中的前缀和，然后遍历修改后的数组，并用map记录除k的余数。如果我们发现有子数
	  组除k余数是一样的，并且子数组长度大于1，则找到了我们想要的结果。
*/

#include"all_in.h"

using namespace std;

class Solution {
public:
	bool checkSubarraySum(vector<int>& nums, int k) {
		int n = nums.size();
			vector<long long> help(n, 0);
		help[0] = nums[0];
		for (int i = 1; i < n; i++) {
			help[i] = help[i - 1] + nums[i];
		}
		map<int, int> mp;
		for (int i = 0; i < n;i++) {
			int div = help[i] % k;
			if (div == 0 && i != 0)return true;
			else if (mp.find(div) == mp.end()) {
				mp[div] = i;
			}
			else if (i - mp[div] > 1) {
				return true;
			}
		}
		return false;
	}
};