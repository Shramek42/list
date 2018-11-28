#ifndef _LIST_H_
#define _LIST_H_
#include "algorithm"

template <class val>
struct node {
    val data;
    node <val> *next;
};

template <class val>
class list {
 private:
    node <val> *head;
    node <val> *end;
    int size;
 public:
    list();
    node <val> *find(val el);
    void insert(val el);
    void del(val el);
    void sort();
    void swap(val a, val b);
};

template <class val>
list <val>::list() {
    head = NULL;
    end = NULL;
    size = 0;
}

template <class val>
void list <val>::insert(val el) {
    node <val> *temp = new node <val>();
    temp -> data = el;
    temp -> next = NULL;
    if (head == NULL) {
        head = temp;
        return;
    }
    end -> next = temp;
    end = temp;
    size++;
    return;
}

template <class val>
void list <val>::del(val el) {
    if (head == NULL) {
        return;
    } else {
        node <val> *temp = head;
        if (head -> data == el) {
            head = head -> next;
            delete temp;
            size--;
        } else {
            while (temp -> next != NULL) {
                if (temp -> next -> data == el)	{
                    node <val> *c = temp -> next;
                    temp -> next = temp -> next -> next;
                    delete c;
                    size--;
                } else {
                    temp = temp -> next;
                }
            }
        }
    }
}

template <class val>
node <val>* list <val>::find(val el) {
    node <val> *temp = head;
    while (temp != NULL) {
        if (temp -> data == el) {
            return temp;
        } else {
            temp = temp -> next;
        }
    }
    return temp;
}

template <class val>
void list <val>::swap(val a, val b) {
    node <val> *temp1 = find(a);
    node <val> *temp2 = find(b);
    if (temp1 == NULL || temp2 == NULL) {
        return;
    }
    std::swap(temp1 -> data, temp2 -> data);
}


template <class val>
void list <val>::sort() {
    node <val> *f = head;
    while (f != end) {
        val min_val  = f -> data;
        node <val> *temp = f;
        while (temp != end) {
            min_val = min(min_val, temp -> next -> data);
        }
        swap(min_val, f -> data);
        f = f -> next;
    }
}
#endif
