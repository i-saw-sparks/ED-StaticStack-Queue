//
// Created by manie on 08/10/2020.
//

#ifndef PILACOLAESTATICA_QUEUE_H
#define PILACOLAESTATICA_QUEUE_H

#include <exception>
#include <string>

class Exception : std::exception {
private:
    std::string msg;
public:
    explicit Exception(const char *msg) : msg(msg) {}

    explicit Exception(const std::string &msg) : msg(msg) {}

    virtual ~Exception() throw() {}

    const char *what() const throw() override {
        return msg.c_str();
    }
};

template<typename T>
class Queue {
private:
    class Node {
    private:
        T *data;
        Node *next;
        Node *prev;
    public:
        Node();
        Node(const T &);
        ~Node();

        T *getDataPtr() const;
        T getData() const;
        Node *getNext() const;
        Node *getPrev() const;

        void setDataPtr(T *);
        void setData(const T &);
        void setNext(Node *);
        void setPrev(Node *);
    };

    Node *header;
    void deleteAll();

public:
    Queue();
    Queue(const Queue &);
    ~Queue();

    bool isEmpty() const;

    void enqueue(const T &);
    T dequeue();

    T getFront() const;

    Queue &operator=(const Queue &);
};

template<typename T>
Queue<T>::Queue():header(new Node) {
    if (header == nullptr) {
        throw Exception("Queue(): std::bad_alloc");
    }

    header->setNext(header);
    header->setPrev(header);
}

template<typename T>
Queue<T>::~Queue() {
    deleteAll();
    delete header;
}

template<typename T>
bool Queue<T>::isEmpty() const{
    return header->getNext() == header;
}

template<typename T>
void Queue<T>::enqueue(const T &arg) {
    Node *aux;

    if ((aux = new Node(arg)) == nullptr) {
        throw Exception("Node(): std::bad_alloc");
    }

    aux->setPrev(header->getPrev());
    aux->setNext(header);

    header->getPrev()->setNext(aux);
    header->setPrev(aux);
}

template<typename T>
T Queue<T>::dequeue() {
    if(isEmpty()){
        throw Exception("dequeue(): Queue is empty");
    }

    T res(header->getNext()->getData());
    Node* aux(header->getNext());

    aux->getPrev()->setNext(aux->getNext());
    aux->getNext()->setPrev(aux->getPrev());

    delete aux;
    return res;
}

template<typename T>
T Queue<T>::getFront() const {
    if(isEmpty()){
        throw Exception("getFront(): queue is empty");
    }

    return header->getNext()->getData();
}

template<typename T>
Queue<T>& Queue<T>::operator=(const Queue &arg) {
    deleteAll();

    this = Queue(arg);
    return *this;
}

template<typename T>
Queue<T>::Queue(const Queue &arg) :Queue(){
    Node* aux(arg.header->getNext());
    Node* newNode;

    while(aux != arg.header) {
        if ((newNode = new Node(aux->getData())) == nullptr) {
            throw Exception("Queue(): std::bad_alloc");
        }


        newNode->setPrev(header->getPrev());
        newNode->setNext(header);

        header->getPrev()->setNext(newNode);
        header->setPrev(newNode);

        aux = aux->getNext();
    }
}

template<typename T>
void Queue<T>::deleteAll() {
    Node* aux;

    while(header->getNext() != header){
        aux = header->getNext();
        header->setNext(aux->getNext());
        delete aux;
    }

    header->setPrev(header);
}

template<typename T>
Queue<T>::Node::Node(): data(nullptr), prev(nullptr), next(nullptr) {}

template<typename T>
Queue<T>::Node::~Node() {
    delete data;
}

template<typename T>
Queue<T>::Node::Node(const T &arg): data(new T(arg)), prev(nullptr), next(nullptr) {
    if (data == nullptr) {
        throw Exception("Node(): std::bad_alloc");
    }
}

template<typename T>
T *Queue<T>::Node::getDataPtr() const {
    return data;
}

template<typename T>
T Queue<T>::Node::getData() const {
    if (data == nullptr) {
        throw Exception("Node::getData(): nullptr");
    }
    return *data;
}

template<typename T>
typename Queue<T>::Node *Queue<T>::Node::getNext() const {
    return next;
}

template<typename T>
typename Queue<T>::Node *Queue<T>::Node::getPrev() const {
    return prev;
}

template<typename T>
void Queue<T>::Node::setDataPtr(T *arg) {
    data = arg;
}

template<typename T>
void Queue<T>::Node::setData(const T &arg) {
    if (data == nullptr) {
        if ((data = new T(arg)) == nullptr) {
            throw Exception("Node::setData(): std::bad_alloc");
        }
    } else {
        *data = arg;
    }
}

template<typename T>
void Queue<T>::Node::setNext(Queue::Node *arg) {
    next = arg;
}

template<typename T>
void Queue<T>::Node::setPrev(Queue::Node *arg) {
    prev = arg;
}


#endif //PILACOLAESTATICA_QUEUE_H
