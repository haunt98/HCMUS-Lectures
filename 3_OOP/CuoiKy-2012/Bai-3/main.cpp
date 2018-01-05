#include <math.h>
#include <stdio.h>

// Tinh gia tri va dao ham
class Function
{
      public:
	virtual double Value(double x) = 0;
	virtual double Derive(double x) = 0;
	virtual ~Function()
	{
	}
};

class Sin : public Function
{
      private:
	Sin(){};
	static Sin *m_pointer;

      public:
	// Singleton
	static Sin *init()
	{
		if (!m_pointer) {
			m_pointer = new Sin();
		}
		return m_pointer;
	}
	double Value(double x)
	{
		return sin(x);
	}
	double Derive(double x)
	{
		return cos(x);
	}
	~Sin()
	{
		m_pointer = NULL;
	}
};

class Cos : public Function
{
      public:
	double Value(double x)
	{
		return cos(x);
	}
	double Derive(double x)
	{
		return -sin(x);
	}
};

double DeriveProduct(Function *f, Function *g, double x)
{
	if (f && g) {
		return f->Derive(x) * g->Value(x) + f->Value(x) * g->Derive(x);
	}
	return 0;
}

double DeriveSum(Function *f, Function *g, double x)
{
	if (f && g) {
		return f->Derive(x) + g->Derive(x);
	}
	return 0;
}

Sin *Sin::m_pointer = NULL;

int main()
{
	double x = 3.14 / 6; // PI/6
	Sin *s = Sin::init();
	double y = DeriveSum(s, s, x);
	printf("sin(x) = %f; sin'(x) = %f\n", s->Value(x), s->Derive(x));
	printf("y = %f\n", y);
	delete s;
	return 0;
}
