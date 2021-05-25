// Copyright 2021 NNTU-CS
#include <iostream>
#include <cassert>
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
struct SYM {
    char ch;
    int prior;
};
template <typename T>
class TPQueue {
    struct ITEM {
        T data;
        ITEM* next;
    };
 public:
    TPQueue() : head(nullptr), tail(nullptr) {}
    ~TPQueue();
    void push(const T&);
    T pop();
    void print()const;
 private:
    TPQueue::ITEM* create(const T&);
    ITEM* head;
    ITEM* tail;
};
template<typename T>
TPQueue<T>::~TPQueue() {
    while (head) {
        pop();
    }
}

template<typename T>
typename TPQueue<T>::ITEM* TPQueue<T>::create(const T& S) {
    ITEM* M = new ITEM;
    M->data = S;
    M->next = nullptr;
    return M;
}
template <typename T>
void TPQueue<T>::push(const T& A) {
    if (head) {
        if (head->data.prior < A.prior) {
            auto* temp = head;
            head = create(A);
            head->next = temp;
            return;
        }
        ITEM* Illya = this->head;
        while (Illya->next != nullptr) {
            if (Illya->next->data.prior < A.prior) {
                auto *temp = I->next;
                I->next = create(A);
                I->next->next = temp;
                return;
            }
            I = I->next;
        }
        I->next = create(A);
        tail = I->next;
    } else {
        head = create(A);
        tail = head;
    }
}
template<typename T>
T TPQueue<T>::pop() {
    if (head) {
        T S = head->data;
        head = head->next;
        return S;
    }
}
template <typename T>
void TPQueue<T>::print() const {
    ITEM* B = head;
    while (B) {
        std::cout << B->data.ch << std::endl;
        B = B->next;
    }
    std::cout << std::endl;
}
#endif // INCLUDE_TPQUEUE_H_
