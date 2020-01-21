#include <iostream>
#include "priorityQueue.h"

using namespace std;

int main() {
    int num[10]={2,8,9,4,5,1,0,7,12,3};
    priorityQueue<int> test(num,10);
    test.print();

    cout<<test.dequeue()<<endl;
    test.print();

    int x;
    cin>>x;
    test.enqueue(x);
    test.print();

    cout<<test.dequeue()<<endl;
    test.print();
    return 0;
}