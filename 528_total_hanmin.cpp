/*���������� �������� ָ�������������ֵĶ���������Ӧλ��ͬ��������
����һ�������У�����������֮�人��������ܺ͡�

˼·��һ��ʼ���ñ������ԣ�������ϸ������n^2�ĸ��Ӷȣ�����������Ǻ�������Ķ��壬
	  ��λ�����Ǹ������ѡ������ֻ��Ҫͳ��ÿλ���м���0����1�����������������
	  һλ�ϵĺ������룬ö���������鼴�ɵõ��𰸡����Ӷ�Ϊn*L
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