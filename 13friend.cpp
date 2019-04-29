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



private:
	int m_real;
	int m_image;
};

int main()
{
	cout << "Hello World" << endl;
}