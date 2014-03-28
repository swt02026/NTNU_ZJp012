#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
long sum, middle;
void sumOfDistance(long& neihber)
{
    sum+=abs(neihber-middle);
}

int compare(const void *a, const void *b)
{
    return *(long *)a-*(long *)b;
}
int main()
{
    int TestNum=0;
    cin >> TestNum;
    for(long Neihber[500]; TestNum--;)
    {
        fill(Neihber,Neihber+500,0);
        int NumOfNeihber = 0;
        cin >> NumOfNeihber;
        for(int j= 0; j < NumOfNeihber; j++)
            cin >> Neihber[j];
        qsort(static_cast<void*>(Neihber),NumOfNeihber,sizeof(long),compare);
        int IsTimeOf4 = !(NumOfNeihber%4);
        middle = (NumOfNeihber%2)?
                 Neihber[NumOfNeihber/2]:
                 ((Neihber[NumOfNeihber/2 - IsTimeOf4]+Neihber[NumOfNeihber/2+1-IsTimeOf4])/2)
                 ;
        sum = 0;
        for_each(Neihber,Neihber+NumOfNeihber,sumOfDistance);
        cout << sum ;
        if(TestNum)
            cout << endl;
    }
    return 0;
}
