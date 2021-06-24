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
/*   main.c                                   cclarice@student.21-school.ru   */
/*                                                                            */
/*   Created/Updated: 2021/06/24 00:57:34  /  2021/06/24 00:57:38 @cclarice   */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

t_elem	*create_list(int *d, unsigned int *i, int c, unsigned int *l)
{
	t_elem	*ptr;
	t_elem	*ret;
	int		ip;

	ip = 0;
	ret = ft_newelem(d[ip], i[ip]);
	ip++;
	ptr = ret;
	while (ip < c)
	{
		ptr->n = ft_newelem(d[ip], i[ip]);
		ip++;
		ptr = ptr->n;
	}
	ptr->n = NULL;
	*l = ip;
	return (ret);
}

void	clear_sort(t_sort *sort)
{
	t_elem	*ptr;
	t_elem	*nxt;

	ptr = sort->a;
	while (ptr)
	{
		nxt = ptr->n;
		free(ptr);
		ptr = nxt;
	}
	ptr = sort->b;
	while (ptr)
	{
		nxt = ptr->n;
		free(ptr);
		ptr = nxt;
	}
	sort->a = NULL;
	sort->b = NULL;
}

t_sort	*create_sort(t_sort *sort, int *d, unsigned int *i, int c)
{
	t_elem	*last;

	clear_sort(sort);
	sort->a = create_list(d, i, c, &sort->l);
	sort->la = sort->l;
	sort->lb = 0;
	last = sort->a;
	while (last->n)
		last = last->n;
	sort->al = last;
	sort->bl = NULL;
	exit_if_sorted(sort);
	return (sort);
}

void	sorting(t_sort *sort, int *d, unsigned int *i, int c)
{
	create_sort(sort, d, i, c);
	if (sort->l >= 4 && sort->l < 750)
	{
		whl_sort(sort, ++sort->opr);
		whl_sort(create_sort(sort, d, i, c), ++sort->opr);
		whl_sort(create_sort(sort, d, i, c), ++sort->opr);
		whl_sort(create_sort(sort, d, i, c), ++sort->opr);
		sort->vi = 1;
		if (sort->op[0] <= sort->op[1] && sort->op[0] <= sort->op[2]
			&& sort->op[0] <= sort->op[3])
			whl_sort(create_sort(sort, d, i, c), 0);
		else if (sort->op[1] <= sort->op[0] && sort->op[1] <= sort->op[2]
			&& sort->op[1] <= sort->op[3])
			whl_sort(create_sort(sort, d, i, c), 1);
		else if (sort->op[2] <= sort->op[0] && sort->op[2] <= sort->op[1]
			&& sort->op[1] <= sort->op[3])
			whl_sort(create_sort(sort, d, i, c), 2);
		else
			whl_sort(create_sort(sort, d, i, c), 3);
	}
	else if (++sort->vi && sort->l >= 750)
		whl_sort(sort, 1);
	else
		sw1_sort(sort);
	clear_sort(sort);
}

int	main(int c, char *v[])
{
	t_sort				sort;
	unsigned int		*i;
	int					*d;

	sort.a = NULL;
	sort.b = NULL;
	sort.op[0] = 0;
	sort.op[1] = 0;
	sort.op[2] = 0;
	sort.op[3] = 0;
	sort.opr = -1;
	(v++ && c--);
	if (c && not_integer(v[0]))
		exit_error();
	sort.vi = 0;
	if (c <= 1)
		return (0);
	convert_and_index(c, v, &d, &i);
	sorting(&sort, d, i, c);
	return (0);
}
