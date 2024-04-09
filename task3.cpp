#include <iostream>
#include <string>
#include <sstream>

template <typename T>
class List {
    public:
    List() : next(nullptr) {}
    T val;
    List<T>* next;
};

class Stack {
    private:
    List<int>* fst;
    public:
    Stack() : fst(nullptr) {}
    ~Stack() {
        // not necessary if expression is valid
        while (fst != nullptr) {
            List<int>* tmp = fst;
            fst = fst->next;
            delete tmp;
        }
    }
    void calc(char val) {
        int two = pop(), one = pop();
        
        switch (val) {
            case '+':
                push(one + two);
                break;
            case '-':
                push(one - two);
                break;
            case '*':
                push(one * two);
                break;
            case '/':
                push(one / two);
                break;
        }
    }
    void push(int val) {
        List<int>* tmp = new List<int>();
        tmp->val = val;
        tmp->next = fst;
        fst = tmp;
    }
    int pop() {
        int val = fst->val;
        List<int>* tmp = fst;
        fst = fst->next;
        delete tmp;
        return val;
    }
    bool isEmpty() {
        return fst == nullptr;
    }
    int top() {
        return fst->val;
    }
};

int main() {
    Stack stk;
    std::string inp;

    if (1) {
        std::cout << "invalid expressions lead to undefined behavior." << std::endl << "enter an expression:" << std::endl;
        std::getline(std::cin, inp);
    } else {
        inp = "1 5 + 3 7 + * 5 /";
    }
    std::istringstream iss(inp);
    std::string sub;

    while (std::getline(iss, sub, ' ')) {
        try {
            int num = std::stoi(sub);
            stk.push(num);
        } catch (std::invalid_argument) {
            // must be operator
            stk.calc(sub[0]);
        }
    }
    std::cout << "result: " << stk.pop() << std::endl;
    return 0;
}