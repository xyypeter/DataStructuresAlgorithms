#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

// 定义LRU缓存类
class LRUCache {
    // 定义双链表的节点结构
    struct Node {
        int key;
        int value;
        Node* prev;
        Node* next;
        // 构造函数初始化节点
        Node(int key, int value) :key(key), value(value), prev(nullptr), next(nullptr) {}
    };

    Node* head; // 虚拟头结点（不存储实际数据，用于简化链表操作）
    Node* tail; // 虚拟尾结点（同上）

    // 将节点加入到链表头部（虚拟头结点之后）
    void addToHead(Node* node) {
        // 将新节点的next指向原第一个真实节点
        node->next = head->next;
        // 将新节点的prev指向虚拟头结点
        node->prev = head;
        // 将原第一个真实节点的prev指向新节点
        head->next->prev = node;
        // 将虚拟头结点的next指向新节点
        head->next = node;
    }

    // 从链表中删除指定的节点
    void removeNode(Node* node) {
        // 将前驱节点的next指向当前节点的下一个节点
        node->prev->next = node->next;
        // 将后继节点的prev指向当前节点的上一个节点
        node->next->prev = node->prev;
    }

    // 将节点移动到链表头部（表示最近被访问过）
    void moveToHead(Node* node) {
        removeNode(node); // 先从链表中移除
        addToHead(node);  // 再插入到头部
    }

    // 删除链表尾部的节点（即最久未使用的节点）
    Node* removeTail() {
        // 获取尾部的前一个节点（即最后一个有效节点）
        Node* node = tail->prev;
        removeNode(node); // 将其从链表移除
        return node;      // 返回该节点，供后续释放内存和删除哈希表项
    }

private:
    int capatity;                   // LRU缓存的容量
    unordered_map<int, Node*> cache; // 哈希表：通过键快速定位到链表中的节点

public:
    // 构造函数，初始化缓存容量和双向链表
    LRUCache(int capatity) :capatity(capatity) {
        // 创建虚拟头尾节点，方便处理边界情况
        head = new Node(0, 0);
        tail = new Node(0, 0);
        // 初始状态：头尾相连
        head->next = tail;
        tail->prev = head;
    }

    // 向缓存中添加或更新键值对
    void put(int key, int value) {
        if (cache.count(key)) {
            // 键已存在：更新值，并将其移至头部（标记为最近使用）
            Node* node = cache[key];
            node->value = value;
            moveToHead(node);
        }
        else {
            // 键不存在：创建新节点
            Node* node = new Node(key, value);
            // 将新节点加入哈希表和链表头部
            cache[key] = node;
            addToHead(node);

            // 如果缓存大小超过容量，需淘汰最久未使用的节点（尾部节点）
            if (cache.size() > capatity) {
                Node* tailNode = removeTail(); // 从链表删除
                cache.erase(tailNode->key);    // 从哈希表删除
                delete tailNode;               // 释放节点内存
            }
        }
    }

    // 根据键获取值
    int get(int key) {
        if (cache.count(key)) {
            // 命中缓存：将节点移至头部并返回值
            Node* node = cache[key];
            moveToHead(node);
            return node->value;
        }
        else {
            // 未找到键
            return -1;
        }
    }
};

// 测试主函数
int main() {
    LRUCache lru(2);            // 创建容量为2的LRU缓存

    lru.put(1, 1);             // 缓存: [1]
    lru.put(2, 2);             // 缓存: [2, 1]

    cout << lru.get(1) << endl; // 1 -> 访问1，变为最近使用，缓存: [1, 2]

    lru.put(3, 3);              // 插入3 -> 淘汰2，缓存: [3, 1]
    cout << lru.get(2) << endl; // -1 (2已被淘汰)

    lru.put(4, 4);              // 插入4 -> 淘汰1，缓存: [4, 3]
    cout << lru.get(1) << endl; // -1 (1已被淘汰)
    cout << lru.get(3) << endl; // 3 -> 缓存: [3, 4]
    cout << lru.get(4) << endl; // 4 -> 缓存: [4, 3]

    return 0;
}