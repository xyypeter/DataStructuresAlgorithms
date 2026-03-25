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
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummyHead = new ListNode(0);
        dummyHead->next = head;
        ListNode* curr = dummyHead;
        while (curr->next != nullptr && curr->next->next != nullptr) {
            ListNode* tmp1 = curr->next;
            ListNode* tmp2 = curr->next->next->next;
            curr->next = curr->next->next;
            curr->next->next = tmp1;
            curr->next->next->next = tmp2;
            curr = curr->next->next;
        }
        ListNode* result = dummyHead->next;
        delete dummyHead;
        dummyHead = nullptr;
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
    list->next->next = new ListNode(3);
    list->next->next->next = new ListNode(4);
    printList(list);

    Solution s;
    ListNode* result = s.swapPairs(list);

    // 打印结果
    cout << "Result: ";
    printList(result);

    return 0;
}

