#include <iostream>

using namespace std;

// giver string text and string word
// find the first occurrence of word in text
int bruteSearch(char *text, char *word) {
    int cur = 0;
    bool flag;
    while (text[cur])  // go through text
    {
        flag = true;  // reset flag for every index
        for (int i = cur; text[i] & word[i - cur]; i++) {
            if (text[i] != word[i - cur])
                flag = false;  // 1 error make difference
        }
        if (flag) return cur;
        cur++;
    }
    return -1;
}

using namespace std;

int main() {
    char text[] = "abc123abc123";
    char word[] = "123";
    int i = bruteSearch(text, word);
    cout << i << endl;
    return 0;
}
