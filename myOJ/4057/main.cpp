#include <iostream>
#include <cstring>

using namespace std;

const int MAXSIZE=10003;

int findMaxReverse(char* s);

int main()
{
    char ch[MAXSIZE];
    cin.getline(ch,MAXSIZE);
    int len=strlen(ch);
    int maxLen=0,maxPos=0,curLen;
    for(int i=0;i<len-1;++i)
    {
        curLen=findMaxReverse(s[i]);
        if(curLen>maxLen)
        {
            maxLen=curLen;
            maxPos=i;
        }
    }
    cout<<maxLen;
    if(maxLen>0)
    {
        for(int i=maxPos;i<maxPos+len;++i)
            cout<<s[i];
    }
    return 0;
}

int findMaxReverse(char* s)
{
    int maxlen=strlen(s);
    bool f;
    for(int len=maxlen;len>=2;--len)
    {
        f=true;
        seqStack<char> st(len);
        for(int i=0;i<len;++i)
            st.push(s[i]);
        for(i=0;i!=st.empty();++i)
        {
            if(s[i]!=st.pop())
                f=false;
        }
        if(f)return len;
    }
    return 0;
}

template <class T>
class seqStack
{
private:
    T* elem;
    int top_p;
    int maxSize;
    void doubleSpace();
public:
    seqStack(int initSize=10);
    ~seqStack();
    bool isEmpty()const;
    void push(const T& x );
    T pop();
    T top()const;
};

template <class T>
bool seqStack<T>::isEmpty() const {
    return (top_p==-1);
}

template <class T>
void seqStack<T>::push(const T &x) {
    if(top_p==maxSize)
        doubleSpace();
    ++top_p;
    elem[top_p]=x;
}

template <class T>
T seqStack<T>::top() const{
    return elem[top_p];
}

template <class T>
T seqStack<T>::pop() {

}
