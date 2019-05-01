//运算符重载和友元;
//友元最大的作用是友元函数可以去访问类声明的私有部分。
#include <iostream>
using namespace std;


class Complex
{
private:
	int m_real;
	int m_imag;

	//声明一个友元方法，然后把方法在下方外部进行实现（见下方类外面）；
	friend ostream& operator<<(ostream& out, Complex &c);			//为了可以执行:	cout << c1<<endl; //叫做输出流重载；
	friend Complex operator+(const Complex& c, int i);				//为了可以执行：	c = c1+100;
	friend Complex operator+( const int i, const Complex& c);		//为了可以执行：	c = 100 + c1;
	friend void Show(Complex& c);
public:
	//operator+运算符重载方式是为可以这样调动代码：c=c1+100;
	Complex operator+(int i)		//同样功能用友元方法：friend Complex operator+(const Complex& c, int i){return Complex(c.m_real + i, c.m_imag);}
	{
		return Complex(m_real + i, m_imag);
	}

public://　构造函数一；
	Complex() :m_real(0), m_imag(0)
	{}

public://构造函数二；
	Complex(int real, int imag)
	{
		m_real = real;
		m_imag = imag;
	}

public:
	void PrintComplex()const
	{
		cout << "(" << m_real << "," << m_imag << ")" << endl;
	}

public://加法func；
	Complex Add(const Complex& c)
	{
		Complex cmp(m_real + c.m_real, m_imag + c.m_imag);
		return cmp;
	}

public:
	//operator运算符重载方式是为可以这样调动代码： c=c1+c2;
	Complex operator+(const Complex & c)//为了保证我们的对象不更改加const；
	{
		Complex cmp(m_real + c.m_real, m_imag + c.m_imag);
		return cmp;
	}

public:
	//operator运算符重载方式是为可以这样调动代码： c=c1-c2;
	Complex operator-(const Complex & c)
	{
		
		return Complex(m_real - c.m_real, m_imag - c.m_imag);
		//简化前的代码：
		/* Complex cmp(m_real+c.m_real,m_imag+c.m_imag); */
		//我解析一下这个简化前的代码，如果我要返回这个对象那么我要在这个地方创建无名临时对象，
		//然后用cmp拷贝
		//完成后执行析构函数，把对象返回调用者。这样你定义这个“Complex cmp”的意义就是为了
		//去拷贝这个无名临时对象，我们很多时候不会把代码写成这个样子，而是直接返回这个无名临时
		//对象，不会像先前用无名临时对象去拷贝另外一个无名临时对象， 他直接认为这里所创建的无
		//名临时对象就是要返回的无名的临时对象，把他直接返回调用语句。

	}

};

//友元函数实现；
ostream& operator<<(ostream& out, Complex &c)//输出流重载函数实现；
{
	out << "(" << c.m_real << "," << c.m_imag << ")" << endl;
	return out;
}

Complex operator+(const Complex& c, int i)
{
	return Complex(c.m_real + i, c.m_imag);
}

Complex operator+( const int i,  const Complex & c) // 是为可以这样调动代码：c=20+c1; 
{
	cout << "This is Friend + Funktion " << endl;
	return Complex(c.m_real + i, c.m_imag);
}

void Show(Complex& c)
{
	cout << "This is Friend Show Funktion" << endl;
	cout << "m_real= " << c.m_real<<","<< "m_image= " << c.m_imag << endl;
}


int main()
{

	Complex c;
	Complex c1(100, 2);
	c = 100 + c1;
	cout << c1<<endl;
	c.PrintComplex();
	Show(c1);
	

	/*

	Complex c;
	Complex c1(3, 4);
	Complex c2(1, 2);

	
	c = 20 + c1;        //调用Complex operator+(const Complex &c)函数；

	c = c1 + 10;		//调用Complex operator+(int i ) {return Complex(m_real+i,m_imag);}函数；

	c = c1.Add(c2);		 //调动Complex Add(Complex &c)函数；

	c = c1 + c2;        //调用Complex operator+(const Complex &c)运算符重载方式，
	//如果没有定义operator运算符重载方式的话
	//编译器不知道如何这两个数如何去相加，因为他们是复杂对象，不象int x=10, int y=20 一类
	//的，然后定义int result=x+y；编译器内部已经设定好这种整形类型如何去相加。而对象类型内有
	//多种参数，而且又是我们自己创造出来的类型，编译器不知道如何去相加运算，这怎么办呢？
	//我们所谓的运算符重载实际上就是在对这个“+”加号从新做另外一个解释，这是什么意思呢，假如说
	//你要针对两个对象相加编译器不知道如何去相加，那么我就告诉编译器请按照我所写的方法去加，这意味
	//当你调动这个方法的时候“c=c1+c2;”他会被解释为“c=c1.operator+(c2);”形如c1调动了他的一个
	//叫做 “operator+” 的一个普通的函数，只不过operator+是关键字之后呢我们一般很少像这样写：
	//“c=c1.oprator+(c2)”，你会发现c2被作为参数去运行，所以你发现c=c1+c2;和c=c1.operator+(c2)；
	//这两者是等价的，这个operator+就像Complex Add(Complex &c)函数中的Add一样，你不要用
	//另类的眼光去看他，“oprator”跟另外一个运算符“+”其实就是一个整体，这个函数的名字就叫做operator+
	c2.PrintComplex();
	*/
}
