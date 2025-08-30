#include<stdio.h>
#define MAX 100
int n;
int mat[MAX][MAX];
int stack [MAX];
int top=-1;
void push(int a){
    stack[++top]=a;
}
int pop(){
    return stack[top--];
}
int knows(int b, int c){
    return mat[b][c];
}
int find_celebrity(){
    for(int i=0;i<n;i++)
      push(i);
    while(top>0){
        int x=pop();
        int y=pop();
        if (knows (x,y))
            push(y);
        else
            push(x);
        }
    int e=pop();
    for (int i=0;i<n;i++)
        if (i!=e && (knows(e,i)||!knows(i,e)))
            return -1;
        return e;
    }
    int main(){
    printf("Enter the number of persons:\n");
    scanf("%d",&n);
    printf("Enter the matrix:\n");
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            scanf("%d",&mat[i][j]);
    int result=find_celebrity();
    if(result==-1)
        printf("No celebrity\n");
    else
        printf("The celebrity is person %d\n",result);
    return 0;
    }