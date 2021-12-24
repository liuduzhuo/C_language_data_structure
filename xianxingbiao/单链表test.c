//
// Created by duzhuo on 2021/12/14.
//
#include "stdio.h"
#include "stdlib.h"
//#define MaxSize 100;
#define ERROR 0;
typedef struct Link{
    int elem;
    struct Link* next;
}link;

// 初始化链表
link * InitLink(){
    link * p = (link*) malloc(sizeof (link));
    link * temp = p;
    for (int i =1;i<5;i++){
        link *a = (link*) malloc(sizeof (link));
        a->elem = i+10;
        a->next = NULL;
        temp->next = a;
        temp = temp->next;
    };
    printf("生成的链表为：%p\n",p->elem[p->next]);

    return p;
};
int SelectLink(link *p,int elem){
    link *t = p;
    int i = 1;
    while(t->next){
        t = t->next;
        if(t->elem == elem){
            printf("循环次数：%d\n",i);
            printf("链表元素内容为：%d\n",t->elem);
            return i;
        }
        i++;
    }
    return -1;
}
int main(){
    struct Link li;
    struct Link *p = InitLink();
    SelectLink(p,12);
    while(p->next !=NULL){
        printf("next地址为：%p\n",p->next);
        if(!p->next)return ERROR;
        printf("链表元素中每一个值为：%d\n",p->elem);
        p = p->next;
    }

}