//链表存储二叉树

#include <iostream>
#include <cstdio>

using namespace std;
//二叉树链式存储方式的定义
typedef struct BiTnode
{
    int data;
    struct BiTnode *lchild, *rchild;
}BiTnode, *BiTree;

//前序遍历二
void PreOrderTraverse(BiTnode *T)
{
    if(T==NULL)
        return;
    cout << T->data;
    PreOrderTraverse(T->lchild);
    PreOrderTraverse(T->rchild);
}

//中序遍历二叉树
void InOrderTraverse(BiTnode *T)
{
    if(T==NULL)
        return;

    InOrderTraverse(T->lchild);
    cout << T->data;
    InOrderTraverse(T->rchild);
}

//后序遍历二叉树
void PostOrderTraverse(BiTnode *T)
{
    if(T==NULL)
        return;

    PostOrderTraverse(T->lchild);
    PostOrderTraverse(T->rchild);
    cout << T->data;

}

//建立二叉树,原理类似于遍历搜索
void CreateBiTree(BiTree *T)
{
    int ch;
    cin >> ch;
    if(ch=='#')
        *T=NULL;
    else
    {
        *T=(BiTree)malloc(sizeof(BiTnode));
        if(!*T)
            exit(OVERFLOW);
        (*T)->data = ch;
        CreateBiTree(&(*T)->lchild);
        CreateBiTree(&(*T)->rchild);
    }
}
int main()
{
    *T=(BiTree)malloc(sizeof(BiTnode));
    CreateBiTree(T);
    return 0;
}
