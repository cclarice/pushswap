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
/*   put_digit.c                              cclarice@student.21-school.ru   */
/*                                                                            */
/*   Created/Updated: 2021/06/01 23:24:57  /  2021/06/01 23:32:02 @cclarice   */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

#define TIME 1

void	put_char(char c)
{
	write(1, &c, 1);
}

void	put_nbr(int d)
{
	if (d < 0)
	{
		write(1, "-", 1);
		d *= -1;
	}
	if (d >= 10)
		put_nbr(d / 10);
	put_char((d % 10) + '0');
}

long	nbr_len(int d)
{
	long ret;

	ret = 1;
	if (d < 0)
		ret++;
	while (d / 10 && ret++)
		d /= 10;
	return (ret);
}

void	put_digit(int d, int w, unsigned int i, int c)
{
	//write(1, "\033[38;2;0;255;0m", 15);
	write(1, "\033[38;2;32;", 10);
	if (c >= 1)
		put_nbr(255 - i * c);
	else
		put_nbr(255 - i / (c * -1));
	write(1, ";32m", 4);
	put_nbr(d);
	w -= nbr_len(d);
	while (w > 1 && w--)
		write(1, " ", 1);
	write(1, "\033[0m|", 5);
}
