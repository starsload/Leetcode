/*525.����һ������������ nums , �ҵ�������ͬ������ 0 �� 1 ������������飬�����ظ�������ĳ��ȡ�

˼·�����ʻ�������ǰ׺�����⡣���Ǳ������飬������ͼ���-1������1�ͼ�1���Դ˵õ�ǰ׺�����飬�ڴ˹�������map��¼����ǰ׺�ͳ��ֵ�λ�á�
      ������ǰ׺������󣬱���map���ҵ���ͬǰ׺�������ȳ��ֵ�λ�ú������ֵ�λ�ã��������ǰ׺���µ���������顣�Ƚ����У��ó������
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