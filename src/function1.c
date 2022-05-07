#include "../includes/push_swap.h"

int ft_checker(t_psnode *stack_a, int num)
{
    t_psnode *temp;

    temp = stack_a;
    while(temp)
    {
        if(temp->index > num)
            return 1;
        temp = temp->next;
    }
    return (0);
}

void ft_get_maxes(t_pushswap_data *psdata)
{
    psdata->maxs[0].num = psdata->len_b - 1;
    if(psdata->len_b > 1)
        psdata->maxs[1].num = psdata->len_b - 2;
}

void    ft_getpos(t_pushswap_data *psdata)
{
    int i;
    int j;
    t_psnode *temp;

    i = 1;
    temp = psdata->stack_b;
    while(temp)
    {
        j = 0;
        while(j < psdata->maxs_len)
        {
            if(temp->index == psdata->maxs[j].num)
            {
                if(i > psdata->len_b / 2)
                {
                    psdata->maxs[j].pos = psdata->len_b - (i - 1);
                    psdata->maxs[j].side = 2;
                }
                else
                {
                    psdata->maxs[j].pos = i;
                    psdata->maxs[j].side = 1;
                }
            }
            j++;
        }
        i++;
        temp = temp->next;
    }
}

t_maxs    *ft_getmov(t_pushswap_data *psdata)
{
    int i;
    t_maxs *min_pos;

    i = 0;
    while(1)
    {
        if(psdata->maxs[i].pos != 0)
        {
            min_pos = &psdata->maxs[i];
            break ;
        }
        i++;
    }
    
    i = 0;
    while(i < psdata->maxs_len)
    {
       if(psdata->maxs[i].pos != 0 && psdata->maxs[i].pos <= min_pos->pos)
            min_pos = &psdata->maxs[i];
        i++;
    }
    min_pos->pos = 0;
    return (min_pos);
}

void    ft_push_bta(t_pushswap_data *psdata)
{
    int i;
    t_maxs *pusher;

    while(psdata->len_b)
    {
        ft_get_maxes(psdata);
        i = 0;
        while(i < psdata->maxs_len && psdata->len_b)
        {
            ft_getpos(psdata);
            pusher = ft_getmov(psdata);
            while (psdata->stack_b)
            {
                if(psdata->stack_b->next && psdata->stack_b->next->index == pusher->num)
                    ft_swap_b(&psdata->stack_b);
                if(psdata->stack_b->index == pusher->num)
                {
                    ft_push_a(&psdata->stack_a, &psdata->stack_b);
                    if(psdata->len_a && psdata->stack_a->index > psdata->stack_a->next->index)
                        ft_swap_a(&psdata->stack_a);
                    break ;
                }
                else if(pusher->side == 1)
                    ft_rotate_b(&psdata->stack_b);
                else
                    ft_rrb(&psdata->stack_b);
            }
            i++;
            psdata->len_b--;
            psdata->len_a++;
        }
    }
}