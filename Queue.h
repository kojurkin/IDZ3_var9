//
// Created by ilyak on 29.05.2022.
//

#ifndef IDZ3_VAR9_QUEUE_H
#define IDZ3_VAR9_QUEUE_H


class Queue {
public:
    Queue();

    Queue(const Queue &other);

    Queue &operator=(const Queue &);

    virtual ~Queue();

    void enqueue(std::string);

    std::string dequeue();

    bool isEmpty();

private:
    struct QueueElement {
        std::string string;
        QueueElement *next;
    };
    QueueElement *head;
    QueueElement *tail;
};


#endif //IDZ3_VAR9_QUEUE_H
