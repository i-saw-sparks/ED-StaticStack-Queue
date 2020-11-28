//
// Created by manie on 08/10/2020.
//

#include "PostfixExp.h"

Queue<char> PostfixExp::infixToPostfix(const Queue<char> &obj) {
    Queue<char> post, inf(obj);
    Stack<char> workingStack;

    while (!inf.isEmpty()) {
        if ((inf.getFront() < 40 || inf.getFront() > 47) && inf.getFront() != '^')
            post.enqueue(inf.getFront());
        else {
            if (inf.getFront() == '(')
                workingStack.push('(');
            else if (inf.getFront() == ')') {
                while (workingStack.getTop() != '(') {
                    post.enqueue(workingStack.pop());
                    if (workingStack.isEmpty())
                        break;
                }
                if(!workingStack.isEmpty())
                    workingStack.pop();
            } else if (workingStack.isEmpty())
                workingStack.push(inf.getFront());
            else if (inf.getFront() == '+' || inf.getFront() == '-') {
                while (isGreaterOrEqual(workingStack.getTop(), '+') && workingStack.getTop() != '(') {
                    post.enqueue(workingStack.pop());
                    if (workingStack.isEmpty())
                        break;
                }
                workingStack.push(inf.getFront());
            } else if (inf.getFront() == '/' || inf.getFront() == '*') {
                while (isGreaterOrEqual(workingStack.getTop(), '*') && workingStack.getTop() != '(') {
                    post.enqueue(workingStack.pop());
                    if (workingStack.isEmpty())
                        break;
                }
                workingStack.push(inf.getFront());
            } else if (inf.getFront() == '^') {
                while (isGreaterOrEqual(workingStack.getTop(), '^') && workingStack.getTop() != '(') {
                    post.enqueue(workingStack.pop());
                    if (workingStack.isEmpty())
                        break;
                }
                workingStack.push(inf.getFront());
            }
        }
        inf.dequeue();
    }
    while (!workingStack.isEmpty()) {
        post.enqueue(workingStack.pop());
    }

    return post;
}

void PostfixExp::printAsPostfix(const Queue<char> &inf, std::ostream &os) {
    Queue<char> toPrint = infixToPostfix(inf);

    while(!toPrint.isEmpty()){
        os<<toPrint.getFront();
        toPrint.dequeue();
    }

}

bool PostfixExp::isGreaterOrEqual(char high, char less) {
    if (high == '^') {
        return true;
    } else {
        if (high == '/' || high == '*') {
            return less != '^';
        } else {
            return less == '+' || less == '-';
        }
    }
}
