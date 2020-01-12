#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> mod0;
    vector<int> mod1;
    vector<int> mod2;
    for(int i=0; i<n; i++){
        int tmp;
        cin >> tmp;
        if(tmp % 3 == 0){
            mod0.push_back(tmp);
        }
        else if(tmp % 3 == 1){
            mod1.push_back(tmp);
        }
        else{
            mod2.push_back(tmp);
        }
    }
    int result = mod0.size();
    if(k <= mod1.size() && k <= mod2.size()){
        result += k;
    }

    if(k < mod1.size() && k > mod2.size()){
        result += mod2.size();
        result += (k - mod2.size())/3;
    }

    if(k > mod1.size() && k < mod2.size()){
        result += mod1.size();
        result += (k - mod1.size())/3;
    }

    if(k > mod1.size() && k > mod2.size()){
        int minx = min(mod1.size(), mod2.size());
        int maxx = max(mod1.size(), mod2.size());
        result += minx;
        result += (maxx - minx)/3;
    }

    cout << result << endl;
    return 0;
}
