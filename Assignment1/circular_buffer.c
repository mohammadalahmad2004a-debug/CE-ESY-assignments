#include <stdio.h>
#include <string.h>

#define SIZE 100

// تعريف المخزن الدائري
typedef struct {
    char buffer[SIZE];
    int head;
    int tail;
    int count;
} CircularBuffer;

// التهيئة
void init(CircularBuffer *cb) {
    cb->head = 0;
    cb->tail = 0;
    cb->count = 0;
}

// التحقق إذا ممتلئ
int isFull(CircularBuffer *cb) {
    return (cb->count == SIZE);
}

// التحقق إذا فارغ
int isEmpty(CircularBuffer *cb) {
    return (cb->count == 0);
}

// الكتابة (إدخال)
void write(CircularBuffer *cb, char data) {
    if (isFull(cb)) {
        printf("Buffer Overflow\n");
        return;
    }

    cb->buffer[cb->tail] = data;
    cb->tail = (cb->tail + 1) % SIZE;
    cb->count++;
}

// القراءة (إزالة)
char read(CircularBuffer *cb) {
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
    init(&cb);

    char name[50];

    printf("Enter your name: ");
    scanf("%[^\n]", name);

    // إضافة اللاحقة
    strcat(name, "CE-ESY");

    // إدخال الأحرف إلى المخزن
    for (int i = 0; i < strlen(name); i++) {
        write(&cb, name[i]);
    }

    // القراءة والطباعة
    while (!isEmpty(&cb)) {
        char c = read(&cb);
        printf("%c", c);
    }

    return 0;
}
