/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpirozzi <giovannipirozzi12345@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 18:06:20 by gnicolo           #+#    #+#             */
/*   Updated: 2025/05/20 16:49:32 by gpirozzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Swaps the values of two integers.
 *
 * @param a Pointer to the first integer.
 * @param b Pointer to the second integer.
 */
void	swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * @brief Sorts a linked list of t_stack nodes in ascending order based on the 'nbr' field.
 *
 * Uses a simple bubble sort algorithm swapping the values inside nodes.
 *
 * @param tmp Double pointer to the head of the list to sort.
 */
static void	sort_list(t_stack **tmp)
{
	t_stack	*stack_v;

	stack_v = (*tmp);
	while (stack_v->next)
	{
		if (stack_v->nbr > stack_v->next->nbr)
		{
			swap(&(stack_v->nbr), &(stack_v->next->nbr));
			stack_v = (*tmp);
		}
		else
			stack_v = stack_v->next;
	}
}

/**
 * @brief Assigns an index to each element in stack 'a' based on its sorted position.
 *
 * Sorts a duplicate list 'tmp', then iterates over the original stack 'a' and assigns
 * the index corresponding to the position of its 'nbr' value in the sorted list.
 * Frees the temporary sorted list after indexing.
 *
 * @param a Double pointer to the original stack.
 * @param tmp Double pointer to a duplicate of the stack, used for sorting.
 */
void	ft_index_list(t_stack **a, t_stack **tmp)
{
	t_stack	*head_a;
	t_stack	*head_tmp;
	int		i;

	sort_list(tmp);
	head_a = (*a);
	head_tmp = (*tmp);
	i = 0;
	while (head_a && head_tmp)
	{
		if (head_a->nbr == head_tmp->nbr)
		{
			head_a->index = i;
			i = 0;
			head_tmp = (*tmp);
			head_a = head_a->next;
		}
		else
		{
			i++;
			head_tmp = head_tmp->next;
		}
	}
	free_stack(tmp);
}
