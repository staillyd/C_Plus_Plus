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

int main(int argc, char const *argv[])
{
    Complex c1(3),c2(1,0),c3(c1,c2);
    return 0;
}
