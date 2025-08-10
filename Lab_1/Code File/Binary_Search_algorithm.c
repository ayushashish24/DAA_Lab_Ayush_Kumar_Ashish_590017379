#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    srand(time(NULL));
    int sizes[5]={0,1,10,50,100};
    int arr[1000],i,j,n,temp,key;
    clock_t s,e;
    double tb,tw,ta;
    FILE *fp=fopen("results.csv","w");
    fprintf(fp,"size,best,worst,avg\n");
    for(int t=0;t<5;t++){
        n=sizes[t];
        for(i=0;i<n;i++) arr[i]=(rand()%201)-100;
        for(i=0;i<n-1;i++) for(j=0;j<n-i-1;j++) if(arr[j]>arr[j+1]){temp=arr[j];arr[j]=arr[j+1];arr[j+1]=temp;}
        key = n>0 ? arr[n/2] : 0;
        s=clock();
        int l=0,r=n-1,m; while(l<=r){m=(l+r)/2; if(arr[m]==key) break; else if(arr[m]<key) l=m+1; else r=m-1;}
        e=clock();
        tb=(double)(e-s)/CLOCKS_PER_SEC;
        key = 99999;
        s=clock();
        l=0; r=n-1; while(l<=r){m=(l+r)/2; if(arr[m]==key) break; else if(arr[m]<key) l=m+1; else r=m-1;}
        e=clock();
        tw=(double)(e-s)/CLOCKS_PER_SEC;
        for(i=0;i<n;i++) arr[i]=(rand()%201)-100;
        for(i=0;i<n-1;i++) for(j=0;j<n-i-1;j++) if(arr[j]>arr[j+1]){temp=arr[j];arr[j]=arr[j+1];arr[j+1]=temp;}
        key = n>0 ? arr[n/4] : 0;
        s=clock();
        l=0; r=n-1; while(l<=r){m=(l+r)/2; if(arr[m]==key) break; else if(arr[m]<key) l=m+1; else r=m-1;}
        e=clock();
        ta=(double)(e-s)/CLOCKS_PER_SEC;
        printf("n=%d best=%lf worst=%lf avg=%lf\n",n,tb,tw,ta);
        fprintf(fp,"%d,%lf,%lf,%lf\n",n,tb,tw,ta);
    }
    fclose(fp);
    return 0;
}