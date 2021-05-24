/*有台奇怪的打印机有以下两个特殊要求：

打印机每次只能打印由 同一个字符 组成的序列。
每次可以在任意起始和结束位置打印新字符，并且会覆盖掉原来已有的字符。
给你一个字符串 s ，你的任务是计算这个打印机打印它需要的最少打印次数。

思路：动态规划。对于一个字符串s，我们要计算从i到j的打印次数，用二维数组dp[i][j]记录，则只需要考虑以下两种情况：
		1、当s[i]=s[j]，此时我们可以有dp[i][j]=dp[i][j-1]
		2、当s[i]!=s[j]，此时我们可以找到一个i<k<j，dp[i][j]=min(dp[i][k]+dp[k+1][j])
*/

#include<stdlib.h>
#include<string>
#include<vector>
#include<iostream>

using namespace std;

class Solution {
public:
    int strangePrinter(string s) {
		int len = s.length();
		vector<vector<int>> dp(len, vector<int>(len));
		for (int i = len - 1; i >= 0; i--) {
			dp[i][i] = 1;
			for (int j = i + 1; j < len; j++) {
				if (s[i] == s[j]) {
					dp[i][j] = dp[i][j - 1];
				}
				else {
					int m = INT_MAX;
					for (int k = i; k < j; k++) {
						m = min(m, dp[i][k] + dp[k + 1][j]);
					}
					dp[i][j] = m;
				}
			}
		}
		return dp[0][len - 1];
    }
};