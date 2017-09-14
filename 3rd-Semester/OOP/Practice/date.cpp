#include <iostream>
using namespace std;

class Date {
   private:
    int y, m, d;

   public:
    Date(int yy, int mm, int dd) {}
    void addDay(int n);
    int year() { return y; }
    int month() { return m; }
};

Date::Date(int yy, int mm, int dd) : y{yy}, m{mm}, d{dd};  // member init

void Date::addDay(int n) {
    // add n day
}

int main() { return 0; }
