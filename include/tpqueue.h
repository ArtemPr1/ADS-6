// Copyright 2022 NNTU-CS

#ifndef INCLUDE_TPQUEUE_H_

#define INCLUDE_TPQUEUE_H_

template<typename T, int size>
class TPQueue {
 private:
    T arr[5];
    int frst;
    int lst;

 public:
    TPQueue() :frst(0), lst(0) { }
    void push(T x) {
        int j = 0;
        T value = x;
        for (int i = frst; i < size; i++) {
            j = lst++ - 1;
            while ((j >= frst) && (arr[(j) % size].pr < value.pr)) {
                if (arr[j % size].pr == value.pr) {
                    arr[(j++) % size] = value;
                    break;
                }
                arr[(j + 1) % size] = arr[j % size];
                j--;
            }
            arr[(j++ + 1) % size] = value;
            break;
        }
    }
    T pop() {
        return arr[(frst++) % size];
    }
};
struct SYM {
    char ch;
    int pr;
};
#endif  // INCLUDE_TPQUEUE_H_
