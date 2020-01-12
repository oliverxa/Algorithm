//����洢������

#include <iostream>
#include <cstdio>

using namespace std;
//��������ʽ�洢��ʽ�Ķ���
typedef struct BiTnode
{
    int data;
    struct BiTnode *lchild, *rchild;
}BiTnode, *BiTree;

//ǰ�������
void PreOrderTraverse(BiTnode *T)
{
    if(T==NULL)
        return;
    cout << T->data;
    PreOrderTraverse(T->lchild);
    PreOrderTraverse(T->rchild);
}

//�������������
void InOrderTraverse(BiTnode *T)
{
    if(T==NULL)
        return;

    InOrderTraverse(T->lchild);
    cout << T->data;
    InOrderTraverse(T->rchild);
}

//�������������
void PostOrderTraverse(BiTnode *T)
{
    if(T==NULL)
        return;

    PostOrderTraverse(T->lchild);
    PostOrderTraverse(T->rchild);
    cout << T->data;

}

//����������,ԭ�������ڱ�������
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
