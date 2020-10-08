//
// Created by manie on 08/10/2020.
//

#ifndef PILACOLAESTATICA_STACK_H
#define PILACOLAESTATICA_STACK_H

template <typename T, int MAXSIZE = 2048>
class Stack {
public:
    Stack();
    Stack(const Stack&);

    bool isFull();
    bool isEmpty();

    void push();
    T pop();
    T top();

    int getSize();
private:
    T data[MAXSIZE];
    int size;
};

template<typename T, int MAXSIZE>
Stack<T, MAXSIZE>::Stack() {

}

template<typename T, int MAXSIZE>
Stack<T, MAXSIZE>::Stack(const Stack &) {

}

template<typename T, int MAXSIZE>
bool Stack<T, MAXSIZE>::isFull() {
    return false;
}

template<typename T, int MAXSIZE>
bool Stack<T, MAXSIZE>::isEmpty() {
    return false;
}

template<typename T, int MAXSIZE>
void Stack<T, MAXSIZE>::push() {

}

template<typename T, int MAXSIZE>
T Stack<T, MAXSIZE>::pop() {
    return nullptr;
}

template<typename T, int MAXSIZE>
T Stack<T, MAXSIZE>::top() {
    return nullptr;
}

template<typename T, int MAXSIZE>
int Stack<T, MAXSIZE>::getSize() {
    return 0;
}


#endif //PILACOLAESTATICA_STACK_H
