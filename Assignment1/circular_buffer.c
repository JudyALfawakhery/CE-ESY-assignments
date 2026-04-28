#include <stdio.h>
#include <string.h>

#define SIZE 30


typedef struct {
    char buffer[SIZE];
    int head;
    int tail;
    int count;
} CircularBuffer;

void init(CircularBuffer *cb) {
    cb->head = 0;
    cb->tail = 0;
    cb->count = 0;
}

int isFull(CircularBuffer *cb) {
    return cb->count == SIZE;
}

int isEmpty(CircularBuffer *cb) {
    return cb->count == 0;
}

void writeBuffer(CircularBuffer *cb, char data) {
    if (isFull(cb)) {
        printf("Buffer Overflow\n");
        return;
    }

    cb->buffer[cb->tail] = data;
    cb->tail = (cb->tail + 1) % SIZE;
    cb->count++;
}

char readBuffer(CircularBuffer *cb) {
    if (isEmpty(cb)) {
        printf("Buffer Underflow\n");
        return '\0';
    }

    char data = cb->buffer[cb->head];
    cb->head = (cb->head + 1) % SIZE;
    cb->count--;

    return data;
}

int main() {
    CircularBuffer cb;
    char name[50];
    char text[80];
    int i;

    init(&cb);

    printf("Enter your name: ");
    scanf("%49s", name);

    strcpy(text, name);
    strcat(text, "CE-ESY");

    printf("\nText to store: %s\n", text);

    for (i = 0; text[i] != '\0'; i++) {
        if (isFull(&cb)) {
            printf("Buffer Overflow\n");
            break;
        }

        writeBuffer(&cb, text[i]);
    }

    printf("Data read from buffer: ");

    while (!isEmpty(&cb)) {
        printf("%c", readBuffer(&cb));
    }

    printf("\n");

    if (isEmpty(&cb)) {
        printf("Buffer is empty now.\n");
    }

    return 0;
}