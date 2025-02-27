/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ainthana <ainthana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 18:21:00 by ainthana          #+#    #+#             */
/*   Updated: 2025/02/27 18:21:00 by ainthana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_node	**splitlst(char *str, t_stack *stack)
{
    long int    num;
    size_t        i;
	t_node		new_node;

    i = 0;
    while (str && str[i] == ' ')
        i ++;
    while (str && str[i])
    {
        num = parse_args(str + i);
        if (num < -2147483648 || num > 2147483647 || !check_args(str))
        {
            free_stack(stack);
            return (NULL);
        }
        else
        {
            create_node(stack, str);
            while (str[i] && str[i] != ' ')
                i ++;
            while (str[i] == ' ')
                i ++;
        }
    }
    return (new_node);
}
