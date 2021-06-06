/*给出一个字符串 s（仅含有小写英文字母和括号）。
请你按照从括号内到外的顺序，逐层反转每对匹配括号中的字符串，并返回最终的结果。
注意，您的结果中 不应 包含任何括号。

思路：栈实现，当遇到小写字母时，加入到结果字符串ret中。当我们遇到（，将ret入栈并清空ret，
	  当遇到）时，将栈顶元素弹出并将ret反转后拼在后面重新赋值给ret。重复操作直到遍历完字符串。
*/
#include"all_in.h"

using namespace std;

class Solution {
public:
    string reverseParentheses(string s) {
        string ret = "";
        stack<string> ms;
        int len = s.length();
        for (int i = 0; i < len; i++) {
            if (s[i] == '(') {
                ms.push(ret);
                ret = "";
            }
            else if (s[i] == ')') {
                reverse(ret.begin(), ret.end());
                ret = ms.top() + ret;
                ms.pop();
            }
            else ret += s[i];
        }
        return ret;
    }
};

/*解法二：先处理括号，每遇到括号时就逆向遍历括号内的元素*/
class Solution2 {
public:
    string reverseParentheses(string s) {
        int n = s.length();
        vector<int> pair(n);
        stack<int> stk;
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                stk.push(i);
            }
            else if (s[i] == ')') {
                int j = stk.top();
                stk.pop();
                pair[i] = j, pair[j] = i;
            }
        }

        string ret;
        int index = 0, step = 1;
        while (index < n) {
            if (s[index] == '(' || s[index] == ')') {
                index = pair[index];
                step = -step;
            }
            else {
                ret.push_back(s[index]);
            }
            index += step;
        }
        return ret;
    }
};


