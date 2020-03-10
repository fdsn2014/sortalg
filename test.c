#include<stdio.h>
#include<stdlib.h>
#include <sys/time.h>
//����
//��ӡ����ÿ��10��
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
��������bubblesort
���ܣ�ʹ��ð�ݷ��Գ���Ϊlen��������������
��Σ�  arr δ���������
        len ���鳤��
���Σ�  arr ��������
����ֵ����
*/
void bubblesort(int *arr,int len){
    int i = 0 ,j =0;
    int temp = 0;
    int flag =0;//�Ƿ񽻻�˳��
    //�ڼ���
    for(i=1;i<len;i++){
        flag = 0;
        //δ����ò��������Ƚ�
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
��������partion
���ܣ�ʹ�ÿ��ٷ��з���
��Σ�  arr δ���������
        left �������±�
        riht �������±�
���Σ�  arr ��������
����ֵ����
*/
int partion(int *arr, int left, int right){
 int pivot = arr[left];
 int i = left + 1;
 int j = right;
 while(1)
 {  
   //���ұ���ɨ��
   while(i <= j && arr[i] <= pivot) i++;
   //�������ɨ��
   while(i <= j && arr[j] >= pivot) j--;
   if(i >= j)
     break;
   //����
   int temp = arr[i];
   arr[i] = arr[j];
   arr[j] = temp;
 }
 //��arr[j]����Ԫ����
 arr[left] = arr[j];
 arr[j] = pivot;
 return j;
}
/*
��������quicksort
���ܣ�ʹ�ÿ��ٷ���������������
��Σ�  arr δ���������
        left �������±�
        riht �������±�
���Σ�  arr ��������
����ֵ����
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
��������SelectionSort
���ܣ�ʹ��ð�ݷ��Գ���Ϊlen��������������
��Σ�  arr δ���������
        len ���鳤��
���Σ�  arr ��������
����ֵ����
*/
void SelectionSort(int arr[],int len){
    int i=0,j=0,k;
    int temp;
    //ѡ���λ��
    for(i=0;i<len-1;i++){
        k = i;//��ѡ��Ƚϵ�λ��
        //���������ҵ���С��λ��
        for(j=i+1;j<len;j++){
            if(arr[k]>arr[j]){
                k = j;
            }
        }
        //��С��λ�ò��Ǵ�ѡ���λ�ã��򽻻�
        if(k != i){
            temp = arr[i];
            arr[i] = arr[k];
            arr[k] = temp;    
        }
    }
}
void test_swap(int arr[],int len){
    struct  timeval start,end;
    unsigned  long diff;    
    gettimeofday(&start,NULL);
    //ð������
    bubblesort(arr,len); 
    gettimeofday(&end,NULL);
    diff = 1000000 * (end.tv_sec-start.tv_sec)+ end.tv_usec-start.tv_usec; 
    printf("bubblesort time is %ld\n",diff);
    printf("bubblesort time is %ld\n ",diff);  
    printf("sort arr is :\n");    
    print_arr(arr,len);        
     //��������
    gettimeofday(&start,NULL);
    quicksort(arr,0,len-1);
    gettimeofday(&end,NULL);
    diff = 1000000 * (end.tv_sec-start.tv_sec)+ end.tv_usec-start.tv_usec; 
    printf("quicksort time is %ld\n",diff);  
    printf("quicksort arr is :\n");    
    print_arr(arr,len); 
    //ѡ������           
}

int main(int argc,char *argv[]){    
    int len = 10;
    int arr[100000]; 
    struct  timeval start,end;
    unsigned  long diff; 
    if( argc == 2){
        len = atoi(argv[1]);
        printf("arr len is set %d\n",len);
    }
   //��ʼ������ 
    initarr(arr,len);   
    printf("init rand arr is :\n");
    print_arr(arr,len);
//    test_swap(arr,len);
 
      //ѡ������
    gettimeofday(&start,NULL);
    SelectionSort(arr,len);
    gettimeofday(&end,NULL);
    diff = 1000000 * (end.tv_sec-start.tv_sec)+ end.tv_usec-start.tv_usec; 
    printf("SelectionSort time is %ld\n",diff);  
    printf("SelectionSort arr is :\n");    
    print_arr(arr,len);  

  
     
    return 0; 
}
