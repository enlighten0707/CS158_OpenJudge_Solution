#ifndef BINARYTREE_STACK_H
#define BINARYTREE_STACK_H

template <class T>
class Stack
{
private:
    T* elem;
    int top_p;
    int maxSize;
    void doubleSpace();
public:
    Stack(int initSize=10);
    ~Stack();
    T top()const;
    T pop();
    void push(const T& x);
    bool isEmpty()const;
};
#endif //BINARYTREE_STACK_H

template <class T>
Stack<T>::Stack(int initSize) {
    maxSize=initSize;
    elem=new T[maxSize];
    top_p=-1;
}
template <class T>
Stack<T>::~Stack() {delete []elem;}
template <class T>
T Stack<T>::pop() {
    T data=elem[top_p];
    --top_p;
    return data;
}
template <class T>
bool Stack<T>::isEmpty() const {return top_p==-1;}
template <class T>
T Stack<T>::top() const {return elem[top_p];}
template <class T>
void Stack<T>::push(const T &x) {
    if(top_p==maxSize-1)
        doubleSpace();
    ++top_p;
    elem[top_p]=x;
}
template <class T>
void Stack<T>::doubleSpace() {
    T* tmp=elem;
    elem=new T[2*maxSize];
    for(int i=0;i<=top_p;++i)
        elem[i]=tmp[i];
    delete []tmp;
}
