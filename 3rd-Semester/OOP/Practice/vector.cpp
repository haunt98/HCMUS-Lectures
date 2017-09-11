#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<string> words;
    for (string temp; cin >> temp;) {
        words.push_back(temp);
    }
    for (int i = 0; i < words.size(); i++) {
        cout << words[i] << " ";
    }
    cout << endl;
    return 0;
}
