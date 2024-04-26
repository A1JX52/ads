#include <iostream>

class Heap {
    private:
    int val[100];
    int occ = 0;
    public:
    int size() {
        return occ;
    }
    void push(int num) {
        val[occ] = num;
        occ++;
        heapifyUp(occ - 1);
    }
    void heapifyUp(int ind) {
        if (ind <= 0) {
            //already root
            return;
        }
        int p = val[ind / 2];

        if (val[ind] > p) {
            val[ind / 2] = val[ind];
            val[ind] = p;
            heapifyUp(ind / 2);
        }
    }
    int pop() {
        int max = val[0];
        val[0] = val[occ - 1];
        occ--;
        heapifyDown(0);
        return max;
    }
    void heapifyDown(int ind) {
        if (ind >= occ / 2) {
            //already last level
            return;
        }
        int l = val[ind * 2 + 1];
        int r = val[ind * 2 + 2];

        if (r > l) {
            if (r > val[ind]) {
                val[ind * 2 + 2] = val[ind];
                val[ind] = r;
                heapifyDown(ind * 2 + 2);
            }
        } else {
            if (l > val[ind]) {
                val[ind * 2 + 1] = val[ind];
                val[ind] = l;
                heapifyDown(ind * 2 + 1);
            }
        }
    }
};

int main(int argc, char* argv[]) {
    Heap h;

    if (0) {
        int test[] = {54, 43, 71, 22, 500};
        
        for (int num : test) {
            h.push(num);
        }
    } else if (argc > 1) {
        char* endptr;
        for (int i = 1; i < argc; i++) {
            int num = strtol(argv[i], &endptr, 10);

            if (*endptr != '\0') {
                std::cout << "invalid number entered." << std::endl;
                return 1;
            }
            h.push(num);
        }
    } else {
        h.push(54);
        h.push(43);
        h.push(71);
        h.push(22);
        h.push(500);
    }

    while (h.size() > 0) {
        std::cout << h.pop() << " ";
    }
    std::cout << std::endl;
    return 0;
}