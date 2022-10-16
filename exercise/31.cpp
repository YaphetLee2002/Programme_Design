#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
const double PAI = 3.14159265;
int main()
{
    int n;
    cin >> n;
    vector<double> v(n, 0.0);
    for (auto &&i : v)
        cin >> i;
    sort(v.begin(), v.end());
    vector<double> v1(n, 0.0);
    for (int i = 0; i < n; i++)
        v1[i] = v[i] - 360.0 * i / n;
    sort(v1.begin(), v1.end());
    double mid = (n % 2) ? v1[n / 2] : (v1[n / 2] + v1[n / 2 - 1]) / 2;
    double ans = 0;
    for (auto &&i : v1)
        ans += fabs(i - mid) * PAI / 180.0;
    printf("%lf\n", ans);
    return 0;
}