//
// Created by manie on 08/10/2020.
//

#include "Menu.h"


void Menu::run(std::ostream& os, std::istream& is) {
    Queue<char> infixQueue;
    std::string infixEx;
    os<<"Infix to postfix"<<std::endl<<std::endl<<"Type your infix expression: ";
    is>>infixEx;

    for (char const &c: infixEx)
       infixQueue.enqueue(c);

    os<<std::endl;
    PostfixExp::printAsPostfix(infixQueue, os);
}
