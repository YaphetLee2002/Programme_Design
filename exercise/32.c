#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
#include <unordered_set>
using namespace std;
using ListNode = list<vector<int>>::iterator;

class Rank
{
public:
    vector<int> rank{0, 0};
    Rank() = default;
};

unordered_set<int> onceDoctor;
vector<int> twiceDoctor;
vector<Rank> doctor(105, Rank());
list<vector<int>> RankList;

void GetDoctor();
inline int CompareTwoDoctor(int, int);
inline int CompareTwoDoctor(int, int, int);
inline int Compare(int, int);
ListNode FindPosition(int);
bool AllOnce(vector<int>);
bool LessThanOnce(vector<int>, int, int);
bool MoreThanOnce(vector<int>, int, int);
void InsertDoctor(ListNode, int);
void PushOnceDoctor(int, int);
void TestFunction();
void PushTwiceDoctor();

int main()
{
    GetDoctor();
    PushTwiceDoctor();

    for (auto oncedoctor : onceDoctor)
    {
        int table = 1;
        if (doctor[oncedoctor].rank[0])
            table = 0;
        vector<int> tempv;
        for (auto &&i : twiceDoctor)
        {
            if (CompareTwoDoctor(i, oncedoctor, table) == 0)
                tempv.push_back(i);
        }

        if (tempv.size())
        {
            int allSame = 1;
            for (auto &i : tempv)
            {
                if (CompareTwoDoctor(i, tempv[0]) != 0)
                    allSame = 0;
            }
            if (allSame)
                PushOnceDoctor(tempv[0], oncedoctor);
        }

        else
        {
            ListNode recordPosition = RankList.end();
            ListNode it;
            bool moreState = false;
            for (it = RankList.begin(); it != RankList.end(); it++)
            {
                if (AllOnce(*it))
                {
                    int compareResult2 = CompareTwoDoctor((*it)[0], oncedoctor, table);
                    if (compareResult2 == 0)
                    {
                        (*it).push_back(oncedoctor);
                        break;
                    }
                    continue;
                }
                else
                {
                    bool isLess = LessThanOnce(*it, oncedoctor, table);
                    bool isMore = MoreThanOnce(*it, oncedoctor, table);
                    if (!isLess && !isMore)
                        break;
                    else if (!isLess && isMore)
                    {
                        if (moreState)
                            continue;
                        else
                        {
                            moreState = true;
                            recordPosition = it;
                        }
                    }
                    else if (isLess && !isMore)
                    {
                        if (moreState)
                            break;
                        else
                            continue;
                    }
                    else
                        return -1;
                }
            }
            if (it == RankList.end())
            {
                bool isIn = false;
                if (recordPosition == RankList.begin())
                    InsertDoctor(recordPosition, oncedoctor);
                else
                {
                    --recordPosition;
                    int compareResult1 = CompareTwoDoctor((*recordPosition)[0], oncedoctor);
                    while (AllOnce(*recordPosition))
                    {
                        if (compareResult1 > 0)
                        {
                            if (recordPosition == RankList.begin())
                            {
                                InsertDoctor(recordPosition, oncedoctor);
                                isIn = true;
                                break;
                            }
                            --recordPosition;
                            compareResult1 = CompareTwoDoctor((*recordPosition)[0], oncedoctor);
                        }
                        else if (compareResult1 == 0)
                        {
                            (*recordPosition).push_back(oncedoctor);
                            isIn = true;
                            break;
                        }
                        else if (compareResult1 < 0)
                        {
                            ++recordPosition;
                            InsertDoctor(recordPosition, oncedoctor);
                            isIn = true;
                            break;
                        }
                    }
                    if (!isIn)
                    {
                        ++recordPosition;
                        InsertDoctor(recordPosition, oncedoctor);
                    }
                }
            }
        }
    }
    TestFunction();
    return 0;
}

void GetDoctor()
{
    for (int i = 0; i < 2; i++)
    {
        int count = 1;
        int times;
        scanf("%d", &times);
        getchar();
        for (int j = 0; j < times; j++)
        {
            string s;
            getline(cin, s);
            Rank tempRank;

            if (s.size())
            {
                int l = 0;
                int nowRank = count;
                for (size_t k = 0; k <= s.size(); k++)
                {
                    if (s[k] == ' ' || k == s.size())
                    {
                        int num = stoi(s.substr(l, k - l));
                        if (i == 0)
                        {
                            doctor[num].rank[0] = nowRank;
                            onceDoctor.insert(num);
                        }
                        else
                        {
                            doctor[num].rank[1] = nowRank;
                            if (doctor[num].rank[0])
                            {
                                twiceDoctor.push_back(num);
                                onceDoctor.erase(onceDoctor.find(num));
                            }
                            else
                                onceDoctor.insert(num);
                        }
                        count++;
                        l = k + 1;
                    }
                }
            }
            else
                break;
        }
    }
}

inline int CompareTwoDoctor(int a, int b)
{
    return (doctor[a].rank[0] + doctor[a].rank[1]) - (doctor[b].rank[0] + doctor[b].rank[1]);
}

inline int CompareTwoDoctor(int a, int b, int table)
{
    return doctor[a].rank[table] - doctor[b].rank[table];
}

inline int Compare(int a, int b)
{
    return (CompareTwoDoctor(a, b) > 0);
}

ListNode FindPosition(int n)
{
    for (ListNode it = RankList.begin(); it != RankList.end(); it++)
    {
        for (auto &j : *it)
        {
            if (j == n)
                return it;
        }
    }
    return RankList.end();
}

bool AllOnce(vector<int> v)
{
    for (auto i : v)
    {
        if (doctor[i].rank[0] && doctor[i].rank[1])
            return false;
    }
    return true;
}

bool LessThanOnce(vector<int> v, int oncedoctor, int table)
{
    for (auto &&i : v)
    {
        if (!doctor[i].rank[table])
            continue;
        if (doctor[i].rank[table] >= doctor[oncedoctor].rank[table])
            return false;
    }
    return true;
}

bool MoreThanOnce(vector<int> v, int oncedoctor, int table)
{
    for (auto &&i : v)
    {
        if (!doctor[i].rank[table])
            continue;
        if (doctor[i].rank[table] <= doctor[oncedoctor].rank[table])
            return false;
    }
    return true;
}

void InsertDoctor(ListNode newNode, int oncedoctor)
{
    vector<int> v(1, oncedoctor);
    RankList.insert(newNode, v);
}

void PushOnceDoctor(int targetPosition, int oncedoctor)
{
    vector<int> &v = *FindPosition(targetPosition);
    v.push_back(oncedoctor);
}

void TestFunction()
{
    for (auto i : RankList)
    {
        for (auto j : i)
        {
            if (j == *(i.end() - 1))
                printf("%d", j);
            else
                printf("%d ", j);
        }
        putchar('\n');
    }
}

void PushTwiceDoctor()
{
    if (twiceDoctor.empty())
        return;
    sort(begin(twiceDoctor), end(twiceDoctor), Compare);
    vector<int> tempv(1, twiceDoctor[0]);
    for (size_t i = 1; i < twiceDoctor.size(); i++)
    {
        if (CompareTwoDoctor(twiceDoctor[i], twiceDoctor[i - 1]) == 0)
            tempv.push_back(twiceDoctor[i]);
        else
        {
            RankList.push_front(tempv);
            tempv.clear();
            tempv.push_back(twiceDoctor[i]);
        }
    }
    if (!tempv.empty())
        RankList.push_front(tempv);
}