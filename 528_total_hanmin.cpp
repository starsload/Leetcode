/*两个整数的 汉明距离 指的是这两个数字的二进制数对应位不同的数量。
计算一个数组中，任意两个数之间汉明距离的总和。

思路：一开始想用暴力试试，但是仔细想想是n^2的复杂度，遂放弃。考虑海明距离的定义，
	  按位运算是个不错的选择。我们只需要统计每位上有几个0几个1，将其乘起来就是这
	  一位上的海明距离，枚举整个数组即可得到答案。复杂度为n*L
*/

#include"all_in.h"

using namespace std;

class Solution {
public:
	int totalHammingDistance(vector<int>& nums) {
		int len = nums.size(),ret = 0;
		for (int i = 0; i < 30; i++) {
			int count = 0;
			for (int num : nums) {
				if ((num >> i) & 1)count++;
			}
			ret += count * (len - count);
		}
		return ret;
	}
};