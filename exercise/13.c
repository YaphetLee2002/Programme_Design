#include <stdio.h>
#include <stdlib.h>
typedef int ElementType;
#define MinData 0;
struct HeapStruct;
typedef struct HeapStruct *PriorityQueue;

struct HeapStruct
{
    int Size;
    ElementType *Elements;
};

int IsEmpty(PriorityQueue H)
{
    return H->Size == 0;
}

PriorityQueue
Initialize(int MaxElements)
{
    PriorityQueue H;

    H = (PriorityQueue)malloc(sizeof(struct HeapStruct));

    H->Elements = (ElementType*)malloc(sizeof(ElementType) * (MaxElements + 1));

    H->Size = 0;
    H->Elements[0] = MinData;

    return H;
}

void Insert(ElementType X, PriorityQueue H)
{
    int i;
    for (i = ++H->Size; H->Elements[i / 2] > X; i /= 2)
        H->Elements[i] = H->Elements[i / 2];
    H->Elements[i] = X;
}

ElementType
DeleteMin(PriorityQueue H)
{
    int i, Child;
    ElementType MinElement, LastElement;

    MinElement = H->Elements[1];
    LastElement = H->Elements[H->Size--];

    for (i = 1; i * 2 <= H->Size; i = Child)
    {
        Child = i * 2;
        if (Child != H->Size && H->Elements[Child + 1] < H->Elements[Child])
            Child++;

        if (LastElement > H->Elements[Child])
            H->Elements[i] = H->Elements[Child];
        else
            break;
    }
    H->Elements[i] = LastElement;
    return MinElement;
}

int main(void)
{
    long long sum = 0;
    PriorityQueue Q = Initialize(100000);
    int count;
    scanf("%d", &count);
    int tempnum;
    while(count--)
    {
        scanf("%d", &tempnum);
        Insert(tempnum ,Q);
    }
    while(Q->Size > 1)
    {
        int thisnum = DeleteMin(Q);
        thisnum += DeleteMin(Q);
        sum += thisnum;
        Insert(thisnum, Q);
    }
    printf("%lld\n", sum);
    return 0;
}