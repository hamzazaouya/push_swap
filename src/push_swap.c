#include "../includes/push_swap.h"

void    ft_print(t_psnode *list)
{
    t_psnode *temp1;

    temp1 = list;
    while(temp1)
    {
        printf("|%-6d\n", temp1->num);
        temp1 = temp1->next;
    }
}

void ft_init(int argc, char **argv, t_pushswap_data *psdata)
{
    psdata->argc = argc;
    psdata->stack_a = ft_stack_a(argc, argv);
    psdata->stack_b = NULL;
    psdata->stack_a->index = -1;
    psdata->len_a = argc - 1;
    psdata->len_b = 0;
    psdata->maxs_len = 2;
    psdata->maxs = (t_maxs *)malloc(sizeof(t_maxs) * psdata->maxs_len);
}

 int *ft_fill_arr(t_pushswap_data *psdata)
 {
     int *arr;
     int i;
     t_psnode *temp;

    arr = (int *)malloc(sizeof(int) * psdata->len_a);
    temp = psdata->stack_a;
    i = -1;
    while(++i < psdata->len_a)
    {
        arr[i] = temp->num;
        temp = temp->next;
    }
    return arr;
 }

 void  ft_sort_arr(int *arr, int len)
 {
    int i;
    int temp;

    i = 0;
    while(i < len - 1)
    {
        if(arr[i] > arr[i + 1]){
            temp = arr[i];
            arr[i] = arr[i + 1];
            arr[i + 1] = temp;
            i = 0;
            continue;
        }
        i++;
    }
 }

int ft_serch_arr(int *arr, int num)
{
    int i;

    i = 0;
    while(1)
    {
        if(arr[i] == num)
            return (i);
        i++;
    }
}

void ft_index_stack_a(t_pushswap_data *psdata)
{
    int *aide_arr;
    t_psnode *temp;

    temp = psdata->stack_a;
    aide_arr = ft_fill_arr(psdata);
    ft_sort_arr(aide_arr, psdata->len_a);
    while(temp)
    {
        temp->index = ft_serch_arr(aide_arr, temp->num);
        temp = temp->next;
    }
    free(aide_arr);
}

void    ft_pushswap(t_pushswap_data *psdata)
{
    ft_index_stack_a(psdata);
    ft_push_atb(psdata);
    ft_push_bta(psdata);
    /*t_psnode *temp;
    temp = psdata->stack_b;
    while(temp){
        printf("%-10d   %d\n", temp->num, temp->index);
        temp = temp->next;
    }*/
}

void    ft_check_input(int argc, char **argv)
{
    int i;
    int j;

    i = 1;
    if (argc == 1)
        exit(0);
    while(i < argc)
    {
        j = i + 1;
        while(j < argc)
        {
            if(!ft_strcmp(argv[i], argv[j]))
                exit(0);
            j++;
        }
        i++;
    }
}

int main(int argc, char **argv)
{
    t_pushswap_data psdata;
    ft_check_input(argc, argv);
    ft_init(argc, argv, &psdata);
    ft_pushswap(&psdata);
}   