#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *head = NULL;
void pop()
{
    if (head == NULL)
    {
        printf("stack is empty");
    }
    else
    {
        struct node *temp;
        temp = head;
        printf("%d is poped\n", temp->data);
        head = head->next;
        free(temp);
    }
}
void push(int data)
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = head;
    head = newnode;
}
void peek()
{
    printf("peek value is %d\n", head->data);
}
void display()
{
    struct node *temp;
    temp = head;
    if (head == NULL)
    {
        printf("stack is empty");
    }
    else
    {
        while (temp != NULL)
        {
            printf("%d->", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
        free(temp);
    }
}
int main()
{
    int m, ch, data;
    do
    {
        printf("1 push\n2 display\n3 pop\n4 peek\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("enter the element to push");
            scanf("%d", &data);
            push(data);
            break;
        case 2:
            display();
            break;
        case 3:
            pop();
            break;
        case 4:
            peek();
            break;
        default:
            printf("enter valid choice");
        }

    } while (m != 0);
    return 0;
}
