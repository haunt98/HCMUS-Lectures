#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<string> num = {"zero", "one",   "two",   "three", "four", "five",
			      "six",  "seven", "eight", "nine",  "ten"};
	for (int temp; cin >> temp && temp >= 0 && temp <= 10;) {
		cout << num[temp] << endl;
	}
	return 0;
}
