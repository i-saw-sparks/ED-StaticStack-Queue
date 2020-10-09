//
// Created by manie on 08/10/2020.
//

#include "Menu.h"


void Menu::run(std::ostream& os, std::istream& is) {
    bool running = true;
    do {
        Queue<char> infixQueue;
        std::string infixEx;
        os << "Infix to postfix" << std::endl << std::endl << "Type your infix expression: ";
        is >> infixEx;

        for (char const &c: infixEx)
            infixQueue.enqueue(c);

        os << std::endl<<"Postfix epression: ";
        PostfixExp::printAsPostfix(infixQueue, os);

        os<<std::endl<<"Do you want to convert another expression? 1-Yes, 2-No"<<std::endl;
        is>>running;
    }while(running);
}
