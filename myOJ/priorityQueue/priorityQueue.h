#ifndef PRIORITYQUEUE_PRIORITYQUEUE_H
#define PRIORITYQUEUE_PRIORITYQUEUE_H

#include <iostream>
using namespace std;

template <class T>
class priorityQueue{
public:
    priorityQueue(int capacity=100);
    priorityQueue(const T data[],int size);
    ~priorityQueue();
    bool isEmpty()const;
    void enqueue(const T &x);
    T dequeue();
    T getHead()const;
    void print()const;

private:
    int currentSize;
    T* array;
    int maxSize;
    void doubleSpace();
    void buildHeap();
    void percolateDown(int hole);
};
#endif //PRIORITYQUEUE_PRIORITYQUEUE_H

template <class T>
priorityQueue<T>::priorityQueue(int capacity) {
    array=new T [capacity];
    maxSize=capacity;
    currentSize=0;
}

template <class T>
priorityQueue<T>::~priorityQueue() {
    delete []array;
}

template <class T>
bool priorityQueue<T>::isEmpty() const {
    return currentSize==0;
}

template <class T>
T priorityQueue<T>::getHead() const {return array[1];}

template <class T>
void priorityQueue<T>::enqueue(const T &x) {
    if(currentSize==maxSize-1) doubleSpace();
    int hole=++currentSize;
    for(;hole>1;hole/=2){
        if(array[hole/2]>x)array[hole]=array[hole/2];
        else break;
    }
    array[hole]=x;
}

template <class T>
T priorityQueue<T>::dequeue() {
    T tmp=array[1];
    array[1]=array[currentSize--];
    percolateDown(1);
    return tmp;
}

template <class T>
void priorityQueue<T>::percolateDown(int hole) {
    int child;
    int tmp=array[hole];
    for(;hole*2<=currentSize;hole=child){
        child=hole*2;
        if(child!=currentSize&&array[child+1]<array[child])++child;
        if(array[child]<tmp) array[hole]=array[child];
        else break;
    }
    array[hole]=tmp;
}

template <class T>
priorityQueue<T>::priorityQueue(const T *data, int size) {
    currentSize=size;
    maxSize=size+10;
    array=new T[maxSize];
    for(int i=0;i<size;++i)
        array[i+1]=data[i];
    buildHeap();
}

template <class T>
void priorityQueue<T>::buildHeap() {
    for(int i=currentSize/2;i>0;--i)
        percolateDown(i);
}

template <class T>
void priorityQueue<T>::doubleSpace() {
    T* tmp=array;
    maxSize*=2;
    array=new T[maxSize];
    for(int i=1;i<=currentSize;++i)
        array[i]=tmp[i];
    delete []tmp;
}

template <class T>
void priorityQueue<T>::print()const {
    for(int i=1;i<=currentSize;++i)
        cout<<array[i]<<' ';
    cout<<endl;
}