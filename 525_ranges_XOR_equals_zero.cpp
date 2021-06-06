/*
给你一个整数数组 nums​​​ 和一个整数 k​​​​​ 。区间[left, right]（left <= right）的异或结果是
对下标位于 left 和 right（包括 left 和 right ）之间所有元素进行 XOR 运算的结果：
    nums[left] XOR nums[left+1] XOR ... XOR nums[right] 。
返回数组中 要更改的最小元素数 ，以使所有长度为 k 的区间异或结果等于零。

思路：没有思路，今天看答案了，我紫菜。
    x1 XOR x2 XOR x3…………XOR xk = 0
    x2 XOR x3 XOR x4…………XOR xk+1 = 0
    联立则有x1 XOR xk+1 = 0，即x1 = xk+1
    考虑异或的性质，不难看出我们的答案必然是k个元素一组的周期数组。
    剩下的不懂了，等以后再看吧。
*/

#include "all_in.h"

using namespace std;

class Solution {
public:
    int minChanges(vector<int>& nums, int k) {
        int n = nums.length;
        int max = 1024;
        int[][] f = new int[k][max];
        int[] g = new int[k];
        for (int i = 0; i < k; i++) {
            Arrays.fill(f[i], 0x3f3f3f3f);
            g[i] = 0x3f3f3f3f;
        }
        for (int i = 0, cnt = 0; i < k; i++, cnt = 0) {
            // 使用 map 和 cnt 分别统计当前列的「每个数的出现次数」和「有多少个数」
            Map<Integer, Integer> map = new HashMap<>();
            for (int j = i; j < n; j += k) {
                map.put(nums[j], map.getOrDefault(nums[j], 0) + 1);
                cnt++;
            }
            if (i == 0) { // 第 0 列：只需要考虑如何将该列变为 xor 即可
                for (intxor = 0; xor < max; xor ++) {
                    f[0][xor] = Math.min(f[0][xor], cnt - map.getOrDefault(xor, 0));
                    g[0] = Math.min(g[0], f[0][xor]);
                }
            }
            else { // 其他列：考虑与前面列的关系
                for (intxor = 0; xor < max; xor ++) {
                    f[i][xor] = g[i - 1] + cnt; // 整列替换
                    for (int cur : map.keySet()) { // 部分替换
                        f[i][xor] = Math.min(f[i][xor], f[i - 1][xor ^cur] + cnt - map.get(cur));
                    }
                    g[i] = Math.min(g[i], f[i][xor]);
                }
            }
        }
        return f[k - 1][0];
    }
};