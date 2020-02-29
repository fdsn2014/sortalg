#include<stdio.h>
#include<stdlib.h>
//打印数组每行10个
void (int str[], int len){

    int i = 0;
    int j = 0;
    for(;i < len ;i+10){
        if(i+9 < len){
            printf("%d<->%d:",i,len);    
        }
        else {
            printf("%d<->%d:",i,i+9);    
        }
        for(j=0;(j<10)||(j<len);j++)
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
int main(int argc,char *argv[]){
    
    int len = 10;
    int str[len];
    initstr(str,len);

    if( argc != 1){
        len = argv[0];
        printf("str len is set %d\n",len);
    }
    printf("init rand str is :\n");
    printf_str(str,len);

    
    bubblesort(str,len);
    
    printf("sort str is :\n");    
    print_str(str,len);
     
     return 0; 
}