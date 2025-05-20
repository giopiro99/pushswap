/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpirozzi <giovannipirozzi12345@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 12:53:56 by gnicolo           #+#    #+#             */
/*   Updated: 2025/05/20 16:47:03 by gpirozzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Rotates the stack downwards by moving the last element to the front.
 *
 * The last node becomes the new head, and the rest of the stack shifts down.
 *
 * @param head Double pointer to the head of the stack.
 */
static void	reverse_rotate(t_stack **head)
{
	t_stack	*current;
	t_stack	*last;
	t_stack	*second_last;

	if (!(*head) || !(*head)->next)
		return ;
	current = *head;
	while (current->next && current->next->next)
		current = current->next;
	second_last = current;
	last = current->next;
	second_last->next = NULL;
	last->next = *head;
	*head = last;
}

/**
 * @brief Reverses rotation on stack A and prints "rra".
 *
 * Moves the bottom element of stack A to the top.
 *
 * @param a Double pointer to stack A.
 */
void	rra(t_stack **a)
{
	reverse_rotate(a);
	ft_printf(1,"rra\n");
}

/**
 * @brief Reverses rotation on stack B and prints "rrb".
 *
 * Moves the bottom element of stack B to the top.
 *
 * @param b Double pointer to stack B.
 */
void	rrb(t_stack **b)
{
	reverse_rotate(b);
	ft_printf(1, "rrb\n");
}

/**
 * @brief Reverses rotation on both stacks A and B and prints "rrr".
 *
 * Moves the bottom element of both stacks A and B to the top.
 *
 * @param a Double pointer to stack A.
 * @param b Double pointer to stack B.
 */
void	rrr(t_stack **a, t_stack **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	ft_printf(1, "rrr\n");
}
