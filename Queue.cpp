//
// Created by ilyak on 29.05.2022.
//

#include <string>
#include <stdexcept>
#include "Queue.h"

Queue::Queue() {
    head = nullptr;
    tail = nullptr;
}

Queue::~Queue() {
    while (head != nullptr) {
        QueueElement *e = head;
        head = head->next;
        delete e;
    }
}

std::string Queue::dequeue() {
    if (head == nullptr) {
        throw std::out_of_range("Queue is empty");
    }
    std::string result = head->string;
    QueueElement *e = head;
    head = head->next;
    if (head == nullptr) {
        tail = nullptr;
    }
    delete e;
    return result;

}

void Queue::enqueue(std::string str) {
    QueueElement *e = new QueueElement();
    e->string = str;
    if (head == nullptr) {
        head = e;
        tail = e;
    } else {
        tail->next = e;
        tail = e;
    }

}

bool Queue::isEmpty() {
    return head == nullptr;

}

Queue::Queue(const Queue &other) {
    QueueElement *o = other.head;
    while (o != nullptr) {
        enqueue(o->string);
        o = o->next;
    }
}

Queue &Queue::operator=(const Queue &other) {
    if (&other == this)
        return *this;
    QueueElement *o = other.head;
    while (o != nullptr) {
        enqueue(o->string);
        o = o->next;
    }
    return *this;
}
