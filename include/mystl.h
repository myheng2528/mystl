//
// Created by myheng2528 on 24-7-17.
//

#ifndef PROJECT_MYSTL_H
#define PROJECT_MYSTL_H
#include <iostream>
#include <initializer_list>
#include <deque>
#include <assert.h>
#include <algorithm>
namespace mystl
{
    //模拟实现string类
    class string
    {
    public:
        typedef char* iterator;
        typedef const char* const_iterator;

        //默认成员函数
        explicit string(const char* str = "");         //构造函数
        string(const string& s);              //拷贝构造函数
        string& operator=(const string& s);   //赋值运算符重载函数
        ~string();                            //析构函数

        //迭代器相关函数
        iterator begin();
        iterator end();
        const_iterator begin()const;
        const_iterator end()const;
        void reverse();

        //容量和大小相关函数
        size_t size();
        size_t capacity();
        void reserve(size_t n);
        void resize(size_t n, char ch = '\0');
        bool empty()const;

        //修改字符串相关函数
        void push_back(char ch);
        void append(const char* str);
        string& operator+=(char ch);
        string& operator+=(const char* str);
        string& insert(size_t pos, char ch);
        string& insert(size_t pos, const char* str);
        string& erase(size_t pos, size_t len);
        void clear();
        void swap(string& s);
        const char* c_str()const;

        //访问字符串相关函数
        char& operator[](size_t i);
        const char& operator[](size_t i)const;
        size_t find(char ch, size_t pos = 0)const;
        size_t find(const char* str, size_t pos = 0)const;
        size_t rfind(char ch, size_t pos = npos)const;
        size_t rfind(const char* str, size_t pos = npos)const;

        //关系运算符重载函数
        bool operator>(const string& s)const;
        bool operator>=(const string& s)const;
        bool operator<(const string& s)const;
        bool operator<=(const string& s)const;
        bool operator==(const string& s)const;
        bool operator!=(const string& s)const;
        bool operator>(const char* s)const;
        bool operator>=(const char* s)const;
        bool operator<(const char* s)const;
        bool operator<=(const char* s)const;
        bool operator==(const char* s)const;
        bool operator!=(const char* s)const;
    private:
        char* _str;       //存储字符串
        size_t _size;     //记录字符串当前的有效长度
        size_t _capacity; //记录字符串当前的容量
        static const size_t npos=-1; //静态成员变量（整型最大值）
    };

    std::istream& operator>>(std::istream& in, string& s);
    std::ostream& operator<<(std::ostream& out, const string& s);
    std::istream& getline(std::istream& in, string& s);


    template<class T>
    class vector
    {
    public:
        typedef T* iterator;
        typedef const T* const_iterator;

        //默认成员函数
        vector();
        vector(size_t n, const T& val);
        template<class InputIterator>
        vector(InputIterator first, InputIterator last);
        vector(const vector<T>& v);
        vector<T>& operator=(const vector<T>& v);
        ~vector();
        //迭代器相关
        iterator begin();
        iterator end();
        const_iterator begin() const;
        const_iterator end() const;
        //容器大小相关
        size_t size() const;
        size_t capacity() const;
        void reserve(size_t n);
        void resize(size_t n, const T& val= T());
        bool empty() const;
        //修改内容
        void push_back(const T& x);
        void pop_back();
        void insert(iterator pos, const T& x);
        iterator erase(iterator pos);
        void swap(vector<T>& v);
        //访问内容
        T& operator[](size_t i);
        const T& operator[](size_t i) const;
    private:
        iterator _start;
        iterator _finish;
        iterator _endofstorage;
    };

    template<class T>
    vector<T>::vector()
            :_start(nullptr),
             _finish(nullptr),
             _endofstorage(nullptr)
    {}

    template<class T>
    vector<T>::vector(size_t n, const T& val)
            :_start(nullptr),
             _finish(nullptr),
             _endofstorage(nullptr)
    {
        reserve(n);
        _finish=_start+n;
        iterator begin = _start;
        while (begin<_finish){
            *begin=val;
            begin++;
        }
    }
    template<class T>
    template<class InputIterator>
    vector<T>::vector(InputIterator first, InputIterator last)
            :_start(nullptr),
             _finish(nullptr),
             _endofstorage(nullptr)
    {
        size_t len = last-first;
        reserve(len);
        _finish=_start+len;
        iterator begin = _start;
        while (begin!=_finish){
            *begin=*first;
            begin++;
            first++;
        }

    }
    template<class T>
    vector<T>::vector(const vector<T>& v)
            :_start(nullptr),
             _finish(nullptr),
             _endofstorage(nullptr)
    {
        vector<T> tmp(v._start,v._finish);
        swap(tmp);

    }
    template<class T>
    vector<T>& vector<T>::operator=(const vector<T>& v)
    {
        vector<T> tmp(v);
        swap(tmp);
        return *this;
    }
    template<class T>
    vector<T>::~vector()
    {
        delete[] _start;
        _start= nullptr;
        _finish= nullptr;
        _endofstorage= nullptr;
    }

    template<class T>
    typename vector<T>::iterator vector<T>::begin(){
        return _start;
    }
    template<class T>
    typename vector<T>::iterator vector<T>::end()
    {
        return _finish;
    }
    template<class T>
    typename vector<T>::const_iterator vector<T>::begin() const
    {
        return _start;
    }
    template<class T>
    typename vector<T>::const_iterator vector<T>::end() const
    {
        return _finish;
    }

    template<class T>
    size_t vector<T>::size() const
    {
        return _finish-_start;
    }
    template<class T>
    size_t vector<T>::capacity() const
    {
        return _endofstorage-_start;
    }
    template<class T>
    void vector<T>::reserve(size_t n)
    {
        if (n>capacity()){
            size_t len = size();
            T* tmp = new T[n];
            if (_start){
                for (int i = 0; i < len; ++i) {
                    tmp[i]=_start[i];
                }
                delete[] _start;
            }
            _start=tmp;
            _finish=_start+len;
            _endofstorage=_start+n;
        }
    }
    template<class T>
    void vector<T>::resize(size_t n,const T& val)
    {
        if (n<size()){
            _finish=_start+n;
        } else{
            if (n>capacity()){
                reserve(n);
            }

            while (_finish<_start+n){
                *_finish=val;
                _finish++;
            }
        }
    }
    template<class T>
    bool vector<T>::empty() const
    {
        return _start==_finish;
    }
    template<class T>
    void vector<T>::push_back(const T& x)
    {
        if (size()+1>capacity()){
            reserve(capacity()==0?4:2*capacity());
        }
        *_finish=x;
        _finish++;
    }
    template<class T>
    void vector<T>::pop_back()
    {
        assert(!empty());
        _finish--;
    }
    template<class T>
    void vector<T>::insert(iterator pos, const T& x)
    {
        assert(pos>=_start&&pos<=_finish);
        if (_finish==_endofstorage){
            reserve(capacity()==0?4:2*capacity());
        }
        iterator end = _finish;
        while (end>=pos){
            *(end+1)=*end;
            end--;
        }
        *pos=x;
        _finish++;
    }
    template<class T>
    typename vector<T>::iterator vector<T>::erase(iterator pos)
    {
        assert(pos>=_start&&pos<_finish);
        iterator abc = pos;
        while (pos<_finish){
            *pos=*(pos+1);
            pos++;
        }
        _finish--;
        return abc;
    }
    template<class T>
    void vector<T>::swap(vector<T>& v)
    {
        std::swap(_start,v._start);
        std::swap(_finish,v._finish);
        std::swap(_endofstorage,v._endofstorage);
    }
    template<class T>
    T& vector<T>::operator[](size_t i)
    {
        assert(i<size());
        return _start[i];
    }
    template<class T>
    const T& vector<T>::operator[](size_t i) const
    {
        assert(i<size());
        return _start[i];
    };


    //list
    template<class T>
    class _list_node
    {
    public:
        explicit _list_node(const T& val=T());
        T _val;
        _list_node<T>* _next;
        _list_node<T>* _prev;
    };
    template<class T>
    _list_node<T>::_list_node(const T &val)
        :_val(val),
         _next(nullptr),
         _prev(nullptr)
    {}
    template<class T,class Ref,class Ptr>
    class _list_iterator
    {
    public:
        typedef _list_node<T> node;
        typedef _list_iterator<T,Ref,Ptr> self;
        explicit _list_iterator(node* pnode);
        self operator++();
        self operator--();
        self operator++(int);
        self operator--(int);
        Ref operator*();
        Ptr operator->();
        bool operator==(self it);
        bool operator!=(self it);
        node* _pnode;
    };

    template<class T,class Ref,class Ptr>
    _list_iterator<T,Ref,Ptr>::_list_iterator(node* pnode)
    :_pnode(pnode)
    {}
    template<class T,class Ref,class Ptr>
    typename _list_iterator<T,Ref,Ptr>::self _list_iterator<T, Ref, Ptr>::operator++()
    {
        _pnode=_pnode->_next;
        return *this;
    }
    template<class T,class Ref,class Ptr>
    typename _list_iterator<T,Ref,Ptr>::self _list_iterator<T, Ref, Ptr>::operator--()
    {
        _pnode=_pnode->_prev;
        return *this;
    }
    template<class T,class Ref,class Ptr>
    typename _list_iterator<T,Ref,Ptr>::self _list_iterator<T, Ref, Ptr>::operator++(int)
    {
        self tmp(_pnode);
        _pnode=_pnode->_next;
        return tmp;
    }
    template<class T,class Ref,class Ptr>
    typename _list_iterator<T,Ref,Ptr>::self _list_iterator<T, Ref, Ptr>::operator--(int)
    {
        self tmp(_pnode);
        _pnode=_pnode->_prev;
        return tmp;
    }
    template<class T,class Ref,class Ptr>
    bool _list_iterator<T, Ref, Ptr>::operator==(self it)
    {
        return _pnode==it._pnode;
    }
    template<class T,class Ref,class Ptr>
    bool _list_iterator<T, Ref, Ptr>::operator!=(self it)
    {
        return _pnode!=it._pnode;
    }
    template<class T,class Ref,class Ptr>
    Ref _list_iterator<T,Ref,Ptr>::operator*()
    {
        return _pnode->_val;
    }
    template<class T,class Ref,class Ptr>
    Ptr _list_iterator<T,Ref,Ptr>::operator->()
    {
        return &(_pnode->_val);
    }


    template<class T>
    class list
    {
        typedef _list_node<T> node;
        typedef _list_iterator<T, T&, T*> iterator;
        typedef _list_iterator<T, const T&, const T*> const_iterator;
    public:
        //默认成员函数
        list();
        list(const list<T>& lt);
        list<T>& operator=(list<T> lt);
        list(std::initializer_list<T> il);
        ~list();
        //迭代器相关函数
        iterator begin();
        const_iterator begin() const;
        iterator end();
        const_iterator end() const;
        //容器大小相关
        size_t size() const;
        void resize(size_t n, const T& val=T());
        bool empty() const;
        void clear();
        void swap(list<T>& lt);
        //访问容器相关函数
        const T& front() const;
        T& front() ;
        const T& back() const;
        T& back() ;
        //插入和删除相关函数
        void insert(iterator pos,const T& val=T());
        iterator erase(iterator pos);
        void push_back(const T& x);
        void push_front(const T& x);
        void pop_back();
        void pop_front();
    private:
        node* _head;
    };
    template<class T>
    list<T>::list()
    {
        _head = new node;
        _head->_prev=_head;
        _head->_next=_head;
    }
    template<class T>
    list<T>::list(const list<T>& ls)
    {
        _head = new node;
        _head->_prev=_head;
        _head->_next=_head;
        for(auto e:ls){
            push_back(e);
        }
    }
    template<class T>
    list<T>::list(std::initializer_list<T> il)
    {
        _head = new node;
        _head->_prev=_head;
        _head->_next=_head;
        for (auto e:il){
            push_back(e);
        }
    }
    template<class T>
    list<T>& list<T>::operator=(list<T> lt)
    {
        swap(lt);
        return *this;
    }
    template<class T>
    list<T>::~list()
    {
        clear();
        delete _head;
        _head=nullptr;
    }
    template<class T>
    typename list<T>::iterator list<T>::begin()
    {
        return iterator(_head->_next);
    }
    template<class T>
    typename list<T>::const_iterator list<T>::begin() const
    {
        return const_iterator(_head->_next);
    }
    template<class T>
    typename list<T>::iterator list<T>::end()
    {
        return iterator(_head);
    }
    template<class T>
    typename list<T>::const_iterator list<T>::end() const
    {
        return const_iterator(_head);
    }
    template<class T>
    size_t list<T>::size() const
    {
        size_t count=0;
        const_iterator start = begin();
        const_iterator finish = end();
        while (start!=finish){
            count++;
            start++;
        }
        return count;
    }
    template<class T>
    void list<T>::resize(size_t n, const T& val)
    {
        auto i = begin();
        int len = 0;
        while (len<n&&i!=end()){
            len++;
            i++;
        }
        if (len==n){
            while (i!=end())
            {
                i=erase(i);
            }
        }else{
            while (len<n){
                push_back(val);
            }
        }
    }
    template<class T>
    bool list<T>::empty() const
    {
        return begin()==end();
    }
    template<class T>
    void list<T>::clear()
    {
        auto i = begin();
        while (i!=end()){
            i= erase(i);
        }
    }
    template<class T>
    void list<T>::swap(list<T>& lt)
    {
        std::swap(_head,lt._head);
    }

    //访问函数
    template<class T>
    const T& list<T>::front() const
    {
        return _head->_next->_val;
    }
    template<class T>
    T& list<T>::front(){
        return _head->_next->_val;
    }
    template<class T>
    const T& list<T>::back() const
    {
        return _head->_prev->_val;
    }
    template<class T>
    T& list<T>::back()
    {
        return _head->_prev->_val;
    }
    //修改容器相关的函数
    template<class T>
    void list<T>::insert(iterator pos,const T& val)
    {   node* tmp = new node(val);
        auto cur = pos._pnode;
        auto prev = cur->_prev;
        prev->_next=tmp;
        tmp->_prev=prev;
        tmp->_next=cur;
        cur->_prev=tmp;
    }
    template<class T>
    typename list<T>::iterator list<T>::erase(iterator pos)
    {
        auto cur = pos._pnode;
        auto next = pos._pnode->_next;
        auto prev = pos._pnode->_prev;
        prev->_next=next;
        next->_prev=prev;
        delete cur;
        return iterator(next);
    }
    template<class T>
    void list<T>::push_back(const T& x)
    {
        insert(end(),x);
    }
    template<class T>
    void list<T>::push_front(const T& x)
    {
        insert(begin(),x);
    }
    template<class T>
    void list<T>::pop_back()
    {
        auto it = end();
        it++;
        erase(it);
    }
    template<class T>
    void list<T>::pop_front()
    {
        erase(begin());
    }

    template<class T, class Container = std::deque<T>>
    class stack
    {
    public:
        //元素入栈
        void push(const T& x)
        {
            _con.push_back(x);
        }
        //元素出栈
        void pop()
        {
            _con.pop_back();
        }
        //获取栈顶元素
        T& top()
        {
            return _con.back();
        }
        const T& top() const
        {
            return _con.back();
        }
        //获取栈中有效元素个数
        size_t size() const
        {
            return _con.size();
        }
        //判断栈是否为空
        bool empty() const
        {
            return _con.empty();
        }
        //交换两个栈中的数据
        void swap(stack<T, Container>& st)
        {
            _con.swap(st._con);
        }
    private:
        Container _con;
    };
    template<class T, class Container = std::deque<T>>
    class queue
    {
    public:
        //队尾入队列
        void push(const T& x)
        {
            _con.push_back(x);
        }
        //队头出队列
        void pop()
        {
            _con.pop_front();
        }
        //获取队头元素
        T& front()
        {
            return _con.front();
        }
        const T& front() const
        {
            return _con.front();
        }
        //获取队尾元素
        T& back()
        {
            return _con.back();
        }
        const T& back() const
        {
            return _con.back();
        }
        //获取队列中有效元素个数
        size_t size() const
        {
            return _con.size();
        }
        //判断队列是否为空
        bool empty() const
        {
            return _con.empty();
        }
        //交换两个队列中的数据
        void swap(queue<T, Container>& q)
        {
            _con.swap(q._con);
        }
    private:
        Container _con;
    };

    template<class T>
    struct less
    {
        bool operator()(const T& x, const T& y){
            return x<y;
        }
    };
    template<class T>
    struct greater
    {
        bool operator()(const T& x, const T& y){
            return x>y;
        }
    };
    template<class T,class Container = vector<T>,class Compare = less<T>>
    class priority_queue
    {
    public:
        void AdjustUp(int child)
        {
            int parent = (child - 1)/2;

            while (child>0)
            {
                if (_comp(_con[parent],_con[child])){
                    std::swap(_con[parent],_con[child]);
                    child=parent;
                    parent=(child - 1)/2;
                } else{
                    break;
                }
            }
        }
        void AdjustDown(int n, int parent)
        {
            int child = parent*2+1;
            while (child<n)
            {
                if (child+1<n&&_comp(_con[child],_con[child+1])) child++;
                if (_comp(_con[parent],_con[child])){
                    std::swap(_con[parent],_con[child]);
                    parent=child;
                    child=parent*2+1;
                } else{
                    break;
                }

            }
        }
        void push(const T& x)
        {
            _con.push_back(x);
            AdjustUp(_con.size()-1);
        }
        void pop()
        {
            std::swap(_con[0],_con[_con.size()-1]);
            _con.pop_back();
            AdjustDown(size(),0);
        }
        T& top()
        {
            return _con[0];
        }
        const T& top() const
        {
            return _con[0];
        }
        int size()
        {
            return _con.size();
        }
        bool empty()
        {
            return _con.empty();
        }
        Container _con;
        Compare _comp;
    };

}


#endif //PROJECT_MYSTL_H
