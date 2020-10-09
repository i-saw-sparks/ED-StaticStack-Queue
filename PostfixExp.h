//
// Created by manie on 08/10/2020.
//

#ifndef PILACOLAESTATICA_POSTFIXEXP_H
#define PILACOLAESTATICA_POSTFIXEXP_H

#include "Stack.h"
#include "Queue.h"
#include <ostream>
#include <iostream>

class PostfixExp {
public:
    static void printAsPostfix(const Queue<char>&, std::ostream&);
    static Queue<char> infixToPostfix(const Queue<char>&);

private:
    static bool isGreaterOrEqual(char, char);
};


#endif //PILACOLAESTATICA_POSTFIXEXP_H
