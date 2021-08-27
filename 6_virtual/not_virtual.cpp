#include <iostream>
using namespace std;
class Base{
private:
    int a;
public:
    void print(){cout<<"基类"<<endl;};
    virtual void x(){cout<<"x:基类"<<endl;};
};
class Derived:public Base{
private:
    int b;
public:
    void print(){cout<<"继承"<<endl;};
    virtual void x(){cout<<"x:继承"<<endl;};
};
int main(){
    Derived d=Derived();
    Base base=d;//拷贝构造函数??然后只拷贝成员变量
    base.print();//基类
    base.x();//基类

    Base base_=Base();
    base_=d;//赋值,改变变量指向地址
    base_.print();//基类
    base_.x();//基类

    Base *p=&d;
    p->print();//基类
    p->x();//继承,多态
}