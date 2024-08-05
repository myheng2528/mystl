//
// Created by myheng2528 on 24-7-18.
//
#include <cstring>
#include <cassert>
#include "mystl.h"
//string
using namespace mystl;

string::string(const char* str)
{
    _size = strlen(str);
    _capacity = _size;
    _str = new char[_capacity+1];
    strcpy(_str,str);
}

void string::swap(string& s)
{
    //调用库里的swap
    std::swap(_str, s._str); //交换两个对象的C字符串
    std::swap(_size, s._size); //交换两个对象的大小
    std::swap(_capacity, s._capacity); //交换两个对象的容量
}

string::string(const string& s)
    :_str(nullptr),
    _size(0),
    _capacity(0)
{
    string tmp(s._str);
    swap(tmp);
}
string& string::operator=(const mystl::string &s)
{
    if(this!=&s){
        string tmp(s);
        swap(tmp);
    }
    return *this;
}
string::~string()
{
    delete[] _str;
    _str = nullptr;
    _size = 0;
    _capacity = 0;
}
string::iterator string::begin()
{
    return _str;
}
string::const_iterator string::begin()const
{
    return _str;
}
string::iterator string::end()
{
    return _str+_size;
}

string::const_iterator string::end()const
{
    return _str+_size;
}
size_t string::size()
{
    return _size;
}
size_t string::capacity()
{
    return _capacity;
}
//n<=_capacity什么都不做
//n>_capacity，_capacity扩展到n
void string::reserve(size_t n)
{
    if (n>_capacity){
        char * tmp = new char[n+1];
        ::strncpy(tmp,_str,_size+1);
        delete[] _str;
        _str = tmp;
        _capacity=n;
    }
}
//如果n>capacity,先将capacity扩展到n,然后扩大_size,使用ch填充
void string::resize(size_t n, char ch)
{
    if (n<_size){
        _str[n] = '\0';
        _size = n;
    }else{
        if (n>_capacity){
            reserve(n);
        }
        for (int i = _size; i < n; ++i) {
            _str[i] = ch;
        }
        _size = n;
        _str[_size] = '\0';
    }
}
bool string::empty()const
{
    return strcmp(_str,"")==0;
}
string& string::insert(size_t pos, char ch)
{   assert(pos<=_size);
    if (_size==_capacity){
        reserve(_capacity==0?4:_capacity*2);
    }
    auto end = _str+_size;
    while (end>=_str+pos){
        *(end+1)=*end;
        end--;
    }
    _size++;
    _str[pos]=ch;
    return *this;
}
string& string::insert(size_t pos, const char* str)
{
    assert(pos<=_size);
    int len = strlen(str);
    if (len+_size>_capacity){
        reserve(len+_size);
    }
    char* end = _str+_size;
    while (end>=_str+pos){
        *(end+len)=*end;
        end--;
    }
    strncpy(_str + pos, str, len);
    _size+=len;
    return *this;
}
void string::push_back(char ch)
{
    insert(_size,ch);
}
void string::append(const char* str)
{
    insert(_size,str);
}
string& string::operator+=(char ch)
{
    return insert(_size,ch);
}
string& string::operator+=(const char* str)
{
    return insert(_size,str);
}

string& string::erase(size_t pos, size_t len)
{
    assert(pos<_size);
    int n = _size-pos;
    if (len>=n){
        _str[pos]='\0';
        _size=pos;
    }else{
        for (int i = 0; i <=_size-len; ++i) {
            _str[i+pos]=_str[i+pos+len];
        }
        _size-=len;
    }
    return *this;

}
void string::clear()
{
    _size=0;
    _str[_size]='\0';
}
const char* string::c_str()const
{
    return _str;
}
char& string::operator[](size_t i)
{
    assert(i<_size);
    return _str[i];
}
const char& string::operator[](size_t i)const
{
    assert(i<_size);
    return _str[i];
}
size_t string::find(char ch, size_t pos)const
{
    assert(pos<_size);
    for (int i = pos; i < _size; ++i) {
        if (_str[i]==ch){
            return i;
        }
    }
    return npos;
}
size_t string::find(const char* str, size_t pos)const
{
    assert(pos<_size);
    const char* ret = strstr(_str,str);
    if (ret){
        return ret-_str;
    }else{
        return npos;
    }
}
void string::reverse() {
    iterator a = this->begin();
    iterator b = this->end();
    b--;
    while (a<b){
        std::swap(*a,*b);
        a++;
        b--;
    }
}
//在string中倒序查找第一个字符ch，并返回它的索引
//首先倒置string,复用find函数
size_t string::rfind(char ch, size_t pos)const
{
    string tmp(*this);
    tmp.reverse();
    if (pos>=_size){
        pos=_size-1;
    }
    pos=_size-1-pos;
    int res=tmp.find(pos,ch);
    if (res!=npos){
        return _size-1-res;
    } else{
        return npos;
    }
}
size_t string::rfind(const char* str, size_t pos)const
{
    string tmp(*this);
    tmp.reverse();
    if (pos >= _size) //所给pos大于字符串有效长度
    {
        pos = _size - 1; //重新设置pos为字符串最后一个字符的下标
    }
    pos=_size-1-pos;
    int len = strlen(str);
    char* a=new char[len+1] ;
    strcpy(a,str);
    char *e = a+len-1;
    while (a<e){
        std::swap(*a,*e);
        a++;
        e--;
    }
    auto ret = tmp.find(a,pos);
    if (ret!= npos){
        return _size-1-(ret+len-1);
    }else{
        return npos;
    }
}

std::istream& mystl::operator>>(std::istream& in, string& s)
{
    s.clear(); //清空字符串
    char ch = in.get(); //读取一个字符
    while (ch != ' '&&ch != '\n') //当读取到的字符不是空格或'\n'的时候继续读取
    {
        s += ch; //将读取到的字符尾插到字符串后面
        ch = in.get(); //继续读取字符
    }
    return in; //支持连续输入
}

std::ostream& mystl::operator<<(std::ostream& out, const string& s)
{
    //使用范围for遍历字符串并输出
    for (auto e : s)
    {
        std::cout << e;
    }
    return out; //支持连续输出
}

bool string::operator>(const string& s)const
{
    return strcmp(_str,s._str)>0;
}
bool string::operator>=(const string& s)const
{
    return (*this>s)||(*this==s);
}
bool string::operator<(const string& s)const
{
    return !(*this>=s);
}
bool string::operator<=(const string& s)const
{
    return (*this<s)||(*this==s);
}
bool string::operator==(const string& s)const
{
    return strcmp(_str,s._str)==0;
}
bool string::operator!=(const string& s)const
{
    return !(*this==s);
}

bool string::operator>(const char* s)const
{
    return strcmp(_str,s)>0;
}
bool string::operator>=(const char* s)const
{
    return strcmp(_str,s)>=0;
}
bool string::operator<(const char* s)const
{
    return strcmp(_str,s)<0;
}
bool string::operator<=(const char* s)const
{
    return strcmp(_str,s)<=0;
}
bool string::operator==(const char* s)const
{
    return strcmp(_str,s)==0;
}
bool string::operator!=(const char* s)const
{
    return strcmp(_str,s)!=0;
}

std::istream& mystl::getline(std::istream& in, string& s)
{
    s.clear();
    char ch = in.get();
    while (ch!='\n'){
        s+=ch;
        ch=in.get();
    }
    return in;
}

