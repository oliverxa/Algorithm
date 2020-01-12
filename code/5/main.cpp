#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int mat[n][3];
    int maxmat[n];
    int minmat[n];
    int zero[n];
    int sum =0;
    int j=0;
    for(int i=0; i<n; i++){
        cin >> mat[i][0] >> mat[i][1] >> mat[i][2];
        //cout << mat[i][0];
        if(mat[i][0]==0||mat[i][1]==0||mat[i][2]==0){
            //cout <<"i:" << i;
            zero[j++] = i;
            int tt = mat[i][0]+mat[i][1]+mat[i][2];
            maxmat[i] = max(mat[i][0],max(mat[i][1],mat[i][2]));
            minmat[i] = tt - maxmat[i];
        }
        else{
            maxmat[i] = max(mat[i][0],max(mat[i][1],mat[i][2]));
        //cout << maxmat[i];
            minmat[i] = min(mat[i][0],min(mat[i][1],mat[i][2]));
        }
        //cout << minmat[i];
    }


    int flag1 =0;
    int flag2 =0;
    for(int i=0; i<zero[0]; i++){
        sum+= maxmat[i];
    }
    //sum = 13
    int m =0;
    bool tmp = false;
    int summax =0;
    int summin =0;
    while(j-2 >= m){
        flag1 = zero[m];
        flag2 = zero[m+1];
        summax =0;
        summin =0;



        if(!tmp){
            summax = maxmat[flag1];
        }
        else{
            summin = minmat[flag1];
        }
        for(int i=flag1+1; i<flag2; i++){
                summax += maxmat[i];

                summin += minmat[i];
            }
        //cout << summax;
        //cout << summin;
        if(summax>(-summin)){
            sum+=summax;
            tmp = false;
        }
        else{
            sum-=summin;
            tmp = true;
        }
        m++;
    }





    cout << sum;

    return 0;
}
