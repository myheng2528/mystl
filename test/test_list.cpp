//
// Created by myheng2528 on 24-7-31.
//


#include "mystl.h"
using namespace mystl;
void test_list() {
    // 测试构造函数
    list<int> lst1;
    std::cout << "Default constructor passed: " << (lst1.empty() ? "Yes" : "No") << std::endl;

    // 测试插入
    lst1.push_back(10);
    lst1.push_back(20);
    lst1.push_back(30);
    std::cout << "Push back passed: ";
    for (auto it = lst1.begin(); it != lst1.end(); ++it) {
        std::cout << *it << ' ';
    }
    std::cout << std::endl;

    // 测试front和back
    std::cout << "Front: " << lst1.front() << std::endl; // 应输出10
    std::cout << "Back: " << lst1.back() << std::endl; // 应输出30

    // 测试大小相关函数
    std::cout << "Size: " << lst1.size() << std::endl; // 应输出3

    // 测试复制构造函数
    list<int> lst2(lst1);
    std::cout << "Copy constructor passed: ";
    for (auto it = lst2.begin(); it != lst2.end(); ++it) {
        std::cout << *it << ' ';
    }
    std::cout << std::endl;

    // 测试赋值运算符
    list<int> lst3;
    lst3=lst1;
    std::cout << "Assignment operator passed: ";
    for (auto it = lst3.begin(); it != lst3.end(); ++it) {
        std::cout << *it << ' ';
    }
    std::cout << std::endl;

    // 测试插入和删除
    auto it = lst1.begin();
    ++it;
    lst1.insert(it, 15); // 在第二个位置插入15
    std::cout << "Insert passed: ";
    for (auto it = lst1.begin(); it != lst1.end(); ++it) {
        std::cout << *it << ' ';
    }
    std::cout << std::endl;

    it = lst1.begin();
    ++it;
    lst1.erase(it); // 删除第二个元素
    std::cout << "Erase passed: ";
    for (auto it = lst1.begin(); it != lst1.end(); ++it) {
        std::cout << *it << ' ';
    }
    std::cout << std::endl;

    // 测试push_front和pop_front
    lst1.push_front(5);
    std::cout << "Push front passed: ";
    for (auto it = lst1.begin(); it != lst1.end(); ++it) {
        std::cout << *it << ' ';
    }
    std::cout << std::endl;

    lst1.pop_front();
    std::cout << "Pop front passed: ";
    for (auto it = lst1.begin(); it != lst1.end(); ++it) {
        std::cout << *it << ' ';
    }
    std::cout << std::endl;

    // 测试push_back和pop_back
    lst1.push_back(20);
    std::cout << "Push back passed: ";
    for (auto it = lst1.begin(); it != lst1.end(); ++it) {
        std::cout << *it << ' ';
    }
    std::cout << std::endl;

    lst1.pop_back();
    std::cout << "Pop back passed: ";
    for (auto it = lst1.begin(); it != lst1.end(); ++it) {
        std::cout << *it << ' ';
    }
    std::cout << std::endl;

    // 清除列表
    lst1.clear();
    std::cout << "Clear passed: List is" << (lst1.empty() ? " empty" : " not empty") << std::endl;

    // 测试交换
    list<int> lst4 = {5, 10, 15, 20};
    lst1.swap(lst4);
    std::cout << "Swap passed: lst1 contains: ";
    for (auto it = lst1.begin(); it != lst1.end(); ++it) {
        std::cout << *it << ' ';
    }
    std::cout << std::endl;
    std::cout << " and lst4 contains: ";
    for (auto it = lst4.begin(); it != lst4.end(); ++it) {
        std::cout << *it << ' ';
    }
    std::cout << std::endl;
}