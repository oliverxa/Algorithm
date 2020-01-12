#include <iostream>
#include <bits/stdc++.h>

using namespace std;
const int MAXV = 200;

//��������Ķ����������޻�ͼ��DAG��
//�����ų��������У�
//ʹ������������u��v�� �������u->v����ôuһ����vǰ�档

//��������ĺ���Ҫ��Ӧ�þ����ж�һ��������ͼ�Ƿ��������޻�ͼ��
//������priority_queue ������ʹ��ÿ�ΰ��ձ����С������

vector<int> G[MAXV];
int  inDegree[MAXV];
int n,m;

bool topologicalSort(){
    int num = 0;
    queue<int> q;
    for(int i=0; i<n; i++){
        if(inDegree[i] == 0)
            q.push(i);
    }
    while(!q.empty()){
        int u=q.front();
        //printf("%d",u); //��ӡ������
        q.pop();
        for(int i=0; i< G[u].size(); i++){
            int v = G[u][i];
            inDegree[v]--;
            if(inDegree[v] == 0){
                q.push(v);
            }
        }
        //G[u].clear(); //��ն���u�����г���
        num++;
    }

    if(num == n) return true; //˵����������ɹ�
    else return false;
}



int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
