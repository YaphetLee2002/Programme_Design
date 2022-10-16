#include <stdio.h>
#include <string.h>

int A[100005], B[100005], C[100005];
inline int Max(int a, int b)
{
    return a > b ? a : b;
}

void Initialize()
{
    memset(C, 0, 100005);
    memset(B, 0, 100005);
    memset(A, 0, 100005);
}

int Compare(int *a, int *b)
{
    int i;
    for (i = 0; i < 1000; i++)
    {
        if (a[i] > b[i])
            return 1;
        if (b[i] > a[i])
            return 0;
    }
    return 0;
}

void plus(const char *a, const char *b, char *c)
{
    Initialize();
    memset(c, 0, 100005);
    const char str[] = {'0'};
    int lengtha = strlen(a);
    int lengthb = strlen(b);
    int len0 = strspn(a, str);
    int lengthA = lengtha - len0;
    len0 = strspn(b, str);
    int lengthB = lengthb - len0;
    for (int i = 0; i < lengthA; i++)
        A[i] = a[lengtha - 1 - i] - '0';
    for (int i = 0; i < lengthB; i++)
        B[i] = b[lengthb - 1 - i] - '0';
    int lengthC = Max(lengthA, lengthB) + 1;
    for (int i = 0; i < lengthC; i++)
    {
        C[i] += A[i] + B[i];
        C[i + 1] = C[i] / 10;
        C[i] %= 10;
    }
    if (C[lengthC - 1] == 0)
        lengthC--;
    if (lengthC == 0)
        c[0] = '0';
    else
    {
        for (int i = 0; i < lengthC; i++)
            c[i] = C[lengthC - 1 - i] + '0';
    }
}

void TurnToArray(int * Array, const char * a, int length, int * Length)
{
    for (int i = 0; i < length; i++)
    {
        if (a[i] != '0')
            A[(*Length)++] = a[i] - '0';
    }
}

void minus(const char *a, const char *b, char *c)
{
    Initialize();
    int flag = 0, i, lengthA = 0, lengthB = 0;
    int lengtha = strlen(a);
    int lengthb = strlen(b);
    for (i = 0; i < lengtha; i++)
    {
        if (a[i] != '0')
            flag = 1;
        if (flag == 1)
        {
            A[lengthA++] = a[i] - '0';
        }
    }
    flag = 0;
    for (i = 0; i < lengthb; i++)
    {
        if (b[i] != '0')
            flag = 1;
        if (flag == 1)
        {
            B[lengthB++] = b[i] - '0';
        }
    }
    int len = Max(lengthA, lengthB);
    if (lengthA > lengthB || ((lengthA == lengthB) && Compare(A, B)))
    {
        for (i = len - 1; i >= 0; i--)
        {
            if (lengthA > 0 && lengthB > 0)
            {
                C[i] = A[--lengthA] - B[--lengthB];
            }
            else if (lengthA > 0 && lengthB <= 0)
            {
                C[i] = A[--lengthA];
            }
            else
                C[i] = -B[--lengthB];
        }
        for (i = len - 1; i >= 0; i--)
        {
            if (C[i] < 0)
            {
                C[i] += 10;
                C[i - 1] -= 1;
            }
        }
        int f;
        for (f = 0; f < len && C[f] == 0; f++)
            ;
        if (f < len)
        {
            for (i = f; i < len; i++)
            {
                c[i - f] = C[i] + '0';
            }
            c[i - f] = '\0';
        }
        else
        {
            c[0] = '0';
            c[1] = '\0';
        }
    }

    else
    {
        for (i = len - 1; i >= 0; i--)
        {
            if (lengthA > 0 && lengthB > 0)
            {
                C[i] = B[--lengthB] - A[--lengthA];
            }
            else if (lengthB > 0 && lengthA <= 0)
            {
                C[i] = B[--lengthB];
            }
            else
                C[i] = -A[--lengthA];
        }
        for (i = len - 1; i >= 0; i--)
        {
            if (C[i] < 0)
            {
                C[i] += 10;
                C[i - 1] -= 1;
            }
        }
        int f;
        for (f = 0; f < len && C[f] == 0; f++)
            ;
        if (f != len)
        {
            for (i = f; i < len; i++)
                c[i - f + 1] = C[i] + '0';
            c[i - f + 1] = '\0';
            c[0] = '-';
        }
        else
        {
            c[0] = '0';
            c[1] = '\0';
        }
    }
}

void multiply(const char *a, const char *b, char *c)
{
    Initialize();
    int lengtha = strlen(a);
    int lengthb = strlen(b);
    int flag = 0, i, lengthA = 0, lengthB = 0, j, ac = 0, f;
    for (i = 0; i < lengtha; i++)
    {
        if (a[i] != '0')
            flag = 1;
        if (flag == 1)
        {
            A[lengthA++] = a[i] - '0';
        }
    }
    flag = 0;
    for (i = 0; i < lengthb; i++)
    {
        if (b[i] != '0')
            flag = 1;
        if (flag == 1)
        {
            B[lengthB++] = b[i] - '0';
        }
    }
    for (i = lengthA - 1; i >= 0; i--)
    {
        for (j = lengthB - 1; j >= 0; j--)
        {
            C[i + j + 1] += A[i] * B[j];
        }
    }
    for (i = lengthA + lengthB - 1; i >= 1; i--)
    {
        if (C[i] >= 10)
        {
            C[i - 1] += C[i] / 10;
            C[i] = C[i] % 10;
        }
    }
    for (f = 0; f <= lengthA + lengthB; f++)
        if (C[f] != 0)
            break;
    if (f <= lengthA + lengthB - 1)
    {
        for (i = f; i <= lengthA + lengthB - 1; i++)
            c[i - f] = C[i] + '0';
        c[i - f] = '\0';
    }
    else
    {
        c[0] = '0';
        c[1] = '\0';
    }
}