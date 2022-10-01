#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
    int n;
    bool balanced;
    string sentence;

    cin >> n;
    cin.ignore();

    while (n--) {
        stack <char> openedBrackets;
        balanced = true;
        getline(cin, sentence);

        for (int i = 0; i < sentence.size(); i++) {
            if (sentence[i] == '(' || sentence[i] == '[')
                openedBrackets.push(sentence[i]);

            else if ((!openedBrackets.empty()) && ((sentence[i] == ')' && openedBrackets.top() == '(') ||
                (sentence[i] == ']' && openedBrackets.top() == '[')))
                openedBrackets.pop();

            else {
                balanced = false;
                break;
            }
        }

        balanced && openedBrackets.empty() ? cout << "Yes\n" : cout << "No\n";
    }

    return 0;
}