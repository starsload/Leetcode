/*203.�Ƴ�����Ԫ��
����һ�������ͷ�ڵ� head ��һ������ val ������ɾ���������������� Node.val == val �Ľڵ㣬������ �µ�ͷ�ڵ� ��

˼·����˫ָ�롣��ͷ����������¼�ϸ��ڵ�pre�����cur�ڵ�ֵ��ָ��ֵ��ͬ����preָ��cur��һλ��ɾ��cur��
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