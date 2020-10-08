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
        for (int i = 0; i <= cpy.lastPos; i++)
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


#endif //PILACOLAESTATICA_QUEUE_H
