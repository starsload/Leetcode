/*������ͬ����Ӳ�Һ�һ���ܽ�д��������������Դճ��ܽ���Ӳ�������������ÿһ������Ӳ�������޸���

˼·��һ��ʼ�������ˣ�������Ϊ�ǻ��ݽ�����Ƕ�̬�滮��
      �����Ӧ�������ֱȽ�ƫ�򵥵Ķ�̬�滮��״̬ת�Ʒ���ֻ��Ҫһ��dp[i] += dp[i-coin]���� ��dp�����ʾѡ���������iΪ�ܽ��
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
