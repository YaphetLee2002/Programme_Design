#include<iostream>
#include<string>
using namespace std;
int main()
{
    string s = "123456";
    s.push_back(s[1]);
    cout << s << endl;
    return 0;
}