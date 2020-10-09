#include <iostream>
#include "Stack.h"
#include "Queue.h"
#include "PostfixExp.h"

int main() {
Queue<char> ex;

    ex.enqueue('(');
    ex.enqueue('A');
    ex.enqueue('-');
    ex.enqueue('B');
    ex.enqueue(')');
    ex.enqueue('+');
    ex.enqueue('(');
    ex.enqueue('C');
    ex.enqueue('/');
    ex.enqueue('(');
    ex.enqueue('D');
    ex.enqueue('-');
    ex.enqueue('E');
    ex.enqueue('^');
    ex.enqueue('F');
    ex.enqueue(')');
    ex.enqueue(')');
    ex.enqueue('/');
    ex.enqueue('G');
    ex.enqueue('*');
    ex.enqueue('H');
    PostfixExp::printAsPostfix(ex, std::cout);
    return 0;
}