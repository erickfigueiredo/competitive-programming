#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main()
{
    stack<string> nxt, prev;
    string curr = "http://www.acm.org/";
    string input;

    while (true)
    {
        cin >> input;

        if (input == "QUIT")
            break;

        if (input == "VISIT")
            continue;

        if (input == "BACK")
        {
            if (prev.empty())
            {
                cout << "Ignored\n";
            }
            else
            {
                nxt.push(curr);
                curr = prev.top();
                prev.pop();
                cout << curr << endl;
            }
        }
        else if (input == "FORWARD")
        {
            if (nxt.empty())
            {
                cout << "Ignored\n";
            }
            else
            {
                prev.push(curr);
                curr = nxt.top();
                nxt.pop();
                cout << curr << endl;
            }
        }
        else
        {
            prev.push(curr);
            curr = input;
            cout << input << endl;
            nxt = stack<string>();
        }
    }
    return 0;
}
