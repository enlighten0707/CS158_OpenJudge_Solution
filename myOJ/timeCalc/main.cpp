
#include <iostream>

#include <windows.h>

#define NUM 100000

using namespace std;

int main()

{

    int arry[NUM]={0};

    double timeSpent=0;

    LARGE_INTEGER nFreq;

    LARGE_INTEGER nBeginTime;

    LARGE_INTEGER nEndTime;

    QueryPerformanceFrequency(&nFreq); //统计频率

    QueryPerformanceCounter(&nBeginTime);//开始计时



    for(int i=0;i<NUM;i++)

        arry[i]=i;



    QueryPerformanceCounter(&nEndTime); //结束计时

    timeSpent=(double)(nEndTime.QuadPart-nBeginTime.QuadPart )/(nFreq.QuadPart );//得到的是耗时的秒数

    timeSpent*=1000;//得到的是耗时的毫秒数

    cout<<timeSpent<<endl;

    return 0;

}
