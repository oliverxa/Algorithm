#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
typedef struct node{
    int child[100];
    int level;  
}node_n;

int main() {
    int N,M,i,j,ID,id,m,maxl;
    node_n* n;
    int** level;
    int* l;
    int* a;
    
    scanf("%d",&N);
    if(N != 0){
        scanf("%d",&M);
        n = (node_n*)malloc(N*sizeof(node_n));
        for(i = 0;i < N;i++){
            for(j = 0;j < 100;j++){
                n[i].child[j] = 0;
            }
            n[i].level = 0;
        }

        level = (int**)malloc(N*sizeof(int*));
        for(i = 0;i < N;i++){
                level[i] = (int*)malloc(N*sizeof(int));     
        }
        level[0][0] = 0;
        //n[0].level = 0;
        maxl = 0;
        a = (int*)malloc(N*sizeof(int));
        for(i = 0;i <N;i++){
            a[i] = 0;
        }
        for(i = 0;i < M;i++){
            scanf("%d%d",&ID,&m);
            //printf("%d %d ",ID,m);
            for(j = 0;j < m;j++){
                scanf("%d",&id);
                //printf("%d ",id);
                n[ID - 1].child[j] = id - 1;
                //printf("%d %d",(ID - 1),(id - 1));
                //printf("%d ",n[ID - 1].child[j]);
                //printf("%d ",n[id - 1].child[0]);
                n[id - 1].level = n[ID - 1].level + 1;
                level[n[id - 1].level][a[n[id - 1].level]]= id - 1;
                ++a[n[id - 1].level];
                if(n[id - 1].level > maxl){
                    maxl = n[id - 1].level;
                }
            }
        }
        a[0]++;
        l = (int*)malloc((maxl + 1)*sizeof(int));
        for(i = 0;i <= maxl;i++){
            --a[i];
            l[i] = 0;
            //printf("%d ",a[i]);
            for(j = a[i];j >= 0;j--)
            {
                //printf("%d ",n[level[i][a[i]]].child[0]);
                if(n[level[i][a[i]]].child[0] == 0){
                    l[i]++; 
                    //printf("%d ",l[i]);
                }
                
            }
        }
        printf(0);
        for(i=1; i<=maxl ; i++){
            printf()
        }

