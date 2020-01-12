#include <iostream>
#include <queue>
using namespace std;

int main()
{
    int n;
    cin >> n;
    priority_queue<int,vector<int>, greater<int> > q;
    char tmp;
    int num;
    char fuhao;
    vector<char> result;
    for(int i=0; i<n-1; i++){
        cin >> num;
        if(num == '-'){
            cin >> num;
            q.push(-num);
            cin >> tmp;
        }
        else{
            q.push(num);
            cin >> tmp;
        }

        if(tmp != fuhao && i!=0){
            while(!q.empty()){
                int ans = q.top();
                if(ans < 0){
                    result.push_back('-');
                    char xx = -ans + '0';
                    result.push_back(xx);
                    result.push_back(fuhao);
                }
                q.pop();
                if(q.size()-1 != 0){
                    char xx = ans + '0';
                    result.push_back(xx);
                    //result.push_back(" ");
                    result.push_back(fuhao);

                }
                else{
                    char xx = ans + '0';
                    result.push_back(xx);
                    //result.push_back(" ");
                }
            }
        }
        fuhao = tmp;

    }

    while(!q.empty()){
        int ans = q.top();
        if(ans < 0){
            result.push_back('-');
            char xx = -ans + '0';
            result.push_back(xx);
            result.push_back(fuhao);
        }

        if(q.size()-1 != 0){
            char xx = ans + '0';
            result.push_back(xx);
            //result.push_back(" ");
            result.push_back(fuhao);

        }
        else{
            char xx = ans + '0';
            result.push_back(xx);
            //result.push_back(" ");


        }
        q.pop();
    }


    for(int k=0; k<result.size(); k++){
        cout << result[k];
        cout << " ";
    }
    //cout << "Hello world!" << endl;
    return 0;
}
