#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

int Partition(int L[], int low, int high)
{
    int pivotkey;
    pivotkey=L[low];
    while(low<high)
    {
        while(low<high&&L[high]>=pivotkey)
            high--;
        swap(L[low], L[high]);
        while(low<high&&L[low]<=pivotkey)
            low++;
        swap(L[low], L[high]);
    }
    return low;
}

void QSort(int L[], int low, int high)
{
    int pivot;
    if(low<high)
    {
        pivot=Partition(L, low, high);

        QSort(L, low, pivot-1);
        QSort(L, pivot+1, high);

    }

}

void QuickSort(int L[], int len)
{
    QSort(L, 1, len-1);
}


int main()
{
    int L[] = {0,50,10,90,30,70,40,80,60,20};
    int len = sizeof(L)/sizeof(L[0]);


    for(int i=1; i<len; i++)
    {
        cout<<L[i] << " ";
    }
    cout <<"\n";
    cout << len <<"\n";
    QuickSort(L,len);
    cout << len <<"\n";


    for(int i=1; i<len; i++)
    {
        cout<<L[i] << " ";
    }

    return 0;
}
/*



*/

