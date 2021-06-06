/*203.移除链表元素
给你一个链表的头节点 head 和一个整数 val ，请你删除链表中所有满足 Node.val == val 的节点，并返回 新的头节点 。

思路：简单双指针。从头遍历链表，记录上个节点pre，如果cur节点值和指定值相同，则将pre指向cur下一位并删除cur。
*/

#include"all_in.h"

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* new_head =new ListNode(-1), * cur;
        new_head->next = head;
        cur = new_head;
        while (cur->next != nullptr) {
            if (cur->next->val == val) {
                cur->next = cur->next->next;
            }
            else cur = cur->next;
        }
        return new_head->next;
    }
};