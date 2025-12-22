#include <stdio.h>


struct stack{
	int data[1000];
	int counter;
};

int pop(struct stack *s){
	if(s->counter == 0) {printf("stack is empty");return 1;}
	s->counter --;
	return s->data[s->counter];
	
}

int push(struct stack *s,int data){
	if(s->counter == 1000){printf("stack is full");return 1;}
	s->data[s->counter] = data;
	s->counter ++;
	return 0;
}


int main(){
    struct stack s;
    s.counter = 0;

    push(&s, 10);
    push(&s, 20);

    printf("%d\n", pop(&s));
    printf("%d\n", pop(&s));

    
}
