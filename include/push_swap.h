/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ainthana <ainthana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 12:40:03 by ainthana          #+#    #+#             */
/*   Updated: 2025/02/25 01:02:11 by ainthana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../ft_printf/ft_printf.h"

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <fcntl.h>
#include <limits.h>

typedef struct s_node
{
	int				value;
	struct s_node	*next;
	int				index;
}	t_node;

typedef struct s_stack
{
	int				size;
	struct s_node	*head;
}	t_stack;

//move_stack
void	ft_push(t_stack *src, t_stack *dst, char c);
void	ft_reverse_rotate(t_stack *lst, char c);
void	ft_reverse_rotate_both(t_stack *a, t_stack *b);
void	ft_rotate(t_stack *lst, char c);
void	rotate_both(t_stack *stack_a, t_stack *stack_b);
void	ft_swap(t_stack *lst, char c);
void	swap_both(t_stack *stack1, t_stack *stack2);

//utils
void	print_stack(t_stack *stack, char name);
void	free_stack(t_stack *stack);
t_node	*ft_lstnew(int value);
int		create_node(t_stack *stack, char *str, size_t start, size_t end);
void	add_node(t_stack *stack, t_node *new_node);
int		ft_lstsize(t_node *head);

//verif
int		ft_isdigit(int c);
long	ft_atol(char *nb);
char	*ft_putword(char const *s, size_t start, size_t end);
t_node    **splitlst(char *str, t_node **lst);
long int    transcheck(char *str);
char    *subcopy(char *str, size_t len);
int		ft_is_duplicate(int nb, char **argv, int i);
char    **verif_args(int argc, char **argv);

#endif
