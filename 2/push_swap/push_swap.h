/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yje <yje@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 15:19:19 by yje               #+#    #+#             */
/*   Updated: 2022/11/04 21:38:29 by yje              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdlib.h>
#include <unistd.h>

typedef struct s_node
{
	int				val;
	struct s_node	*left;
	struct s_node	*right;
}	t_node;

typedef struct s_stack
{
	struct s_node	*top;
	struct s_node	*bottom;
}	t_stack;

typedef struct s_var
{
	struct s_stack	*stack_a;
	struct s_stack	*stack_b;
	
} t_var;


/* operationp.c */
void	pa(t_var *stacks);
void	pb(t_var *stacks);

/* operations.c */
void	sa(t_var *stacks);
void	sb(t_var *stacks);
void	ss(t_var *stacks);

/* operations.r */
void	ra(t_var *stacks);
void	rb(t_var *stacks);

/* utils_split.c */
static int	ft_size_check(char const *str, char c);
static int	ft_str_check(char const *str, char c);
void	ft_free(char **arr, int i);
static char	**ft_too_many_lines(char **arr, char const *str, char c, int i);
char	**ft_split(char const *s, char c);

/* utils.c */
size_t	ft_strlen(const char *s);
int	ft_atoi(const char *str);

/* args.c */
char *join_argv(int ac, char **av);
void validate_args(int ac, char **av);

void init_stack(t_var *var);
t_node	*add_new_node(int n);
t_node	*pop_top(t_stack *stack);
t_node	*pop_bottom(t_stack *stack);
void push_top(t_stack *stack, t_node *new_node);
void push_bottom(t_stack *stack, t_node *new_node);


#endif
