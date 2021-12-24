#include "stdio.h"
#include "stdlib.h"
#define MaxSize 100
#define OK 1
#define ERROR 0
typedef struct List{
    int *elem;  // 线性表的初始地址
    int Length; // 线性表的当前长度
//    int listsize; // 当前分配的存储容量
}SqList;
int Init_List(SqList *L){ // 当使用*L时下方指针运算符使用 -> ,当使用&L时下方指针运算符使用L.elem、 L.length
    L->elem =(int *)malloc(MaxSize * sizeof(int));  //
    if(!L -> elem ) exit(ERROR);  //
    L->Length=0;
    L->Length=MaxSize;
    printf("长度为：%d\n",L->Length);

    return OK;
};
int Insert_List_Sq(SqList *L, int i, int e){
    if(i<0 || i> L-> Length+1) return ERROR;  //如果i小于0或者*L 大于初始长度+1(即当i超过初始线性表初始长度，)则添加失败
//    if(MaxSize == L || L-> Length) return ERROR;
//    printf("数组长度为：%d\n",L->Length);
//    if(MaxSize <= L-> Length) return ERROR;
//    if(MaxSize == L || L-> Length) return 0;
    for (int j = 0; j <= L->Length; j++)L->elem[j + 1] = L-> elem[j];
    L->elem[i]=e;
//    L->Length ++;
//    printf("数组内容为:%d\n",e);
    return OK;
}
int Delete_List_Sq(SqList *L, int i){
    if(i<0 || i>L->Length) return ERROR;  // 如果i小于 0 或者i 大于线性表的长度，则报错处理
//    printf("数组长度为：%d\n",L->Length);
    if(i<L->Length+1){
        printf("第%d个元素为：%d\n",i,L->elem[i]);
        printf("线性表长度为：%d\n",L->Length);
        printf("删除的元素为：%d\n",L->elem[i]);
        for(int j=i;j<= L->Length;j++) {
            L->elem[j]=L->elem[j+1];
        };
    return OK;
};};
int SelectSqList(SqList *L,int i){  // 顺序查找
    for(int j=0;j<L->Length+1;j++){
        if(L->elem[j]==i) {
            printf("找到了，值为：%d\n",L->elem[j]);
            printf("循环次数为：%d\n",j);
            return OK;
        };
    };
    printf("没有找到该值：%d\n",i);
};

int main(){
    SqList sq;
    Init_List(&sq);
    Insert_List_Sq(&sq,5,2);
    Delete_List_Sq(&sq,5);
    Insert_List_Sq(&sq,99,2);
    SelectSqList(&sq,2);

};