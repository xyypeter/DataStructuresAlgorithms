#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        // 递归终止条件：空链表或只有一个节点
        if (!head || !head->next)
            return head;

        // ===== 1. 使用快慢指针找到中点 =====
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = nullptr;

        while (fast && fast->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        // 断开链表，分成两半
        prev->next = nullptr;

        // ===== 2. 递归排序左右两部分 =====
        ListNode* left = sortList(head);
        ListNode* right = sortList(slow);

        // ===== 3. 合并两个有序链表 =====
        return merge(left, right);
    }

private:
    // 合并两个有序链表
    ListNode* merge(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode* tail = &dummy;

        while (l1 && l2) {
            if (l1->val < l2->val) {
                tail->next = l1;
                l1 = l1->next;
            }
            else {
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }

        // 接上剩余部分
        tail->next = l1 ? l1 : l2;
        return dummy.next;
    }
};

int main() {
    // 示例：4 -> 2 -> 1 -> 3
    ListNode* head = new ListNode(4);
    head->next = new ListNode(2);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(3);

    Solution s;
    ListNode* sorted = s.sortList(head);

    while (sorted) {
        cout << sorted->val << " ";
        sorted = sorted->next;
    }
    return 0;
}
