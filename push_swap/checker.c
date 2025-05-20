/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpirozzi <giovannipirozzi12345@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 15:49:34 by gpirozzi          #+#    #+#             */
/*   Updated: 2025/02/28 13:37:14 by gpirozzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_bank_data(t_stack **a, char **numbers, int flags)
{
	if (flags == 1)
	{
		init_stack_a(a, numbers, 0);
		ft_clean_matrix(numbers);
	}
	else
		init_stack_a(a, numbers, 0);
}

static int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	return (1);
}

void	ft_moves2(t_stack *a, t_stack *b, char *line)
{
	if (ft_strcmp(line, "rrb\n"))
		rrb(&b);
	else if (ft_strcmp(line, "rrr\n"))
		rrr(&a, &b);
	else if (ft_strcmp(line, "pa\n"))
		pa(&a, &b);
	else if (ft_strcmp(line, "pb\n"))
		pb(&a, &b);
	else
	{
		ft_printf("Error\n");
		free(line);
		exit(1);
	}
}

void	ft_moves(t_stack *a, t_stack *b)
{
	char	*line;

	line = get_next_line(0);
	while (line != NULL)
	{
		if (ft_strcmp(line, "ra\n"))
			ra(&a);
		else if (ft_strcmp(line, "rb\n"))
			rb(&b);
		else if (ft_strcmp(line, "rr\n"))
			rr(&a, &b);
		else if (ft_strcmp(line, "sa\n"))
			sa(&a);
		else if (ft_strcmp(line, "sb\n"))
			sb(&b);
		else if (ft_strcmp(line, "ss\n"))
			ss(&a, &b);
		else if (ft_strcmp(line, "rra\n"))
			rra(&a);
		else
			ft_moves2(a, b, line);
		free(line);
		line = get_next_line(0);
	}
}

int	main(int argc, char **argv)
{
	t_stack			*a;
	t_stack			*b;
	char			**numbers;
	char			*line;

	a = NULL;
	b = NULL;
	line = NULL;
	if (argc <= 1)
		return (ft_printf("\n"));
	else if (argc == 2)
	{
		numbers = ft_split(argv[1], ' ');
		ft_bank_data(&a, numbers, 1);
	}
	else if (argc > 2)
		ft_bank_data(&a, &argv[1], 0);
	ft_moves(a, b);
	if (stack_sorted(a))
		return (ft_printf("OK"), 0);
	else
		return (ft_printf("KO"), 1);
}
