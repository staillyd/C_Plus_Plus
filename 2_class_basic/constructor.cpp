class Complex
{
private:
    double real,imag;//和python中self不同
public:
    Complex(double r,double i);
    Complex(double r);
    Complex(Complex c1,Complex c2);
    ~Complex();
};

Complex::Complex(double r,double i)
{
    real=r;imag=i;
}

Complex::Complex(double r)
{
    real=r;imag=0;
}

Complex::Complex(Complex c1,Complex c2)
{
    real=c1.real+c2.real;
    imag=c1.imag+c2.imag;
}

Complex::~Complex()
{
}


class Test
{
private:
    /* data */
public:
    Test(int n){};
    Test(int n,int m){};
    Test(){};
    ~Test(){};
};

#include <iostream>
using namespace std;
class A
{
public:
    int x;
    A(int x){this->x=x;};
    A(const A& a){//形式必须是T &或const T&
        // x=a.x+1;
        cout<<"copy"<<std::endl;
    }
};
A func(){
    A b(4);
    return b;
}

class C
{
public:
    double real,imag;
    C(int i){real=i;imag=0;cout<<"类型转换"<<endl;};
    C(double r,double i){real=r;imag=i;}
};


int main(int argc, char const *argv[])
{
    //构造函数
    Complex c1(3),c2(1,0),c3(c1,c2);
    Test arr1[3]={1,Test(1,2)};//0: Test(1);  1:Test(1,2);  2:Test()
    Test * p[3]={new Test(4),new Test(1,2)};//生成2个对象,定义的是指针数组!!
    //复制构造函数
    A a1=A(1);
    A a2=a1;//调用复制构造函数,但自己实现的复制构造函数没有对成员变量进行赋值
    cout<<func().x<<endl;
    //类型转换构造函数
    C c1(7,8);
    C c2=12;//构造函数
    c1=9;//自动转换为临时C对象

    return 0;
}
