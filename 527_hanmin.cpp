/*��������֮��ĺ�������ָ�������������ֶ�Ӧ������λ��ͬ��λ�õ���Ŀ��

������������ x �� y����������֮��ĺ������롣

ע�⣺
0 �� x, y < 2^31.

˼·�����⣬��ȡ���Ȼ������������1�ĸ�����
*/

#include"all_in.h"

using namespace std;

class Solution {
public:
    int hammingDistance(int x, int y) {
        int count = 0;
        int ret = x ^ y;
        while (ret != 0) {
            ret = ret & (ret - 1);
            count++;
        }
        return count;
    }
};

