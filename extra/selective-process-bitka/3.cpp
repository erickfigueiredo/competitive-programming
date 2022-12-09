#include <stack>
#include <string>
#include <iostream>

using namespace std;

int main() {
    string expressao, buffer;
    double n1, n2;

    while (getline(cin, expressao)) {
        stack<double>nums;

        for (char c : expressao) {
            if (isdigit(c)) 
                buffer += c;
            else if (c == ' ' && buffer.size()) {
                nums.push(stof(buffer));
                buffer = "";
            }
            else if (c != ' ') {
                n2 = nums.top();
                nums.pop();

                n1 = nums.top();
                nums.pop();

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

                nums.push(n1);
            }
        }

        cout << expressao << " = " << nums.top() << "\n\n";
    }

    return 0;
}