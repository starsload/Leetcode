/*给你一个整数 n，请你判断该整数是否是 2 的幂次方。如果是，返回 true ；否则，返回 false 。

如果存在一个整数 x 使得 n == 2x ，则认为 n 是 2 的幂次方。

思路：如果用循环的话，不仅性能差，也太没有技术含量了
      我们考虑数的性质。如果我们列出数字的二进制表示，很容易发现2的幂数仅在本位上为1，其他位都是0，因此我们有
      1、若n&（n-1）=0，则n是2的幂
      2、否则，不是2的幂
*/

#include"all_in.h"

using namespace std;

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n <= 0)return false;
        if ((n & (n - 1)) == 0)return true;
        return false;
    }
};