#include<stdio.h>
#include<stdlib.h>
#include <time.h>
//打印数组每行10个
void print_str(int str[], int len){
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
            printf("%6d",str[j]);
        printf("\n");         
    } 
}
void initstr(int* str,int len){
    int i = 0;
    while(i < len){
        str[i] = rand()%1000;
        i++;    
    } 
    return;   
}
/*
函数名：bubblesort
功能：使用冒泡法对长度为len的无序数组排序
入参：  str 未排序的数组
        len 数组长度
出参：  str 有序数组
返回值：无
*/
void bubblesort(int *str,int len){
    int i = 0 ,j =0;
    int temp = 0;
    int flag =0;//是否交互顺序
    //第几趟
    for(i=1;i<len;i++){
        flag = 0;
        //未排序好部分两两比较
        for(j=0;j<len-i;j++){
            if(str[j] > str[j+1])
            {
                temp = str[j+1];
                str[j+1] = str[j];
                str[j] = temp;
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
入参：  str 未排序的数组
        left 数组左下标
        riht 数组右下表
出参：  str 有序数组
返回值：无
*/
int partion(int *str, int left, int right){
   int temp,pivot;//pivot存放主元
   int i,j;
   i = left;
   pivot = str[right];
   for(j = left;j < right;j++)
   {
       if(str[j] < pivot)
       {  //交换值
           temp = str[i];
           str[i] = str[j];
           str[j] = temp;
           i++;
       }
   }
   str[right] = str[i];
   str[i] = pivot;
   return i;//把主元的下标返回
}
/*
函数名：quicksort
功能：使用快速法对无序数组排序
入参：  str 未排序的数组
        left 数组左下标
        riht 数组右下表
出参：  str 有序数组
返回值：无
*/
void quicksort(int *str,int left,int right){
    int i = 0 ,j =0;
    int center;
    if(left>=right)
        return;
    else
    {
        center = partion(str,left,right);
        quicksort(str,left,center-1);
        quicksort(str,center+1,right);
    }    
      
    
    
}
int main(int argc,char *argv[]){
    
    int len = 10;
    int str[1000];
    time_t stime;
    if( argc == 2){
        len = atoi(argv[1]);
        printf("str len is set %d\n",len);
    }
   //初始化数组 
    initstr(str,len);   
   
 printf("init rand str is :\n");
    print_str(str,len);

/*
//    stime = time(NULL);
    //冒泡排序
    bubblesort(str,len); 
 //   printf("sort time is %d\n",time(NULL)-stime);     
    printf("sort str is :\n");    
    print_str(str,len);
 */  
     //快速排序
//    stime = time(NULL);
    quicksort(str,0,len-1);
 //   printf("quicksort time is %d\n",time(NULL)-stime);      
    printf("quicksort str is :\n");    
    print_str(str,len);  
       
     return 0; 
}
