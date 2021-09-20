#include <iostream>

const int n = 6;
int matrix[n][n] = {
    {0,1,1,0,0,0},
    {0,0,0,1,1,1},
    {0,0,0,0,0,1},
    {1,0,0,0,0,0},
    {0,0,0,0,0,0},
    {0,0,0,0,1,0},
};

int visited[n] = { 0 };

void resetArr() {
    for (size_t i = 0; i < n; i++)
    {
        visited[i] = 0;
    }
}

typedef struct Node {
    int data;
    Node* next;
} Node;

typedef struct {
    Node* head;
    int size;
}Stack;

void init(Stack* stack) {
    stack->head = NULL;
    stack->size = 0;
}

bool push(Stack* stack, int st) {
    Node* tmp = (Node*)malloc(sizeof(Node));
    if (tmp==NULL)
    {
        std::cout << "Stack overflow";
        return 0;
    }
    tmp->data = st;
    tmp->next = stack->head;
    stack->head = tmp;
    stack->size++;
    return true;
}

int pop(Stack* stack) {
    if (stack->size==0)
    {
        //std::cout << "Stack is empty";
        return -1;
    }
    Node* tmp = stack->head;
    int st = stack->head->data;
    //int tmp2 = stack->head->next->data;
    stack->head = stack->head->next;
    free(tmp);
    stack->size--;
    return st;
}

void check(Stack* stack,int st) {
    int r;
    int temp;
    std::cout << st << " ";
    push(stack, st);
    visited[st] = 1;
    for (size_t i = 0; i < n; i++)
    {
        st = pop(stack);
        for (r = 0; r < n; )
        {
            if (matrix[st][r] == 1 && !visited[r])
            {
                std::cout << r << " ";
                visited[r] = 1;
                push(stack, r);
                if (matrix[st][r+1] ==1)
                {
                    push(stack, r);
                }
                st = r;
                r = 0;
            }
            else
            {
                r++;
            }
        }
    }
}

int checkhead(int st) {
    int p = 0;
    for (int r = 0; r < n; r++)
    {
        if (matrix[st][r] == 1)
        {
            p++;
        }
    }
    return p;
}


int arr[n];
void linkc() {
    for (size_t j = 0; j < n; j++)
    {
        for (size_t i = 0; i < n; i++)
        {
            if (matrix[j][i] == 1)
            {
                arr[i] += 1;
            }
        }
    }
}

int main()
{
    //////// exercise 1

    Stack* stack=(Stack*) malloc(sizeof(Stack));
    init(stack);
    check(stack,1);
    resetArr();
    std::cout << std::endl;
    ////////////

    //////exercise 2

    std::cout << checkhead(1) << std::endl;

    linkc();

    for (size_t i = 0; i < n; i++)
    {
        std::cout << i << ":" << arr[i] << "," << " ";
    }
    std::cout << std::endl;

    ////////
    system("pause");
    return 0;
}
