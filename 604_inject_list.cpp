/*给你两个单链表的头节点 headA 和 headB ，请你找出并返回两个单链表相交的起始节点。如果两个链表没有交点，返回 null 。

图示两个链表在节点 c1 开始相交：



题目数据 保证 整个链式结构中不存在环。

注意，函数返回结果后，链表必须 保持其原始结构 。

 

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/intersection-of-two-linked-lists
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

思路：很简单的相交链表问题，双指针即可解决。题目中已经说了无环，这是好事.
      这里我们用双指针方式进行解答。
      每步操作需要同时更新指针 pA 和 pB；

      如果指针 pA 不为空，则将指针 pA 移到下一个节点；如果指针 }pB 不为空，则将指针 pB 移到下一个节点。
      如果指针 pA 为空，则将指针 pA 移到链表 headB 的头节点；如果指针 pB 为空，则将指针 pB 移到链表 headA 的头节点。
      当指针 pA 和 }pB 指向同一个节点或者都为空时，返回它们指向的节点或者 null。

*/

#include"all_in.h"

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        if (headA == nullptr || headB == nullptr) {
            return nullptr;
        }
        ListNode* pa = headA, * pb = headB;
        while (pa != pb) {
            pa = (pa == nullptr) ? headB : pa->next;
            pb = (pb == nullptr) ? headA : pb->next;
        }
        return pa;
    }
};
