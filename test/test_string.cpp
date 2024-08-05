//
// Created by myheng2528 on 24-7-21.
//
#include <iostream>
#include <cassert>
#include "mystl.h"
using namespace mystl;

void test_string()
{
    using std::cout;
    using std::cin;
    using std::endl;
    // 构造函数测试
    string s1("Hello");
    assert(s1 == "Hello");

    // 拷贝构造函数测试
    string s2(s1);
    assert(s2 == "Hello");

    // 赋值运算符重载测试
    string s3 = s1;
    assert(s3 == "Hello");

    // 迭代器相关函数测试
    for(auto it = s1.begin(); it != s1.end(); ++it) {
        cout << *it; // 应该输出 "Hello"
    }
    cout << endl;

    // 反转字符串
    s1.reverse();
    assert(s1 == "olleH");

    // 容量和大小相关函数测试
    assert(s1.size() == 5);
    assert(!s1.empty());

    // 修改字符串相关函数测试
    s1.push_back('!');
    assert(s1 == "olleH!");

    s1.append(" World");
    assert(s1 == "olleH! World");

    s1 += " Rocks";
    assert(s1 == "olleH! World Rocks");

    s1.insert(6, 'Y');
    assert(s1 == "olleH!Y World Rocks");

    s1.erase(6, 1);
    assert(s1 == "olleH! World Rocks");

    s1.clear();
    assert(s1.empty());

    // 访问字符串相关函数测试
    s1 += "HelloWorld";
    assert(s1[0] == 'H');
    assert(s1.find('W') == 5);
    assert(s1.find("World") == 5);
    assert(s1.rfind("o") == 6);

    // 关系运算符重载函数测试
    string s4("Apple");
    string s5("Banana");
    assert(s4 < s5);
    assert(!(s5 < s4));
    assert(s4 != s5);

    // 流操作符测试
    string s6;
    cout << "Enter a string: ";
    cin >> s6;
    cout << "You entered: " << s6 << endl;

    // 测试getline
    cout << "Enter a line: ";
    string s7;
    getline(cin, s7);
    cout << "You entered: " << s7 << endl;

    // 测试 swap 函数
    s1.clear();
    s2.clear();

    s1 += "First";
    s2 += "Second";
    s1.swap(s2);
    assert(s1 == "Second");
    assert(s2 == "First");

    cout << "All tests passed!" << endl;
}


