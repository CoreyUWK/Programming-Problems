#include <iostream>
#include <stack>
using namespace std;

string reverse(string s) {
    stack<string> st;

    while (s.size() > 0) {
        int endIndex = 0;
        while (s[endIndex] != ' ' && s[endIndex] != '\0') ++endIndex;
        st.push(s.substr(0, endIndex));
        s.erase(0, endIndex + 1);
    }

    while (!st.empty()) {
        s += st.top() + " ";
        st.pop();
    }
    s.pop_back();
    
    return s;
}

int main()
{
   cout << reverse("Hello, my name is Corey!");
   
   return 0;
}