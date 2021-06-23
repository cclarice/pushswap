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
/*   Created/Updated: 2021/06/23 19:51:44  /  2021/06/23 19:52:04 @cclarice   */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	exit_error(void)
{
	write(1, "Error\n", 6);
	exit(0);
}

t_elem	*ft_newelem(int nbr, unsigned int index)
{
	t_elem	*ptr;

	ptr = malloc(sizeof(t_elem));
	if (!ptr)
		exit_error();
	ptr->n = NULL;
	ptr->d = nbr;
	ptr->i = index;
	ptr->w = 0;
	return (ptr);
}

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

void	create_sort(t_sort *sort, int *d, unsigned int *i, int c)
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
}

void	sorting(t_sort *sort, int *d, unsigned int *i, int c)
{
	create_sort(sort, d, i, c);
	if (sort->vi == 0)
	{
		if (sort->l >= 4 && sort->l < 750)
		{
			sort->opr = 0;
			whl_sort_0(sort);
			sort->opr++;
			clear_sort(sort);
			create_sort(sort, d, i, c);
			whl_sort_1(sort);
			sort->opr++;
			clear_sort(sort);
			create_sort(sort, d, i, c);
			whl_sort_2(sort);
			sort->opr++;
			clear_sort(sort);
			create_sort(sort, d, i, c);
			whl_sort_3(sort);
			clear_sort(sort);
			create_sort(sort, d, i, c);
			sort->vi = 1;
			if (sort->op[0] <= sort->op[1] && sort->op[0] <= sort->op[2] && sort->op[0] <= sort->op[3])
				whl_sort_0(sort);
			else if (sort->op[1] <= sort->op[0] && sort->op[1] <= sort->op[2] && sort->op[1] <= sort->op[3])
				whl_sort_1(sort);
			else if (sort->op[2] <= sort->op[0] && sort->op[2] <= sort->op[1] && sort->op[1] <= sort->op[3])
				whl_sort_2(sort);
			else
				whl_sort_3(sort);
		}
		else if (++sort->vi && sort->l >= 750)
			whl_sort_1(sort);
		else
			sw1_sort(sort);
		clear_sort(sort);
	}
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
