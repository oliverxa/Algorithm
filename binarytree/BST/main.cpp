#include <iostream>

using namespace std;

struct node{
    int data;
    node* lchild;
    node* rchild;
};

node* root=NULL;

node* newNode(int v){
    node* Node = new node;
    Node->data = v;
    Node->lchild = Node->rchild = NULL;
    return Node;
}

void search_node(node* root, int x){
    if(root == NULL){
        print("search failed\n");
        return;
    }

    if(x == root->data){
        print("%d\n", root->data);
    }else if (x < root->data){
        search_node(root->lchild, x);
    }else{
        search_node(root->rchild, x);
    }
}

void insert_node(node* &root, int x){
    if(root == NULL){
        root = newNode(x);
        return;
    }

    if(x == root->data){
        return;
    }else if(x < root->data){
        insert_node(root->lchild, x);
    }else{
        insert_node(root->rchild, x);
    }

}

node* Create(int data[], int n){
    node* root = NULL;
    for(int i=0; i<n; i++){
        insert_node(root, data[i]);
    }
    return root;
}

//¶þ²æ²éÕÒÊ÷µÄÉ¾³ý
node* findMax(node* root){
    while(root->rchild != NULL){
        root = root->rchild;
    }
    return root;
}

node* findmin(node* root){
    while(root->lchild !=NULL){
        root = root->lchild;
    }
    return root;
}

void deleteNode(node* &root, int x){
    if(root == NULL) return;
    if(root->data == x){
        if(root->lchild == NULL && root->rchild == NULL){
            root = NULL;
        }else if( root->lchild != NULL){
            node* pre = findMax(root->lchild);
            root->data = pre->data;
            deleteNode(root->lchild, pre->data);
        }else{
            node* next = findMin(root->rchild);
            root->data = next->data;
            deleteNode(root->rchild, next->data);
        }
    }else if(root->data > x){
        deleteNode(root->lchild, x);
    }else{
        deleteNode(root->rchild, x);
    }

}

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
