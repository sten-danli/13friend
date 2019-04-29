#include<iostream>
using namespace std;

class Constractor
{
public://构造函数一;
	Constractor() :m_real(0),m_image(0){}
public://构造函数二;
	Constractor(int real, int image)
	{
		m_real = real;
		m_image = image;
	}
public:
	void PrintData()
	{
		cout << "(" << m_real << "," << m_image <<")"<< endl;
	}

public://func加法;
	Constractor Add(const Constractor& c)
	{
		return Constractor(m_real + c.m_real, m_image + c.m_image);
	}

public:
	Constractor operator+(Constractor& c)
	{
		return Constractor(m_real + c.m_real, m_image + c.m_image);
	}
private:
	int m_real;
	int m_image;
};

int main()
{
	Constractor x;
	Constractor c(1, 2);
	Constractor c1(3, 4);
	x = c + c1;
	x.PrintData();
}