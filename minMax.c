#include<stdio.h>
 int min,max;
 void findMinMax(int arr[], int low, int high){
    if(low==high){
        if( arr[low] <min) min=arr[low];
        if(arr[low]> max) max=arr[low];
        return;
    }
    if(high ==low+1){
        if(arr[low]<arr[high]){
            if(arr[low]<min) min=arr[low];
            if(arr[high]>  max) max=arr[high];
        }else{
             if(arr[high]<min) min=arr[high];
            if(arr[low]>  max) max=arr[low];
        }
        return;
    }
    int mid= (low+high )/2;
    findMinMax(arr,low,mid);
    findMinMax(arr,mid+1,high);
 }
int main(){
  printf("emter no of elements:");
    int n;
    scanf("%d",&n);
    int arr[n];
    printf("enter elements:");
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
   min=arr[0];
   max=arr[0];
   findMinMax(arr,0,n-1);
   printf("min is:%d \n",min);
   printf("max is:%d",max);
 
    return 0;
}
