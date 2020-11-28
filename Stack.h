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

template <typename T>
class Stack {
private:
    class Node{
    private:
        T data;
        Node* next;
    public:
        Node();
        Node(const T&);

        T getData() const;
        Node* getNext() const;

        void setData(const T&);
        void setNext(Node*);
    };

    Node* anchor;
    void deleteAll();

public:
    Stack();
    Stack(const Stack&);
    ~Stack();

    bool isEmpty() const;

    void push(const T&);
    T pop();
    T getTop() const;
    Stack& operator = (const Stack&);
};

template<typename T>
void Stack<T>::deleteAll() {
    Node* aux;

    while (anchor != nullptr){
        aux = anchor;
        anchor = anchor ->getNext();

        delete aux;
    }
}

template<typename T>
Stack<T>::Stack():anchor(nullptr) {}

template<typename T>
Stack<T>::Stack(const Stack &arg):anchor(nullptr) {
    Node* aux(arg.anchor);
    Node* last(nullptr);
    Node* newNode;

    while(aux != nullptr){
        newNode = new Node(aux->getData());
        if(newNode == nullptr)
            throw StackException("Stack(): bad_alloc");

        if(last == nullptr)
            anchor = newNode;
        else
            last->setNext(newNode);

        last = newNode;
        aux= aux->getNext();
    }
}

template<typename T>
Stack<T>::~Stack() {
    deleteAll();
}

template<typename T>
bool Stack<T>::isEmpty() const {
    return anchor == nullptr;
}

template<typename T>
Stack<T>& Stack<T>::operator=(const Stack &arg) {
    deleteAll();
    this = Stack(arg);

    return *this;
}

template<typename T>
void Stack<T>::push(const T &arg) {
    Node* aux(new Node(arg));

    if(aux == nullptr){
        throw StackException("push(const T&): std::bad_alloc");
    }

    aux->setNext(anchor);
    anchor = aux;
}

template<typename T>
T Stack<T>::pop() {
    if(anchor == nullptr){
        throw StackException("pop(): Stack is empty");
    }

    T res(anchor->getData());
    Node* aux(anchor);
    anchor = anchor -> getNext();

    delete aux;
    return res;
}

template<typename T>
T Stack<T>::getTop() const {
    if(anchor == nullptr){
        throw StackException("getTop(): std::bad_alloc");
    }

    return anchor -> getData();
}

template<typename T>
Stack<T>::Node::Node():next(nullptr) {}

template<typename T>
Stack<T>::Node::Node(const T &arg):data(arg), next(nullptr) {}

template<typename T>
T Stack<T>::Node::getData() const {
    return data;
}

template<typename T>
typename Stack<T>::Node* Stack<T>::Node::getNext() const {
    return next;
}

template<typename T>
void Stack<T>::Node::setData(const T &arg) {
    data = arg;
}

template<typename T>
void Stack<T>::Node::setNext(Stack::Node *arg) {
    next = arg;
}


#endif //PILACOLAESTATICA_STACK_H
