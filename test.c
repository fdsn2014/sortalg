#include<stdio.h>
#include<stdlib.h>

void initstr(int* str,int len){
    int i = 0;
    while(i < len){
        str[i] = rand()%100;
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
int main(void){
    int len = 10;
    int str[len];
    initstr(str,len);

    printf("init rand str is :\n");
    int i = 0;
    for(;i < len ;i++){
        printf("%8d",str[i]);
    }
    printf("\n"); 
    
    bubblesort(str,len);
    
    printf("sort str is :\n");    
    for(i=0;i < len ;i++){
        printf("%8d",str[i]);
    }
    printf("\n");      
     return 0; 
}