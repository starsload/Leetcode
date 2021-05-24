/*��̨��ֵĴ�ӡ����������������Ҫ��

��ӡ��ÿ��ֻ�ܴ�ӡ�� ͬһ���ַ� ��ɵ����С�
ÿ�ο�����������ʼ�ͽ���λ�ô�ӡ���ַ������һḲ�ǵ�ԭ�����е��ַ���
����һ���ַ��� s ����������Ǽ��������ӡ����ӡ����Ҫ�����ٴ�ӡ������

˼·����̬�滮������һ���ַ���s������Ҫ�����i��j�Ĵ�ӡ�������ö�ά����dp[i][j]��¼����ֻ��Ҫ�����������������
		1����s[i]=s[j]����ʱ���ǿ�����dp[i][j]=dp[i][j-1]
		2����s[i]!=s[j]����ʱ���ǿ����ҵ�һ��i<k<j��dp[i][j]=min(dp[i][k]+dp[k+1][j])
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