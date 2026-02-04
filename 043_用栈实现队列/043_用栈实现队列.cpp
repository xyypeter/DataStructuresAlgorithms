#include <iostream>
#include <stack>
using namespace std;

class MyQueue {
private:
    stack<int> inStack;   // 负责入队
    stack<int> outStack;  // 负责出队

public:
    MyQueue() {}

    // 将元素 x 推到队列末尾
    void push(int x) {
        inStack.push(x);
    }

    // 从队列开头移除并返回元素
    int pop() {
        // 如果 outStack 为空，把 inStack 的元素倒过来
        if (outStack.empty()) {
            while (!inStack.empty()) {
                outStack.push(inStack.top());
                inStack.pop();
            }
        }
        int res = outStack.top();
        outStack.pop();
        return res;
    }

    // 返回队列开头的元素
    int peek() {
        if (outStack.empty()) {
            while (!inStack.empty()) {
                outStack.push(inStack.top());
                inStack.pop();
            }
        }
        return outStack.top();
    }

    // 判断队列是否为空
    bool empty() {
        return inStack.empty() && outStack.empty();
    }
};

int main() {
    MyQueue q;
    q.push(1);
    q.push(2);
    cout << q.peek() << endl; // 1
    cout << q.pop() << endl;  // 1
    cout << q.empty() << endl; // 0 (false)
    return 0;
}
