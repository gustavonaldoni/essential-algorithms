struct Node
{
    int data;
    struct Node *next;
};

typedef struct
{
    struct Node *top;
} Stack;

void StackCreate(Stack *);
bool StackIsEmpty(Stack);
bool StackPush(Stack *, int);
void StackShow(Stack);
int StackPop(Stack *);
int StackTop(Stack);

int StackCountElements(Stack);
int StackSizeOf(Stack);

void StackCreate(Stack *stack)
{
    stack->top = NULL;
}

bool StackIsEmpty(Stack stack)
{
    return stack.top == NULL;
}

bool StackPush(Stack *stack, int data)
{
    struct Node *aux;

    aux = (struct Node *)malloc(sizeof(struct Node));

    if (aux == NULL)
        return false;

    aux->data = data;
    aux->next = stack->top;
    stack->top = aux;

    return true;
}

void StackShow(Stack stack)
{
    struct Node *aux;
    aux = stack.top;

    if (StackIsEmpty(stack))
    {
        printf("Stack is empty ...\n");
    }

    else
    {
        while (aux != NULL)
        {
            printf("Data: %d\n", aux->data);
            aux = aux->next;
        }
    }
}

int StackCountElements(Stack stack)
{
    int counter;
    struct Node *aux;

    counter = 0;
    aux = stack.top;

    if (StackIsEmpty(stack))
    {
        return -1;
    }

    else
    {
        while (aux != NULL)
        {
            counter += 1;
            aux = aux->next;
        }
    }

    return counter;
}

int StackSizeOf(Stack stack)
{
    int numberOfElements;
    struct Node aux;

    if (StackIsEmpty(stack))
        return 0;

    numberOfElements = StackCountElements(stack);
    return sizeof(stack) + sizeof(aux) * numberOfElements;
}

int StackPop(Stack *stack)
{
    struct Node *aux;

    if (stack->top == NULL)
        return -1;

    aux = stack->top;
    stack->top = aux->next; 

    aux->data = 0;
    aux->next = NULL;

    free(aux);

    return aux->data;

}

int StackTop(Stack stack)
{
    if (StackIsEmpty(stack))
        return -1;

    return stack.top->data;
}