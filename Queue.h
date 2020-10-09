//
// Created by manie on 08/10/2020.
//

#ifndef PILACOLAESTATICA_QUEUE_H
#define PILACOLAESTATICA_QUEUE_H

#include <exception>
#include <string>

class QueueException : std::exception{
private:
    std::string msg;
public:
    explicit QueueException(const char* msg): msg(msg){}
    explicit QueueException(const std::string& msg): msg(msg){}

    virtual ~QueueException() throw(){}

    const char* what() const throw() override{
        return msg.c_str();
    }
};

template <typename T, int MAXSIZE = 2048>
class Queue {
public:
    Queue();
    Queue(const Queue<T, MAXSIZE>&);

    bool isEmpty() const;
    bool isFull() const;
    void enqueue(const T&);
    void dequeue();
    T getFront() const;
    int getSize() const;

    Queue &operator=(const Queue<T, MAXSIZE>&);
private:
    T data[MAXSIZE];
    int lastPos;
};

template<typename T, int MAXSIZE>
Queue<T, MAXSIZE>::Queue():lastPos(-1) {}

template<typename T, int MAXSIZE>
Queue<T, MAXSIZE>::Queue(const Queue<T,MAXSIZE>& cpy):lastPos(cpy.lastPos) {
    if(!cpy.isEmpty()) {
        for (int i = 0; i < cpy.getSize(); i++)
            data[i] = cpy.data[i];
    }
}

template<typename T, int MAXSIZE>
bool Queue<T, MAXSIZE>::isEmpty() const {
    return lastPos == -1;
}

template<typename T, int MAXSIZE>
bool Queue<T, MAXSIZE>::isFull() const {
    return lastPos == MAXSIZE-1;
}

template<typename T, int MAXSIZE>
void Queue<T, MAXSIZE>::enqueue(const T &obj) {
    if(isFull())
        throw QueueException("Queue is full");
    lastPos++;
    data[lastPos] = obj;
}

template<typename T, int MAXSIZE>
void Queue<T, MAXSIZE>::dequeue() {
    if(isEmpty())
        throw QueueException("Queue is empty");

    for (int i = 0; i < lastPos; ++i) {
        data[i] = data[i+1];
    }

    lastPos--;
}

template<typename T, int MAXSIZE>
T Queue<T, MAXSIZE>::getFront() const {
    if(isEmpty())
        throw QueueException("Queue is empty");

    return data[0];
}

template<typename T, int MAXSIZE>
Queue<T, MAXSIZE> &Queue<T, MAXSIZE>::operator=(const Queue<T,MAXSIZE>& cpy) {
    this = Queue(cpy);
    return *this;
}

template<typename T, int MAXSIZE>
int Queue<T, MAXSIZE>::getSize() const {
    return lastPos + 1;
}


#endif //PILACOLAESTATICA_QUEUE_H
