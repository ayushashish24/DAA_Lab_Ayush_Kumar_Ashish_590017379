#include <stdio.h>
void S_N(int*first,int*second){
    int temp=*first; 
    *first=*second; 
    *second=temp;
}
int find_pivot_place(int numbers[],int start,int end){
    int pivot=numbers[end],smaller_index=start-1;
    for (int current=start;current<end;current++) {
        if (numbers[current]<=pivot) {
            smaller_index++;
            S_N(&numbers[smaller_index],&numbers[current]);
        }
    }
    S_N(&numbers[smaller_index+1],&numbers[end]);
    return smaller_index+1;
}
void quick_sort(int numbers[],int start,int end){
    if (start<end){
        int pivot_index=find_pivot_place(numbers,start,end);
        quick_sort(numbers,start,pivot_index-1);
        quick_sort(numbers,pivot_index+1,end);
    }
}
int main(){
    int numbers[]={283,92,54,29,84738,2973,94,261,753,617,9,1,0,0};
    int n=sizeof(numbers)/sizeof(numbers[0]);
    quick_sort(numbers,0,n-1);
    printf("Sorted array numbers: ");
    for (int i=0;i<n;i++)
    printf("%d,",numbers[i]);
return 0;
}