#include <iostream>
#include <string>

using namespace std;

const char *const Name = "tran hau";
const string AnotherName("test");

class GamePlayer
{
private:
    enum
    {
        N = 5
    }; // enum hack
    int m_arr[N];
    static const int NumTurns; // declare not define
};

const int NumTurns = 5; // define

int main()
{
    cout << Name << endl;
    cout << AnotherName << endl;
    return 0;
}
