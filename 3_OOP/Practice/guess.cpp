#include <iostream>
#include <vector>
using namespace std;

#define MAX 100

void guess(int low, int high)
{
	if (low == high) {
		cout << "Yeah, I know it : " << low << endl;
	} else {
		int mid = (low + high) / 2;
		cout << "Is your number higher or lower " << mid << " ?"
		     << endl;
		string inp;
		do {
			cin >> inp;
			if (inp == "lower") {
				guess(low, mid);
			} else if (inp == "higher") {
				guess(mid + 1, high);
			}
		} while (inp != "lower" && inp != "higher");
	}
}

int main()
{
	guess(1, 100);
	return 0;
}
