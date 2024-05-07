#include <iostream>
#include <stack>

using namespace std;

class Hanoi {
    private:
    stack<int> arr[3];
    int counter;
    public:
    void init(int h) {
        for (int i = 0; i < h; i++) {
            arr[0].push(i);
        }
        counter = 0;
    }
    void setzeScheibe(int from, int to) {
        arr[to].push(arr[from].top());
        arr[from].pop();
    }
    void setzeTurm(int h, int from, int to, int with) {
        counter++;

        if (h == 1) {
            setzeScheibe(from, to);
            return;
        }
        setzeTurm(h - 1, from, with, to);
        setzeScheibe(from, to);
        setzeTurm(h - 1, with, to, from);
    }
    void printResult() {
        for (stack<int> s : arr) {
            if (s.empty()) {
                cout << "(empty)";
            }

            while (!s.empty()) {
                cout << s.top() << " ";
                s.pop();
            }
            cout << endl;
        }
        cout << "setzeTurm() has been called " << counter << " times!" << endl;
    }
};

int main(int argc, char* argv[]) {
    // complexity is 2^n
    Hanoi h;
    int height = 5;

    h.init(height);
    h.setzeTurm(height, 0, 1, 2);
    h.printResult();

    return 0;
}