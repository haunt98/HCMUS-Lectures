#include <iostream>
using namespace std;

class Date {
   private:
    int y, m, d;

   public:
    Date(int y, int m, int d);
    void addDay(int n);
    int year { return y; }
    int month{return m};
};

int main() { return 0; }
