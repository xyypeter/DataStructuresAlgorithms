#include <iostream>
using namespace std;

class MyLinkedList {
public:
    //定义链表的节点的结构体
    struct ListNode {
        int val;
        ListNode* next;
        ListNode() :val(0), next(nullptr) {}
        ListNode(int x) :val(x), next(nullptr) {}
        ListNode(int x, ListNode* next) :val(x), next(next) {}
    };
    //初始化链表
    MyLinkedList() {
        m_size = 0;
        m_dummyHead = new ListNode(0);//定义虚拟头结点
    }
    //获取第index节点的数值，如果
    int get(int index) {
        if (index > (m_size - 1) || index < 0) return -1;
        ListNode* curr = m_dummyHead->next;
        while (index--) {
            curr = curr->next;
        }
        return curr->val;
    }
    //头部插入节点
    void addAtHead(int val) {
        ListNode* newNode = new ListNode(val);
        newNode->next = m_dummyHead->next;
        m_dummyHead->next = newNode;
        m_size++;
    }
    //尾部插入节点
    void addAtTail(int val) {
        ListNode* newNode = new ListNode(val);
        ListNode* curr = m_dummyHead;
        while (curr->next != nullptr) {
            curr = curr->next;
        }
        curr->next = newNode;
        m_size++;
    }
    // 第n个节点插入节点
    // 在第index个节点之前插入一个新节点，例如index为0，那么新插入的节点为链表的新头节点。
    // 如果index 等于链表的长度，则说明是新插入的节点为链表的尾结点
    // 如果index大于链表的长度，则返回空
    // 如果index小于0，则在头部插入节点
    void addAtIndex(int index, int val) {
        if (index > m_size) return;
        if (index < 0)index = 0;
        ListNode* newNode = new ListNode(val);
        ListNode* curr = m_dummyHead;
        while (index--) {
            curr = curr->next;
        }
        newNode->next = curr->next;
        curr->next = newNode;
        m_size++;
    }
    //删除第n个节点
    // 删除第index个节点，如果index 大于等于链表的长度，直接return，注意index是从0开始的
    void deleteAtIndex(int index) {
        if (index >= m_size || index < 0) {
            return;
        }
        ListNode* curr = m_dummyHead;
        while (index--) {
            curr = curr->next;
        }
        ListNode* tmp = curr->next;
        curr->next = tmp->next;
        delete tmp;
        tmp = nullptr;
        m_size--;
    }

    //打印链表
    void PrintList() {
        ListNode* curr = m_dummyHead->next;
        while (curr != nullptr) {
            cout << curr->val << "->";
            curr = curr->next;
        }
        cout << endl;
    }

private:
    int m_size;
    ListNode* m_dummyHead;
};

int main()
{
    MyLinkedList list;

    cout << "=== 测试头插 ===" << endl;
    list.addAtHead(1);
    list.addAtHead(2);
    list.addAtHead(3);   // 3->2->1
    list.PrintList();

    cout << "=== 测试尾插 ===" << endl;
    list.addAtTail(4);
    list.addAtTail(5);   // 3->2->1->4->5
    list.PrintList();

    cout << "=== 测试 get ===" << endl;
    cout << "index 0: " << list.get(0) << endl; // 3
    cout << "index 2: " << list.get(2) << endl; // 1
    cout << "index 10: " << list.get(10) << endl; // -1

    cout << "=== 测试按索引插入 ===" << endl;
    list.addAtIndex(2, 99); // 插入到 index=2
    list.PrintList();       // 3->2->99->1->4->5

    list.addAtIndex(0, 100); // 头部插入
    list.PrintList();        // 100->3->2->99->1->4->5

    cout << "=== 测试删除 ===" << endl;
    list.deleteAtIndex(0); // 删除头
    list.PrintList();

    list.deleteAtIndex(2); // 删除中间
    list.PrintList();

    list.deleteAtIndex(10); // 无效删除
    list.PrintList();

    return 0;
}


