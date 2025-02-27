/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ainthana <ainthana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 17:02:16 by ainthana          #+#    #+#             */
/*   Updated: 2025/02/27 23:16:48 by ainthana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	add_node(t_stack *stack, t_node *new_node)
{
	t_node	*current;

	if (!stack->head)
		stack->head = new_node;
	else
	{
		current = stack->head;
		while (current->next)
			current = current->next;
		current->next = new_node;
	}
	stack->size++;
}

int create_node(t_stack *stack, char *str, size_t start)
{
    long value;

    if (!check_word(str + start))
        return 0;
    value = parse_args(str + start);
    if (value == 0)
    {
        if (str[start] == '0' && (str[start + 1] == '\0' || str[start + 1] == ' '))
        {
            t_node *new_node = ft_lstnew((int)value);
            if (!new_node)
                return 0;
            add_node(stack, new_node);
            return 1;
        }
        return 0;
    }
    t_node *new_node = ft_lstnew((int)value);
    if (!new_node)
        return 0;
    add_node(stack, new_node);
    return 1;
}


t_node	*ft_lstnew(int value)
{
	t_node	*ptr;

	ptr = malloc(sizeof(t_node));
	if (!ptr)
		return (NULL);
	ptr->value = value;
	ptr->index = 0;
	ptr->next = NULL;
	return (ptr);
}

int	ft_lstsize(t_node *head)
{
	int	count;

	count = 0;
	while (head)
	{
		count++;
		head = head->next;
	}
	return (count);
}
