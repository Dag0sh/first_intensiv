#ifndef SRC_STACK_H_
#define SRC_STACK_H_

struct stack {
    char num;
    struct stack *next;
};

struct stack *init(int num);
void push(struct stack **last, char ch);
char pop(struct stack **last);
void destroy(struct stack **last);
int priority(char x);
char *inputString();
int isEmpty(struct stack *st);
#endif  
