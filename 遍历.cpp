#include<iostream>
#include<stdlib.h>
#include<malloc.h>
using namespace std;
typedef struct BiTNode{
	char data;
	struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;//定义二叉树 
void CreateBiTree(BiTree &T)
{
    char ch;
	ch=getchar();
	
	if(ch=='#'){T=NULL;}
	else{
	    T=(BiTree)malloc(sizeof(BiTNode));
		T->data=ch;
		CreateBiTree(T->lchild);
		CreateBiTree(T->rchild);
	}
}//先序输入数据 
void ReadMiddle(BiTree T)
{
	BiTree p=T,Stack[100];
    int top=0;
    do{
        while(p)
        {
            Stack[top]=p;
            top++;
            p=p->lchild;
        }
        if(top>0)
        {
        	top=top--;
            p=Stack[top];
            cout<<p->data;
            p=p->rchild;
        }
    }while(top>0 || p);
}//中序遍历 

int main()
{
	BiTree T;
	CreateBiTree(T);
	ReadMiddle(T);
	return 0;
}
