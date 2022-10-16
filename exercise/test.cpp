#include <iostream>
#include <string>
#include <vector>
using namespace std;
int candy(vector<int>& ratings) {
    vector<int> candyVec(ratings.size(), 1);
    // 从前向后
    cout << candyVec[0] << " ";
    for (int i = 1; i < ratings.size(); i++) {
        if (ratings[i] > ratings[i - 1]) 
            candyVec[i] = candyVec[i - 1] + 1;
        cout << candyVec[i] << " ";
    }
    cout << endl;
    // 从后向前
    cout << candyVec[ratings.size() - 1] << " ";
    for (int i = ratings.size() - 2; i >= 0; i--) {
        if (ratings[i] > ratings[i + 1] ) {
            candyVec[i] = max(candyVec[i], candyVec[i + 1] + 1);
        }
        cout << candyVec[i] << " ";
    }
    cout << endl;
    // 统计结果
    int result = 0;
    for (int i = 0; i < candyVec.size(); i++) result += candyVec[i];
    return result;
}

int main(int argc, char const *argv[])
{
    vector<int> nums {1, 2, 87, 87, 87, 2, 1};
    cout << candy(nums) << endl;
    return 0;
}