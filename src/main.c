/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ainthana <ainthana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 10:39:20 by ainthana          #+#    #+#             */
/*   Updated: 2025/02/28 02:20:36 by ainthana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int main(int argc, char **argv)
{
    t_stack *stack_a;
    t_stack *stack_b;
    int i;
    int num;

    if (argc < 2)
        return (1);
    stack_a = malloc(sizeof(t_stack));
    stack_b = malloc(sizeof(t_stack));
    if (!stack_a || !stack_b)
    {
        free(stack_a);
        free(stack_b);
        return (1);
    }
    stack_a->head = NULL;
    stack_b->head = NULL;
    stack_a->size = 0;
    stack_b->size = 0;
    if (argc == 2)
        i = 0;
    else
        i = 1;
    while (argv[i])
    {
        num = ft_atol(argv[i]);
        if (num < INT_MIN || num > INT_MAX || ft_is_duplicate(num, argv, i))
        {
            free_stack(stack_a);
            free_stack(stack_b);
            print_error();
            return (1);
        }
        else if (!create_node(stack_a, argv[i]))
        {
            free_stack(stack_a);
            free_stack(stack_b);
            return (1);
        }
        i++;
    }
    index_stack(stack_a);
    print_stack(stack_a, 'a');
    free_stack(stack_a);
    free_stack(stack_b);
    return (0);
}
