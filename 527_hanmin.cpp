/*两个整数之间的汉明距离指的是这两个数字对应二进制位不同的位置的数目。

给出两个整数 x 和 y，计算它们之间的汉明距离。

注意：
0 ≤ x, y < 2^31.

思路：简单题，先取异或然后计算异或结果里1的个数。
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

