#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#include <stack>
#include <iostream>

using namespace std;

template <class Tipo>
class Stack : private stack<Tipo> {
public:
    void push(Tipo _valor) {
        stack<Tipo>::push(_valor);
    }

    Tipo pop() {
        Tipo temp = stack<Tipo>::top();
        stack<Tipo>::pop();
        return temp;
    }

    bool empty () {
        return stack<Tipo>::empty();
    }

};

#endif // STACK_H_INCLUDED