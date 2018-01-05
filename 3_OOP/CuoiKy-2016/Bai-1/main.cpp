#include <iostream>
#include <sstream>
#include <string>
#include <typeinfo>
using namespace std;

const double PI = 3.1415928;

class Shape
{
      public:
	Shape()
	{
		cerr << "construct Shape" << endl;
	}
	virtual string Description()
	{
		stringstream ss;
		ss << "Shape(area=" << this->Area() << ")";
		return ss.str();
	}
	virtual float Area() = 0;
	virtual void Scale(float scaleFactor) = 0;
	virtual void Scale(float, float) = 0;
	const type_info &InterfaceType()
	{
		return typeid(Shape);
	}
	const type_info &ImplementationType()
	{
		return typeid(*this);
	}
	virtual ~Shape()
	{
		cerr << "destruct Shape" << endl;
	}
};

class NShape : public Shape
{
	float Area()
	{
		return 0;
	}
	void Scale(float)
	{
	}
	void Scale(float, float)
	{
	}
};

class Circle : public Shape
{
      private:
	float radius;

      public:
	Circle(float r) : Shape(), radius(r)
	{
		cerr << "construct Circle" << endl;
	}
	string Description()
	{
		stringstream ss;
		ss << "Circle(r=" << this->radius << ")";
		return ss.str();
	}
	float Area()
	{
		return PI * radius * radius;
	}
	void Scale(float scaleFactor)
	{
		this->radius *= scaleFactor;
	}
	const type_info &InterfaceType()
	{
		return typeid(Circle);
	}
	~Circle()
	{
		cerr << "destruct Circle" << endl;
	}
};

class Ellipse : public Shape
{
      private:
	float majorR, minorR;

      public:
	Ellipse(float a, float b) : Shape(), majorR(a), minorR(b)
	{
		cerr << "construct Ellipse" << endl;
	}
	string Description()
	{
		stringstream ss;
		ss << "Ellipse(a=" << this->majorR << ", b=" << this->minorR
		   << ")";
		return ss.str();
	}
	float Area()
	{
		return PI * majorR * minorR;
	}
	void Scale(float scaleFactor)
	{
		this->majorR *= scaleFactor;
		this->minorR *= scaleFactor;
	}
	void Scale(float sa, float sb)
	{
		this->majorR *= sa;
		this->minorR *= sb;
	}
	const type_info &InterfaceType()
	{
		return typeid(Ellipse);
	}
	~Ellipse()
	{
		cerr << "destruct Ellipse" << endl;
	}
};

int main()
{
	Ellipse ellipse(2.0 / 3, 6);
	Shape *shape = &ellipse;
	shape->Scale(1.0 / 2);
	shape->Scale(3, 1.0 / 3);
	cout << "ellipse: " << endl;
	cout << ellipse.Description() << endl;
	cout << ellipse.Area() << endl;
	cout << ellipse.InterfaceType().name() << endl;
	cout << ellipse.ImplementationType().name() << endl;
	cout << "shape = &ellipse: " << endl;
	cout << shape->Description() << endl;
	cout << shape->Area() << endl;
	cout << shape->InterfaceType().name() << endl;
	cout << shape->ImplementationType().name() << endl;
	NShape ashape;
	cout << ashape.Description() << endl;
	return 0; // no error
}