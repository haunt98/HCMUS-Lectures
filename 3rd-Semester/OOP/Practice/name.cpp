#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool isRepeatName(string tempName, vector<string> names) {
    for (int i = 0; i < names.size(); i++) {
        if (tempName == names[i]) return true;
    }
    return false;
}

void foundName(string tempName, vector<string> names, vector<int> scores) {
    cout << "Founding name" << endl;
    bool isFound = false;
    for (int i = 0; i < names.size(); i++) {
        if (tempName == names[i]) {
            cout << names[i] << " " << scores[i] << endl;
            isFound = true;
        }
    }
    if (!isFound) {
        cout << "Name not found" << endl;
    }
}

void foundScore(int tempScore, vector<string> names, vector<int> scores) {
    cout << "Found score" << endl;
    bool isFound = false;
    for (int i = 0; i < scores.size(); i++) {
        if (tempScore == scores[i]) {
            cout << names[i] << " " << scores[i] << endl;
            isFound = true;
        }
    }
    if (!isFound) {
        cout << "Score not found" << endl;
    }
}

int main() {
    vector<string> names;
    vector<int> scores;

    // Input
    string tempName;
    int tempScore;
    while (cin >> tempName >> tempScore && tempName != "NoName" &&
           tempScore != 0) {
        if (isRepeatName(tempName, names)) {
            cout << "Error, repeated name!" << endl;
        } else {
            names.push_back(tempName);
            scores.push_back(tempScore);
        }
    }

    // Print out name and score
    cout << "Printing again" << endl;
    for (int i = 0; i < names.size(); i++) {
        cout << names[i] << " " << scores[i] << endl;
    }

    // Check
    foundName("hau", names, scores);
    foundScore(3, names, scores);
    return 0;
}
