#include<iostream>
#include<string>

using namespace std;
string s[25];
int n;

int* SpellNum(int );

int cmp(int i, int j) {
    if(i <= 0 || i > n || j <= 0 || j > n)
        return -2;
	return s[i] + s[j] > s[j] + s[i];
}

int main() {
	cin >> n;
	for(int i = 1; i <= n; ++i) 
        cin >> s[i];

    int* index = SpellNum(n);
	for(int i = 1; i <= n; ++i) 
        cout << s[index[i]];
    cout << endl;
	return 0;
}
#include<algorithm>
#include<cstring>
#include<cstdlib>
int* SpellNum(int n)
{
    int* array;
    array = (int*)malloc(sizeof(int) * 25);
    memset(array, 0, sizeof(int));
    for (int i = 1; i <= n; i++)
        array[i] = i;
    sort(array + 1, array + n + 1, cmp);
    return array;
}