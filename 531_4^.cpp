/*给定一个整数，写一个函数来判断它是否是 4 的幂次方。如果是，返回 true ；否则，返回 false 。

整数 n 是 4 的幂次方需满足：存在整数 x 使得 n == 4^x

思路：本题和昨天的2的幂类似，不同的是2的幂我们只需要保证二进制表示中只有一个1就可以，但是4的幂还要满足一些特殊
      条件——1必须位于奇数位上。这一点不太好找出满足的条件，换个角度思考，所有4的幂m都有m%3=1，我们可以利用这
      一点来保证是4的幂而不是2的幂。
*/

#include"all_in.h"

using namespace std;

class Solution {
public:
    bool isPowerOfFour(int n) {
        if (n <= 0)return false;
        if ((n & (n - 1)) == 0 && n%3==1)return true;
        return false;
    }
};