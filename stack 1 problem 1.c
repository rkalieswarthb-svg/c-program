#include <stdio.h>
#include <stdlib.h>

#define MAX 100 
typedef struct {
    int pages[MAX];
    int top;
} BrowserHistory;
void init(BrowserHistory *s) {
    s->top = -1; 
}
int isEmpty(BrowserHistory *s) {
    return s->top == -1;
}
void push(BrowserHistory *s, int pageID) {
    if (s->top == MAX - 1) {
        printf("History full! Cannot track more pages.\n");
        return;
    }
    s->pages[++(s->top)] = pageID;
    printf("Opened page: %d\n", pageID);
}
void pop(BrowserHistory *s) {
    if (isEmpty(s)) {
        printf("No pages in history to go back to.\n");
        return;
    }
    printf("Back pressed -> removed %d\n", s->pages[s->top--]);
}
int peek(BrowserHistory *s) {
    if (isEmpty(s)) {
        return -1;
    }
    return s->pages[s->top];
}
int size(BrowserHistory *s) {
    return s->top + 1;
}

int main() {
    BrowserHistory history;
    init(&history);
    push(&history, 101);
    push(&history, 102);
    push(&history, 103);

    pop(&history); 

    int current = peek(&history);
    if (current != -1) {
        printf("Current page -> %d\n", current);
    }
    
    printf("Total pages in history: %d\n", size(&history));

    return 0;
}