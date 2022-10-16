#include<cstdio>
#define MAXN 1000010
long long tree[MAXN];
int num;
void swap(long long arr[],int i, int j){
    long long temp=arr[i];
    arr[i]=arr[j];
    arr[j]=temp;
}
void Down(int i){
    if(i>=num) return;
    while(i*2+1<num){
        int child=2*i+1;
        if(child+1<num && tree[child+1] < tree[child]) child++;
        if(tree[child]>=tree[i]) break;
        swap(tree,i,child);
        i=child;
    }
}
void Build_heap_Up(){
    for(int i=num-1;i>=0;i--) Down(i);
}
void Min_Heapify(int i)
{
    Down(i);
}
int main(){
    scanf("%d",&num);
    for(int i=0;i<num;i++)
        scanf("%ld",&tree[i]);
    Build_heap_Up();
    long long sum=0;
    while(num-1){
        if(num>=3&&tree[2]<tree[1]){
            tree[2]=tree[0]+tree[2];
            sum=sum+tree[2];
            Min_Heapify(2);
        }
        else {
            tree[1]=tree[0]+tree[1];
            sum=sum+tree[1];
            Min_Heapify(1);
        }
        swap(tree,num-1,0);
        num--;
        Min_Heapify(0);
    }
    printf("%ld\n",sum);
}