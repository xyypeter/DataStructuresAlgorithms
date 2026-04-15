#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

// 定义单链表节点结构
struct ListNode {
    int val;         // 节点存储的值
    ListNode* next;  // 指向下一个节点的指针
    ListNode(int x) :val(x), next(nullptr) {} // 构造函数，初始化值和将next置为空
};

// 反转链表的迭代法实现类
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        // 初始化两个指针：prev指向前一个节点（初始为nullptr），curr指向当前节点（初始为head）
        ListNode* prev = nullptr;
        ListNode* curr = head;

        // 遍历链表，直到当前节点为空（即到达链表尾部）
        while (curr != nullptr) {
            // 临时保存当前节点的下一个节点，防止丢失后续链表
            ListNode* temp = curr->next;

            // 反转指针：将当前节点的next指向前一个节点（实现反转）
            curr->next = prev;

            // 移动prev和curr指针，为下一次迭代做准备
            prev = curr; // prev移到当前节点
            curr = temp; // curr移到之前保存的下一个节点
        }

        // 循环结束后，prev指向原链表的最后一个节点（即反转后的新头节点）
        return prev;
    }
};

// 测试链表反转的主函数
int main() {
    // 创建测试链表：1->2->3->4->5->nullptr
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    // 创建Solution对象
    Solution sol;
    // 调用反转链表方法，得到反转后的链表头节点
    ListNode* reversed = sol.reverseList(head);

    // 遍历并打印反转后的链表
    ListNode* p = reversed;
    while (p != nullptr) {
        cout << p->val;
        if (p->next != nullptr) {
            cout << "->"; // 只在节点之间打印箭头
        }
        p = p->next;
    }
    cout << endl;

    return 0;
}