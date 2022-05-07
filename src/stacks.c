#include "../includes/push_swap.h"

t_psnode *ft_create_node()
{
    t_psnode *node;

    node = (t_psnode *)malloc(sizeof(t_psnode));
    node->next = NULL;
    return (node);
}

t_psnode *ft_stack_a(int argc, char **argv)
{
    int i;
    t_psnode *head;
    t_psnode *temp;

    head = NULL;
    if(argc > 1)
    {
        head = ft_create_node();
        temp = head;
        i = 1;
        while(i < argc)
        {
            temp->num = ft_atoi(argv[i]);
            if(i != argc - 1)
                temp->next = ft_create_node();
            temp = temp->next;
            i++;
        }
    }
    return (head);
}

void ft_rrr(t_psnode **stack_a, t_psnode **stack_b)
{
    ft_reverse_rotate(stack_a);
    ft_reverse_rotate(stack_b);
    write(1, "rrr\n", 4);
}