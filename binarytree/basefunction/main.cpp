#include <iostream>
#include <cstdio>

#include <queue>
using namespace std;

//树的建立

struct node{
    int data; //typename data;
    //int layer;
    node* lchild;
    node* rchild;
};

node* root = NULL;

//创建新的节点
node* newNode(int v){
    node* Node = new node;
    Node->data = v;
    Node->lchild = Node->rchild = NULL;
    return Node;
}

//查找 x 修改的数据， 修改成newdata 的数据
void search_node(node* root, int x, int newdata){
    if(root == NULL){
        return;
    }

    if(root->data == x){
        root->data = newdata;
    }

    search_node(root->lchild, x, newdata);
    search_node(root->rchild, x, newdata);
}

void insert_node(node* &root, int x){
    if(root == NULL){
        root = newNode(x);
        return;
    }
    //根据题目条件判断应该插在哪边
    if(x != 0){
        insert_node(root->lchild, x);
    }
    else{
        insert_node(root->rchild, x);
    }
}

node* Create(int data[], int n){
    node* root = NULL;
    for(int i = 0; i<n; i++){
        insert_node(root, data[i]);
    }

    return root;
}

//先序
void preorder(node* root){
    if(root == NULL){
        return;
    }

    printf("%d\n", root->data);

    preorder(root->lchild);
    preorder(root->rchild);
}

//中序
void midorder(node* root){
    if(root == NULL){
        return;
    }

    midorder(root->lchild);
    printf("%d\n", root->data);
    midorder(root->rchild);
}
//后续
void postorder(node* root){
    if(root == NULL){
        return;
    }

    postorder(root->lchild);
    postorder(root->rchild);
    printf("%d\n", root->data);
}

//层序遍历 类似BFS
void LayerOrder(node* root){
    queue<node*> q;
    q.push(root);
    while(!q.empty()){
        node* now = q.front();
        q.pop();
        printf("%d", now->data);
        if(now->lchild != NULL) q.push(now->lchild);
        if(now->rchild != NULL) q.push(now->rchild);
    }
}

//根据先序遍历和中序遍历重建二叉树
int mid[];
int pre[];

node* rebuild(int preL, int preR, int midL, int midR){
    if(preL > preR){
        return NULL;
    }
    node* root = new node;
    root->data = pre[preL];
    int k;
    for(k = midL; k<=midR; k++){
        if(mid[k] == pre[preL]){ //在中序中找到根节点
            break;
        }
    }
    int numLeft = k - midL;
    root->lchild = rebuild(pre+1, preL+numLeft, midL, k-1);

    root->rchild = rebuild(pre+numLeft+1, preR, k+1, midR);

    return root;
}


int main()
{
    int n;
    scanf("%d", n);
    int data[n];
    for(int i=0; i<n; i++){
        scanf("%d", data[i]);
    }
    Create(data, n);

    cout << "Hello world!" << endl;
    return 0;
}
