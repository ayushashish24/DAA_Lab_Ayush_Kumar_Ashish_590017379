#include <stdio.h>
void merge (int arr[],int low,int mid, int high){
    int a1=mid-low+1, a2=high-mid;
    int left[a1], right[a2];
    for(int i=0;i<a1;i++)
        left[i]=arr[low+i];
    for(int j=0;j<a2;j++)
        right[j]=arr[mid+1+j];
    int i=0,j=0,k=low;
    while(i<a1 && j<a2){
        if(left[i]<=right[j])
            arr[k++]=left[i++];
        else arr[k++]=right[j++];}
        while(i<a1) arr[k++]=left[i++];
        while(j<a2) arr[k++]=right[j++];}
void merge_short(int arr[],int low,int high){
    if(low<high){
        int mid=low+(high-low)/2;
        merge_short(arr,low,mid);
        merge_short(arr,mid+1,high);
        merge(arr,low,mid,high);
    }
}
int main(){
    int arr[]={283,92,54,29,84738,2973,94,0261,753,617,9,1};
    int n=sizeof(arr)/sizeof(arr[0]);
    merge_short(arr,0,n-1);
    printf("Shoeted array numbers:\n");
    for (int i=0;i<n;i++)
        printf("%d,",arr[i]);
        return 0;
}