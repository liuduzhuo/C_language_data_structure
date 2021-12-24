//
// Created by duzhuo on 2021/12/13.
//
#include "stdio.h"
#include "stdlib.h"
#include "float.h"
#define MaxSize 100;
typedef struct List{
    int data[100];
    int length;
}Lineartable;


Lineartable* INITAL(){
    Lineartable *lineartable;
    lineartable = (Lineartable *)malloc(sizeof(Lineartable));
    lineartable->length = 0;
    return lineartable;
};
void INSERT(int x,int i, Lineartable *lineartable){
    if(i<0 || i>lineartable->length){
        printf("插入位置不合理;\n");
        return;
    }else{
        for(int j=lineartable->length;j>=i-1;j--){
            lineartable->data[j+1] = lineartable->data[j];
        }
        lineartable->data[i-1]=x;
        lineartable->length++;
        return;
    };
};

int main(){
//    Lineartable li;
//    INITAL();
//    INSERT(10,6,&li);
    printf("float 存储的最大字节数：%lu\n",sizeof(float));
    printf("float 最小值：%E\n",FLT_MIN);
    printf("float 最小值：%E\n",FLT_MAX);
    printf("精度值：%d\n",FLT_DIG);

}