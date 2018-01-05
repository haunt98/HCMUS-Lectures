#include <iostream>

using namespace std;

class Empty
{
};

// Base class always initialized before derived class
// Empty class always have:
// - Copy constructor
// - Assignment operator
// - Destructor
// If not have any constructor, compiler will give the default

class HomeForSale
{
      private:
	// declare not define
	// no one can use it
	// compiler don't make the default one
	HomeForSale(const HomeForSale &);
	HomeForSale &operator=(const HomeForSale &);

      public:
	HomeForSale();
};

// Use a base class for better prevent

class Uncopyable
{
      protected:
	Uncopyable(); // allow cto and dto
	~Uncopyable();

      private:
	Uncopyable(const Uncopyable &);
	Uncopyable &operator=(const Uncopyable &);
};

// make the base class do firty job
class HomeForSale2 : private Uncopyable
{
};

int main()
{
	Empty e1;
	Empty e2(e1);
	e2 = e1;
	return 0;
}
