#ifndef BINARYTREE_QUEUE_H
#define BINARYTREE_QUEUE_H
template <class T>
class Queue
{
private:
    T *elem;
    int front;
    int rear;
public:
    Queue();
    ~Queue();
    bool isEmpty()const;
    void enQueue(const T &x);
    T deQueue();
};
template <class T>
Queue<T>::Queue() {
    front=rear=0;
    elem=new T[1000];
}

template <class T>
Queue<T>::~Queue() {delete []elem;}

template <class T>
bool Queue<T>::isEmpty() const {return front==rear;}

template <class T>
void Queue<T>::enQueue(const T &x) {
    rear=(rear+1)%1000;
    elem[rear]=x;
}

template <class T>
T Queue<T>::deQueue() {
    front=(front+1)%1000;
    return elem[front];
}

#endif //BINARYTREE_QUEUE_H
