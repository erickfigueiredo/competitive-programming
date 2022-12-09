#include <stack>
#include <string>
#include <iostream>

using namespace std;

int main() {
    string expression, aux;
    double n1, n2;
    stack<double> numbers;

    while (getline(cin, expression)) {
        for (char c : expression) {
            if (isdigit(c)) {
                aux += c;
            }
            else if (c == ' ' && aux.size()) {
                numbers.push(stof(aux));
                aux = "";
            }
            else if (c != ' ') {
                n2 = numbers.top();
                numbers.pop();
                n1 = numbers.top();
                numbers.pop();

                cout << n1 << c << n2 << endl;

                switch (c) {
                case '+':
                    n1 += n2;
                    break;
                case '-':
                    n1 -= n2;
                    break;
                case '*':
                    n1 *= n2;
                    break;
                case '/':
                    n1 /= n2;
                    break;
                }

                numbers.push(n1);
            }
        }

        cout << numbers.top() << endl;
    }
    return 0;
}