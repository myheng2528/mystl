//
// Created by myheng2528 on 24-8-1.
//
#include "mystl.h"
void testStack() {
    mystl::stack<int> s;

    // 插入元素
    s.push(1);
    s.push(2);
    s.push(3);

    // 输出并移除元素
    std::cout << "Stack elements (top to bottom): ";
    while (!s.empty()) {
        std::cout << s.top() << " ";
        s.pop();
    }
    std::cout << std::endl;
}

void testQueue() {
    mystl::queue<int> q;

    // 插入元素
    q.push(1);
    q.push(2);
    q.push(3);

    // 输出并移除元素
    std::cout << "Queue elements (front to back): ";
    while (!q.empty()) {
        std::cout << q.front() << " ";
        q.pop();
    }
    std::cout << std::endl;
}