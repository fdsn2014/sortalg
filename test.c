#include<stdio.h>
#include<stdlib.h>
#include <sys/time.h>
//打印数组每行10个
void print_arr(int arr[], int len){
    int i = 0;
    int j = 0;
    for(;i < len;i=i+10){
        if(i+9 > len-1){
            printf("%6d<->%6d:",i,len-1);    
        }
        else {
            printf("%6d<->%6d:",i,i+9);    
        }
        for(j=i;(j<(i+10))&&(j<len);j++)
            printf("%6d",arr[j]);
        printf("\n");         
    } 
}
void initarr(int* arr,int len){
    int i = 0;
    while(i < len){
        arr[i] = rand()%10000;
        i++;    
    } 
    return;   
}
/*
函数名：bubblesort
功能：使用冒泡法对长度为len的无序数组排序
入参：  arr 未排序的数组
        len 数组长度
出参：  arr 有序数组
返回值：无
*/
void bubblesort(int *arr,int len){
    int i = 0 ,j =0;
    int temp = 0;
    int flag =0;//是否交互顺序
    //第几趟
    for(i=1;i<len;i++){
        flag = 0;
        //未排序好部分两两比较
        for(j=0;j<len-i;j++){
            if(arr[j] > arr[j+1])
            {
                temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = temp;
                flag = 1;
            }    
        }
        if(0 == flag){
            break;    
        }
    }
}
/*
函数名：partion
功能：使用快速法中分区
入参：  arr 未排序的数组
        left 数组左下标
        riht 数组右下表
出参：  arr 有序数组
返回值：无
*/
int partion(int *arr, int left, int right){
 int pivot = arr[left];
 int i = left + 1;
 int j = right;
 while(1)
 {  
   //向右遍历扫描
   while(i <= j && arr[i] <= pivot) i++;
   //向左遍历扫描
   while(i <= j && arr[j] >= pivot) j--;
   if(i >= j)
     break;
   //交换
   int temp = arr[i];
   arr[i] = arr[j];
   arr[j] = temp;
 }
 //把arr[j]和主元交换
 arr[left] = arr[j];
 arr[j] = pivot;
 return j;
}
/*
函数名：quicksort
功能：使用快速法对无序数组排序
入参：  arr 未排序的数组
        left 数组左下标
        riht 数组右下表
出参：  arr 有序数组
返回值：无
*/
void quicksort(int *arr,int left,int right){
    int i = 0 ,j =0;
    int center;
    if(left>=right)
        return;
    else
    {
        center = partion(arr,left,right);
        quicksort(arr,left,center-1);
        quicksort(arr,center+1,right);
    }     
}
/*
函数名：SelectionSort
功能：使用冒泡法对长度为len的无序数组排序
入参：  arr 未排序的数组
        len 数组长度
出参：  arr 有序数组
返回值：无
*/
void SelectionSort(int arr[],int len){
;
}
void test_swap(int arr[],int len){
    struct  timeval start,end;
    unsigned  long diff;
    
    gettimeofday(&start,NULL);
    //冒泡排序
    bubblesort(arr,len); 
    gettimeofday(&end,NULL);
    diff = 1000000 * (end.tv_sec-start.tv_sec)+ end.tv_usec-start.tv_usec; 
//    printf("bubblesort time is %ld\n",diff);
    printf("bubblesort time is %ld\n ",diff);  
    printf("sort arr is :\n");    
    print_arr(arr,len);
        
     //快速排序
    gettimeofday(&start,NULL);
    quicksort(arr,0,len-1);
    gettimeofday(&end,NULL);
    diff = 1000000 * (end.tv_sec-start.tv_sec)+ end.tv_usec-start.tv_usec; 
    printf("quicksort time is %ld\n",diff);
    printf("quicksort time is %ld\n",diff);      
    printf("quicksort arr is :\n");    
//    print_arr(arr,len);        
}

int main(int argc,char *argv[]){
    
    int len = 10;
    int arr[100000];

  
    if( argc == 2){
        len = atoi(argv[1]);
        printf("arr len is set %d\n",len);
    }
   //初始化数组 
    initarr(arr,len);   
    printf("init rand arr is :\n");
    print_arr(arr,len);
    
    test_swap(arr,len);
 


  
     
    return 0; 
}