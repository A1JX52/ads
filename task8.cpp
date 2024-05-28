#include <iostream>
using namespace std;
template <typename T>
class Node {
    private:
    T v;
    Node* l;
    Node* r;
    public:
    Node() {
        l = nullptr;
        r = nullptr;
    }
    ~Node() {
        delete l;
        delete r;
    }
    Node* getLeftChild() {
        return l;
    }
    void setLeftChild(Node* n) {
        l = n;
    }
    Node* getRightChild() {
        return r;
    }
    void setRightChild(Node* n) {
        r = n;
    }
    T getValue() {
        return v;
    }
    void setValue(T v) {
        this->v = v;
    }
    void inOrder() {
        if (l != nullptr) {
            l->inOrder();
        }
        cout << v << " ";

        if (r != nullptr) {
            r->inOrder();
        }
    }
    void preOrder() {
        cout << v << " ";

        if (l != nullptr) {
            l->preOrder();
        }

        if (r != nullptr) {
            r->preOrder();
        }
    }
    void postOrder() {
        if (l != nullptr) {
            l->postOrder();
        }

        if (r != nullptr) {
            r->postOrder();
        }
        cout << v << " ";
    }
    void insert (T v) {
        //using a value instead of a node makes sure that we have no children
        if (v < this->v) {
            if (l != nullptr) {
                l->insert(v);
            } else {
                Node* n = new Node();
                n->v = v;
                l = n;
            }
        } else if (v > this->v) {
            if (r != nullptr) {
                r->insert(v);
            } else {
                Node* n = new Node();
                n->v = v;
                r = n;
            }
        }
        //otherwise the value is already in the tree
    }
};

int main(int argc, char* argv[]) {
    Node<int>* n = new Node<int>();;
    n->setValue(15);
    n->insert(5);
    n->insert(20);
    n->insert(3);
    n->insert(12);
    n->insert(17);
    n->insert(31);
    n->insert(10);
    n->insert(14);
    n->insert(13);

    n->preOrder();
    cout << endl;
    
    delete n;
}