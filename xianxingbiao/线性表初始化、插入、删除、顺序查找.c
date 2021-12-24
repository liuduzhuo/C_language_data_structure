#include "stdio.h"
#include "stdlib.h"
#define OK 1;
#define ERROR 0;
#define MaxSize 100
typedef struct List{
    int *elem;
    int Length;
} SqList;
int InitSqList(SqList *L){
    L->elem  =(int *)malloc(MaxSize * 15);
    if(!L->elem) return ERROR;
    L->Length=0;
    L->Length = MaxSize;
    return OK;
};
int InsertSqList(SqList *L,int i,int e){
  if(i<0 || i>L->Length+1) return ERROR;
  if(i< L->Length){
      for(int j=i;j<=L->Length;++j){
          L->elem[j] =L->elem[j+1];
          L->elem[i] = e;
      };
      printf("InsertSqList 函数：插入的位置为：%d,插入的数据为：%d\n",i,L->elem[i]);
  };
  return OK;
};
int DeleteSqList(SqList *L,int i){
    if(i<0 || i>L->Length) return ERROR;
    printf("DeleteSqList函数：要删除的元素索引为：%d,要删除的元素值为：%d\n",i,L->elem[i]);
    if(i<L->Length){
        for(int j=i;j<L->Length;++j){
            L->elem[j] = L->elem[j+1];
        };
    };
    return OK;
}//顺序查找;
int SelectSqList(SqList *L,int e){
    /* e: 为要查找的元素的值 */
    for(int i=0;i<L->Length;i++){
        if(L->elem[i] == e) {
            printf("SelectSqList 函数：要查找的元素【%d】找到了，该元素的下标为：%d\n",e,i);
            return OK;
        };
    };

    printf("SelectSqList 函数：要查找的元素【%d】没有找到！！！\n",e);
    return ERROR;
};
int main(){
    SqList sq;
    InitSqList(&sq);
    InsertSqList(&sq,-1,2);
    InsertSqList(&sq,0,1);
    InsertSqList(&sq,1,5);
    InsertSqList(&sq,2,10);
    InsertSqList(&sq,65,110);
    InsertSqList(&sq,97,101);
    InsertSqList(&sq,101,102);


    DeleteSqList(&sq,2);
    SelectSqList(&sq,101);
    for(int i=0;i<sq.Length;i++){
//        if(sq.elem[i] != 0){
        printf("main 函数：第%d号元素为%d \n",i,sq.elem[i]);
    };
};
