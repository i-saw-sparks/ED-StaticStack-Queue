//
// Created by manie on 08/10/2020.
//

#ifndef PILACOLAESTATICA_STACK_H
#define PILACOLAESTATICA_STACK_H

#include <exception>
#include <string>

class StackException : std::exception{
private:
    std::string msg;
public:
    explicit StackException(const char* msg): msg(msg){}
    explicit StackException(const std::string& msg): msg(msg){}

    virtual ~StackException() throw(){}

    const char* what() const throw() override{
        return msg.c_str();
    }
};

template <typename T, int MAXSIZE = 2048>
class Stack {
public:
    Stack();
    Stack(const Stack&);

    bool isFull() const;
    bool isEmpty() const;

    void push(const T&);
    T pop();
    T getTop() const;
    int getSize() const;

    Stack &operator=(const Stack &);
private:
    T data[MAXSIZE];
    int top;
};

template<typename T, int MAXSIZE>
Stack<T, MAXSIZE>::Stack():top(-1) {}

template<typename T, int MAXSIZE>
Stack<T, MAXSIZE>::Stack(const Stack &cpy):top(cpy.top) {
    for(int i = 0; i < MAXSIZE; i++)
        data[i] = cpy.data[i];
}

template<typename T, int MAXSIZE>
bool Stack<T, MAXSIZE>::isFull() const{
    return top == MAXSIZE-1;
}

template<typename T, int MAXSIZE>
bool Stack<T, MAXSIZE>::isEmpty() const{
    return top==-1;
}

template<typename T, int MAXSIZE>
void Stack<T, MAXSIZE>::push(const T& obj) {
    if(isFull())
        throw StackException("Stack overflow");
    top++;
    data[top] = obj;
}

template<typename T, int MAXSIZE>
T Stack<T, MAXSIZE>::pop() {
    if(isEmpty())
        throw StackException("Empty stack");
    top--;
    return data[top + 1];
}

template<typename T, int MAXSIZE>
T Stack<T, MAXSIZE>::getTop() const {
    if(isEmpty())
        throw StackException("Empty Stack");
    return data[top];
}

template<typename T, int MAXSIZE>
int Stack<T, MAXSIZE>::getSize() const {
    return top+1;
}

template<typename T, int MAXSIZE>
Stack<T, MAXSIZE>& Stack<T, MAXSIZE>::operator=(const Stack &obj){
    this = Stack(obj);
    return *this;
}


#endif //PILACOLAESTATICA_STACK_H
