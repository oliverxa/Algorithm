#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    vector<int> upbus;
    //vector<int> downbus;
    cin >> n;
    for(int i=0; i<n; i++){
        int tmp = 0;
        cin >> tmp;
        upbus.push_back(tmp);
    }
    int k = 0;
    int sum = 0;

    for(int j=0; j<n; j++){
        int tmp2;
        cin >> tmp2;

        if(tmp2 != 0){
            while(k <= j){
                if( tmp2 <= 0){
                    break;
                }
                if(tmp2- upbus[k] >= 0){
                    sum+= (j-k)*upbus[k];
                    upbus[k] =0;
                    tmp2 -= upbus[k];
                    k++;
                }
                else{
                    sum+= (j-k)* tmp2;
                    upbus[k] -= tmp2;
                    tmp2 = 0;

                }
                //cout << sum;


            }
        }
        //cout << j;
    }






    cout << sum;
    return 0;
}
