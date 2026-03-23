#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() :val(0), next(nullptr) {}
    ListNode(int x) :val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) :val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* dummyHead = new ListNode(0);
        dummyHead->next = head;
        ListNode* curr = dummyHead;
        while (curr->next != nullptr) {
            if (curr->next->val == val) {
                ListNode* tmp = curr->next;
                curr->next = tmp->next;
                delete tmp;  // 释放内存
            }
            else {
                curr = curr->next;
            }
        }
        ListNode* result = dummyHead->next;
        delete dummyHead;   // 优化项(注意细节)
        return result;
    }
};

// 打印链表
void printList(ListNode* head) {
    ListNode* curr = head;
    while (curr != nullptr) {
        cout << curr->val;
        if (curr->next != nullptr) cout << " -> ";
        curr = curr->next;
    }
    cout << endl;
}

int main() {
    ListNode* list = new ListNode(1);
    list->next = new ListNode(2);
    list->next->next = new ListNode(6);
    list->next->next->next = new ListNode(3);
    list->next->next->next->next = new ListNode(4);
    list->next->next->next->next->next = new ListNode(5);
    list->next->next->next->next->next->next = new ListNode(6);

    Solution s;
    ListNode* result = s.removeElements(list, 6);

    // 打印结果
    cout << "Result: ";
    printList(result);

    return 0;
}
