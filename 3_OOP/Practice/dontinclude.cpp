#include <iostream>
#include <string>

using namespace std;

const char *const Name = "tran hau";
const string AnotherName("test");

class GamePlayer
{
      private:
	enum { N = 5 }; // enum hack
	int m_arr[N];
	static const int NumTurns; // declare not define
};

const int NumTurns = 5; // define

class TextBlock
{
      private:
	string m_text;

      public:
	TextBlock(string text)
	{
		m_text = text;
	}
	const char &operator[](size_t position) const
	{
		return m_text[position];
	}
	char &operator[](size_t position)
	{
		return m_text[position];
	}
};

int main()
{
	cout << Name << endl;
	cout << AnotherName << endl;

	TextBlock tb("Hello");
	cout << tb[0] << endl;
	tb[0] = 't';
	cout << tb[0] << endl;
	const TextBlock ctb("Word");
	cout << ctb[0] << endl;
	// ctb[0]='h'; error

	const char *const text = "a string";
	cout << text << endl;

	return 0;
}
