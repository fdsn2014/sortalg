#include<stdio.h>
#include<stdlib.h>
#include <time.h>
//��ӡ����ÿ��10��
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
��������bubblesort
���ܣ�ʹ��ð�ݷ��Գ���Ϊlen��������������
��Σ�  str δ���������
        len ���鳤��
���Σ�  str ��������
����ֵ����
*/
void bubblesort(int *str,int len){
    int i = 0 ,j =0;
    int temp = 0;
    int flag =0;//�Ƿ񽻻�˳��
    //�ڼ���
    for(i=1;i<len;i++){
        flag = 0;
        //δ����ò��������Ƚ�
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
��������partion
���ܣ�ʹ�ÿ��ٷ��з���
��Σ�  str δ���������
        left �������±�
        riht �������±�
���Σ�  str ��������
����ֵ����
*/
int partion(int *str, int left, int right){
   int temp,pivot;//pivot�����Ԫ
   int i,j;
   i = left;
   pivot = str[right];
   for(j = left;j < right;j++)
   {
       if(str[j] < pivot)
       {  //����ֵ
           temp = str[i];
           str[i] = str[j];
           str[j] = temp;
           i++;
       }
   }
   str[right] = str[i];
   str[i] = pivot;
   return i;//����Ԫ���±귵��
}
/*
��������quicksort
���ܣ�ʹ�ÿ��ٷ���������������
��Σ�  str δ���������
        left �������±�
        riht �������±�
���Σ�  str ��������
����ֵ����
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
   //��ʼ������ 
    initstr(str,len);   
   
 printf("init rand str is :\n");
    print_str(str,len);

/*
//    stime = time(NULL);
    //ð������
    bubblesort(str,len); 
 //   printf("sort time is %d\n",time(NULL)-stime);     
    printf("sort str is :\n");    
    print_str(str,len);
 */  
     //��������
//    stime = time(NULL);
    quicksort(str,0,len-1);
 //   printf("quicksort time is %d\n",time(NULL)-stime);      
    printf("quicksort str is :\n");    
    print_str(str,len);  
       
     return 0; 
}
