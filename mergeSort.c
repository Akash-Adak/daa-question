#include<stdio.h>
void merge(int arr[],int s,int m,int e){
   
    int n1=m-s+1;

    int n2=e-m;

    int a1[n1],a2[n2];

    for(int i=0;i<n1;i++) 
        a1[i]=arr[s+i];

    for(int i=0;i<n2;i++)
        a2[i]=arr[m+1+i];

    int  i=0,j=0,k=s;
                            //    a1=[1,3,5]    a2=[2,5,7]
    while(i<n1 && j<n2){
        if(a1[i]<= a2[j]) {
            arr[k]=a1[i];
            i++;
        }
        else{
            arr[k]=a2[j];
             j++;
        }
        k++;
    }
    while(i<n1 ){
        arr[k]=a1[i];
        i++;
        k++;
    }
    while(j<n2 ){
        arr[k]=a2[j];
        j++;
        k++;
        }

}
void mergeSort(int arr[],int start,int end){
    int mid=start+(end-start)/2;
    if(start<end){
        mergeSort(arr,start,mid);
        mergeSort(arr,mid+1,end);
        merge(arr,start,mid,end);
    }
}
int main(){
   int arr[]={2,7,4,1,3,9}; 
   mergeSort(arr,0,5);
   printf("sorted are  :");
    for(int i=0;i<6;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}
