#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node *next;
} Node;


Node *head = NULL;

void push(Node **head, int data) { // добавление в начало
    Node *tmp = (Node*) malloc(sizeof(Node));
    tmp->value = data;
    tmp->next = (*head);
    (*head) = tmp;
}

int pop(Node **head) { // удаление с начала
    Node* prev = NULL;
    int val;
    if (head == NULL) {
        exit(-1);
    }
    prev = (*head);
    val = prev->value;
    (*head) = (*head)->next;
    free(prev);
    return val;
}


Node* get_N(Node* head, int n) { // нахождение n-го элемента списка, перебором всех элементов.
    int counter = 0;
    while (counter < n && head) {
        head = head->next;
        counter++;
    }
    return head;
}

int delete_N(Node **head, int n) { //удаление по индексу
    if (n == 0) {
        return pop(head);
    } else {
        Node *prev = get_N(*head, n-2);
        Node *elm  = prev->next;
        int val = elm->value;

        prev->next = elm->next;
        free(elm);
        return val;
    }
}

Node* LAST_element(Node *head) { // нахождение последнего элемента перебором друг за другом элементов до тех пор,
    // пока указатель next одного из элементов != NULL
    if (head == NULL) {
        return NULL;
    }
    while (head->next) {
        head = head->next;
    }
    return head;
}

void pushBack(Node *head, int value) { // добавление в конец
    Node *last = LAST_element(head);
    Node *tmp = (Node*) malloc(sizeof(Node));
    tmp->value = value;
    tmp->next = NULL;
    last->next = tmp;
}

//[new] -> [] -> [] -> NULL
void insert(Node *head, unsigned n, int val) {
    unsigned i = 0;
    Node *tmp = NULL;

    while (i < n && head->next) {
        head = head->next;
        i++;
    }
    tmp = (Node*) malloc(sizeof(Node));
    tmp->value = val;

    if (head->next) {
        tmp->next = head->next;

    } else {
        tmp->next = NULL;
    }
    head->next = tmp;
}
// [head] -> [2, next] -> [3, next] -> NULL


void printList(const Node *head) {
    while(head) {
        printf("%d ", head->value);
        head = head->next;
    }
    printf("\n");
}


int main(void) {
    Node *head = NULL;
    int one, n;
    printf("Количество элементов?\n");
    scanf("%d", &n);

    printf("Введите элементы списка:\n");
    scanf("%d", &one);
    push(&head, one);

    for (int i = 0; i < (n-1); i++) {
        int data;
        scanf("%d", &data);
        pushBack(head, data);
    }
    printf("Список:\n");
    printList(head);

    printf("Вставка в середину:\n");
    insert(head, (n/2)-1, 7);
    printList(head);

    printf("Удаление по элементу (эл. №2):\n");
    delete_N(&head, 2);
    printList(head);

    printf("Удаление с начала:\n");
    pop(&head);
    printList(head);
}


