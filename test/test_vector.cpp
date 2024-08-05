//
// Created by myheng2528 on 24-7-23.
//
#include "mystl.h"
using namespace mystl;
template <typename T>
void TestVector() {
    // 测试默认构造函数
    vector<T> v1;
    assert(v1.size() == 0);
    assert(v1.empty());

    // 测试带大小和初始值的构造函数
    vector<T> v2(static_cast<size_t>(5), T(10));
    assert(v2.size() == 5);
    for (size_t i = 0; i < v2.size(); ++i) {
        assert(v2[i] == T(10));
    }

    // 测试迭代器构造函数
    vector<T> v3(v2.begin(), v2.end());
    assert(v3.size() == 5);
    for (size_t i = 0; i < v3.size(); ++i) {
        assert(v3[i] == T(10));
    }

    // 测试拷贝构造函数
    vector<T> v4(v3);
    assert(v4.size() == v3.size());
    for (size_t i = 0; i < v4.size(); ++i) {
        assert(v4[i] == v3[i]);
    }

    // 测试赋值操作符
    vector<T> v5;
    v5 = v4;
    assert(v5.size() == v4.size());
    for (size_t i = 0; i < v5.size(); ++i) {
        assert(v5[i] == v4[i]);
    }

    // 测试 push_back 和 pop_back
    vector<T> v6;
    v6.push_back(T(20));
    v6.push_back(T(30));
    assert(v6.size() == 2);
    assert(v6[0] == T(20));
    assert(v6[1] == T(30));
    v6.pop_back();
    assert(v6.size() == 1);
    assert(v6[0] == T(20));

    // 测试 insert
    v6.insert(v6.begin(), T(10));
    assert(v6.size() == 2);
    assert(v6[0] == T(10));
    assert(v6[1] == T(20));

    // 测试 erase
    v6.erase(v6.begin());
    assert(v6.size() == 1);
    assert(v6[0] == T(20));

    // 测试 swap
    v1.push_back(T(40));
    v6.swap(v1);
    assert(v1.size() == 1);
    assert(v1[0] == T(20));
    assert(v6.size() == 1);
    assert(v6[0] == T(40));

    // 测试迭代器
    vector<T> v7(static_cast<size_t>(3), T(50));
    typename vector<T>::iterator it = v7.begin();
    typename vector<T>::const_iterator cit = v7.begin();
    assert(it == cit);
    for (; it != v7.end(); ++it) {
        assert(*it == T(50));
    }

    // 测试 reserve 和 capacity
    v7.reserve(10);
    assert(v7.capacity() >= 10);

    // 测试 resize
    v7.resize(5, T(60));
    assert(v7.size() == 5);
    assert(v7[2] == T(50)); // 之前的值
    assert(v7[4] == T(60)); // 新分配的值

    std::cout << "All tests passed!" << std::endl;
}