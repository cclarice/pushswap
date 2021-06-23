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
/*   whl_sort.c                               cclarice@student.21-school.ru   */
/*                                                                            */
/*   Created/Updated: 2021/06/23 19:26:59  /  2021/06/23 19:29:54 @cclarice   */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	whl_sort_0(t_sort *sort)
{
	t_elem *ptr;
	unsigned int i;

	i = 1;
	push_min_max(sort);
	while (a_has_w(sort->a))
	{
		ptr = get_distances(sort);
		if (sort->lb > sort->l / 2 && ptr->l > sort->l / 20 && i && i--)
		{
			while (sort->lb != 2)
			{
				while (sort->b->i == 0 || sort->b->i == sort->l - 1)
					rota_b(sort);
				sort->b->w = 1;
				push_a(sort);
			}
		}
		ptr = get_distances(sort);
		while (ptr->a)
		{
			if (ptr->a > 0 && ptr->b > 0 && ptr->b-- && ptr->a--)
				rota_r(sort);
			else if (ptr->a > 0 && ptr->a--)
				rota_a(sort);
			else if (ptr->b < 0 && ptr->b++ && ptr->a++)
				rrta_r(sort);
			else if (ptr->a++)
				rrta_a(sort);
		}
		while (ptr->b)
		{
			if (ptr->b > 0 && ptr->b--)
				rota_b(sort);
			else if (ptr->b++)
				rrta_b(sort);
		}
		if (!sort->a->w)
		{
			sort->b->w = 1;
			push_b(sort);
		}
	}
	if (sort->a)
		while (get_distance_index(sort->a, sort->la, get_smallest(sort->a)) != 0)
		{
			if (get_distance_index(sort->a, sort->la, get_smallest(sort->a)) > 0
			 && get_distance_index(sort->b, sort->lb, get_biggest(sort->b)) > 0)
				rota_r(sort);
			else if (get_distance_index(sort->a, sort->la, get_smallest(sort->a)) < 0
			 && get_distance_index(sort->b, sort->lb, get_biggest(sort->b)) < 0)
				rrta_r(sort);
			else if (get_distance_index(sort->a, sort->la, get_smallest(sort->a)) > 0)
				rota_a(sort);
			else
				rrta_a(sort);
		}
	while (get_distance_index(sort->b, sort->lb, get_biggest(sort->b)) != 0)
	{
		if (get_distance_index(sort->b, sort->lb, get_biggest(sort->b)) > 0)
			rota_b(sort);
		else
			rrta_b(sort);
	}
	i = sort->l - 1;
	while (sort->b)
	{
		while (sort->b && sort->b->i == i)
		{
			i--;
			push_a(sort);
		}
		if (sort->al->i == i)
		{
			i--;
			rrta_a(sort);
		}
	}
}

void	whl_sort_1(t_sort *sort)
{
	t_elem *ptr;
	unsigned int i;

	i = 1;
	push_min_max(sort);
	while (a_has_w(sort->a))
	{
		ptr = get_distances(sort);
		if (sort->lb > sort->l / 2 && i && i--)
		{
			while (sort->lb != 2)
			{
				while (sort->b->i == 0 || sort->b->i == sort->l - 1)
					rota_b(sort);
				sort->b->w = 1;
				push_a(sort);
			}
		}
		ptr = get_distances(sort);
		while (ptr->a)
		{
			if (ptr->a > 0 && ptr->b > 0 && ptr->b-- && ptr->a--)
				rota_r(sort);
			else if (ptr->a > 0 && ptr->a--)
				rota_a(sort);
			else if (ptr->b < 0 && ptr->b++ && ptr->a++)
				rrta_r(sort);
			else if (ptr->a++)
				rrta_a(sort);
		}
		while (ptr->b)
		{
			if (ptr->b > 0 && ptr->b--)
				rota_b(sort);
			else if (ptr->b++)
				rrta_b(sort);
		}
		if (!sort->a->w)
		{
			sort->b->w = 1;
			push_b(sort);
		}
	}
	if (sort->a)
	while (get_distance_index(sort->a, sort->la, get_smallest(sort->a)) != 0)
	{
		if (get_distance_index(sort->a, sort->la, get_smallest(sort->a)) > 0
		 && get_distance_index(sort->b, sort->lb, get_biggest(sort->b)) > 0)
			rota_r(sort);
		else if (get_distance_index(sort->a, sort->la, get_smallest(sort->a)) < 0
		 && get_distance_index(sort->b, sort->lb, get_biggest(sort->b)) < 0)
			rrta_r(sort);
		else if (get_distance_index(sort->a, sort->la, get_smallest(sort->a)) > 0)
			rota_a(sort);
		else
			rrta_a(sort);
	}
	while (get_distance_index(sort->b, sort->lb, get_biggest(sort->b)) != 0)
	{
		if (get_distance_index(sort->b, sort->lb, get_biggest(sort->b)) > 0)
			rota_b(sort);
		else
			rrta_b(sort);
	}
	i = sort->l - 1;
	while (sort->b)
	{
		while (sort->b && sort->b->i == i)
		{
			i--;
			push_a(sort);
		}
		if (sort->al->i == i)
		{
			i--;
			rrta_a(sort);
		}
	}
}

void	whl_sort_2(t_sort *sort)
{
	t_elem *ptr;
	unsigned int i;

	i = 1;
	push_min_max(sort);
	while (a_has_w(sort->a))
	{
		ptr = get_distances(sort);
		if (sort->lb >= sort->l / 2 - sort->l / 20 && i && i--)
		{
			while (sort->lb != 2)
			{
				while (sort->b->i == 0 || sort->b->i == sort->l - 1)
					rota_b(sort);
				sort->b->w = 1;
				push_a(sort);
			}
		}
		ptr = get_distances(sort);
		while (ptr->a)
		{
			if (ptr->a > 0 && ptr->b > 0 && ptr->b-- && ptr->a--)
				rota_r(sort);
			else if (ptr->a > 0 && ptr->a--)
				rota_a(sort);
			else if (ptr->b < 0 && ptr->b++ && ptr->a++)
				rrta_r(sort);
			else if (ptr->a++)
				rrta_a(sort);
		}
		while (ptr->b)
		{
			if (ptr->b > 0 && ptr->b--)
				rota_b(sort);
			else if (ptr->b++)
				rrta_b(sort);
		}
		if (!sort->a->w)
		{
			sort->b->w = 1;
			push_b(sort);
		}
	}
	if (sort->a)
	while (get_distance_index(sort->a, sort->la, get_smallest(sort->a)) != 0)
	{
		if (get_distance_index(sort->a, sort->la, get_smallest(sort->a)) > 0
		 && get_distance_index(sort->b, sort->lb, get_biggest(sort->b)) > 0)
			rota_r(sort);
		else if (get_distance_index(sort->a, sort->la, get_smallest(sort->a)) < 0
		 && get_distance_index(sort->b, sort->lb, get_biggest(sort->b)) < 0)
			rrta_r(sort);
		else if (get_distance_index(sort->a, sort->la, get_smallest(sort->a)) > 0)
			rota_a(sort);
		else
			rrta_a(sort);
	}
	while (get_distance_index(sort->b, sort->lb, get_biggest(sort->b)) != 0)
	{
		if (get_distance_index(sort->b, sort->lb, get_biggest(sort->b)) > 0)
			rota_b(sort);
		else
			rrta_b(sort);
	}
	i = sort->l - 1;
	while (sort->b)
	{
		while (sort->b && sort->b->i == i)
		{
			i--;
			push_a(sort);
		}
		if (sort->al->i == i)
		{
			i--;
			rrta_a(sort);
		}
	}
}

void	whl_sort_3(t_sort *sort)
{
	t_elem *ptr;
	unsigned int i;

	i = 1;
	push_min_max(sort);
	while (a_has_w(sort->a))
	{
		ptr = get_distances(sort);
		if (sort->lb >= sort->l / 2 - sort->l / 10 && i && i--)
		{
			while (sort->lb != 2)
			{
				while (sort->b->i == 0 || sort->b->i == sort->l - 1)
					rota_b(sort);
				sort->b->w = 1;
				push_a(sort);
			}
		}
		ptr = get_distances(sort);
		while (ptr->a)
		{
			if (ptr->a > 0 && ptr->b > 0 && ptr->b-- && ptr->a--)
				rota_r(sort);
			else if (ptr->a > 0 && ptr->a--)
				rota_a(sort);
			else if (ptr->b < 0 && ptr->b++ && ptr->a++)
				rrta_r(sort);
			else if (ptr->a++)
				rrta_a(sort);
		}
		while (ptr->b)
		{
			if (ptr->b > 0 && ptr->b--)
				rota_b(sort);
			else if (ptr->b++)
				rrta_b(sort);
		}
		if (!sort->a->w)
		{
			sort->b->w = 1;
			push_b(sort);
		}
	}
	if (sort->a)
	while (get_distance_index(sort->a, sort->la, get_smallest(sort->a)) != 0)
	{
		if (get_distance_index(sort->a, sort->la, get_smallest(sort->a)) > 0
		 && get_distance_index(sort->b, sort->lb, get_biggest(sort->b)) > 0)
			rota_r(sort);
		else if (get_distance_index(sort->a, sort->la, get_smallest(sort->a)) < 0
		 && get_distance_index(sort->b, sort->lb, get_biggest(sort->b)) < 0)
			rrta_r(sort);
		else if (get_distance_index(sort->a, sort->la, get_smallest(sort->a)) > 0)
			rota_a(sort);
		else
			rrta_a(sort);
	}
	while (get_distance_index(sort->b, sort->lb, get_biggest(sort->b)) != 0)
	{
		if (get_distance_index(sort->b, sort->lb, get_biggest(sort->b)) > 0)
			rota_b(sort);
		else
			rrta_b(sort);
	}
	i = sort->l - 1;
	while (sort->b)
	{
		while (sort->b && sort->b->i == i)
		{
			i--;
			push_a(sort);
		}
		if (sort->al->i == i)
		{
			i--;
			rrta_a(sort);
		}
	}
}
