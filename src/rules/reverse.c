/* ************************************************************************** */
/*                                                                            */
/*       ::::::    ::::::   :::  ::::::::  ::::::::   :::  ::::::    :::::::  */
/*     :+:   :+: :+:   :+: :+: :+:   :+:  :+:    :+: :+: :+:   :+: :+:    :+: */
/*    +:+       +:+       +:+ +:+   +:+  +:+    +:+     +:+       +:+    +:+  */
/*   +#+       +:+       +#+ +:+   +#+  +:+    +#+ +:+ +#+       +#+:+:+#+:   */
/*  +#+       +#+       +#+   +#+#+#+# #+#+#+#+   +#+ +#+       +#+           */
/* #+#   #+# #+#   #+# #+#            #+#    #+# #+# #+#   #+# #+#    #+#     */
/*  ######    ######  ############## ###    ### ###   ######    #######       */
/*                                                                            */
/* ************************************************************************** */
/*                                                                            */
/*   reverse.c                                cclarice@student.21-school.ru   */
/*                                                                            */
/*   Created/Updated: 2021/05/31 20:12:13  /  2021/05/31 20:12:27 @cclarice   */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

// rra : reverse rotate a - shift down all elements of stack a by 1.
// rrb : reverse rotate b - shift down all elements of stack b by 1.
// rrr : rra and rrb at the same time.
//                                      (The last element becomes the first one)

void	rrta_a(t_sort *sort)
{
	t_elem *last;
	t_elem *prel;

	if (sort->a && sort->a->n)
	{
		prel = sort->a;
		while (prel->n->n)
			prel = prel->n;
		last = prel->n;
		last->n = sort->a;
		prel->n = NULL;
		sort->a = last;
	}
	visual(sort, "rra\n");
}

void	rrta_b(t_sort *sort)
{
	t_elem *last;
	t_elem *prel;

	if (sort->b && sort->b->n)
	{
		prel = sort->b;
		while (prel->n->n)
			prel = prel->n;
		last = prel->n;
		last->n = sort->b;
		prel->n = NULL;
		sort->b = last;
	}
	visual(sort, "rrb\n");
}

void	rrta_r(t_sort *sort)
{
	t_elem *last;
	t_elem *prel;

	if (sort->b && sort->b->n)
	{
		prel = sort->b;
		while (prel->n->n)
			prel = prel->n;
		last = prel->n;
		last->n = sort->b;
		prel->n = NULL;
		sort->b = last;
	}
	if (sort->a && sort->a->n)
	{
		prel = sort->a;
		while (prel->n->n)
			prel = prel->n;
		last = prel->n;
		last->n = sort->a;
		prel->n = NULL;
		sort->a = last;
	}
	visual(sort, "rrr\n");
}
