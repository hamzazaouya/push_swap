#include <stdio.h> 
#include <stdlib.h>  

typedef struct node
{
    int num;
    struct node *next;
} t_node;

t_node *ft_create_node(int num){
    t_node *node;

    node = (t_node *)malloc(sizeof(t_node));
    node->num = num;
    node->next = NULL;
    return (node);
}

t_node *ft_create_list(int size, int *arr)
{
    t_node *head;
    t_node *temp;
    int     i;

    head = (t_node *)malloc(sizeof(t_node));
    head = ft_create_node(arr[0]);
    temp = head;
    i = 1;
    while(i < size)
    {
        printf("|%d| %d %d\n", arr[i], temp->num, size);
        temp->next = ft_create_node(arr[i++]);
        temp = temp->next;
        
    }
    temp->next = NULL;
    return (head);
}

int main(void)
{
    t_node *head = NULL;
    int arr[5] = {3, 4, 5, 6, 7};

    head = ft_create_list(5, arr);
    while(head){
        printf("%d\n", head->num);
        head = head->next;
    }
    return 0;
}