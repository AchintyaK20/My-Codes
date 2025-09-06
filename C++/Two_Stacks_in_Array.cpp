#include<iostream>
using namespace std;

class TwoStacks {
public:
    int *arr;
    int cap;
    int top1, top2;
    TwoStacks(int n) {
        arr = new int[n];
        cap = n;
        top1 = -1;
        top2 = n;
    }

    void push1(int x) {
        if (top2 - top1 == this->cap) {
            cout << "can't push in stack 1" << endl;
            return;
        }
        top1++;
        arr[top1] = x;
    }
    void push2(int x) {
        if (top2 - top1 == this->cap) {
            cout << "can't push in stack 2" << endl;
            return;
        }
        top2--;
        arr[top2] = x;
    }
    void pop1() {

    }
    void pop2() {

    }
    int peek1() {
        return arr[top1];
    }
    int peek2() {
        return arr[top2];
    }
};

int main() {
    TwoStacks *obj = new TwoStacks(6);
    

}