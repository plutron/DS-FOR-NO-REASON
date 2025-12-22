#include <stdio.h>



#define STACK_SIZE 1000

struct stack {
    int data[STACK_SIZE];
    int counter;
};

int push(struct stack *s, int data) {
    if (s->counter == STACK_SIZE) {
        printf("Stack is full\n");
        return 0;
    }
    s->data[s->counter++] = data;
    return 1;
}

int pop(struct stack *s, int *data) {
    if (s->counter == 0) {
        printf("Stack is empty\n");
        return 0;
    }
    *data = s->data[--s->counter];
    return 1;
}

int main() {
    struct stack s;
    s.counter = 0;

    push(&s, 10);
    push(&s, 20);

    int data;

    if (pop(&s, &data))
        printf("%d\n", data);

    if (pop(&s, &data))
        printf("%d\n", data);

    return 0;
}

