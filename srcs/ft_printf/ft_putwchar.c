/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_putwchar.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lgarcia- <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/26 14:34:28 by lgarcia-     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/02 14:04:00 by lgarcia-    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../incs/ft_printf.h"

int	ft_putwcharsuite(wchar_t c)
{
	if (c > 0xFFFF && c <= 0x10FFFF && MB_CUR_MAX >= 4)
	{
		ft_putchar((c >> 18) | 0xF0);
		ft_putchar(((c >> 12) & 0x3F) | 0x80);
		ft_putchar(((c >> 6) & 0x3F) | 0x80);
		ft_putchar((c & 0x3F) | 0x80);
		return (4);
	}
	return (-1);
}

int	ft_putwchar(wchar_t c)
{
	if ((c >= 0xD800 && c <= 0xDFFF) || c < 0)
		return (-1);
	else if (c <= 0x7F && MB_CUR_MAX >= 1)
	{
		ft_putchar(c);
		return (1);
	}
	else if (c > 0x7F && c <= 0x7FF && MB_CUR_MAX >= 2)
	{
		ft_putchar((c >> 6) | 0xC0);
		ft_putchar((c & 0x3F) | 0x80);
		return (2);
	}
	else if (c > 0x7FF && c <= 0xFFFF && MB_CUR_MAX >= 3)
	{
		ft_putchar((c >> 12) | 0xE0);
		ft_putchar(((c >> 6) & 0x3F) | 0x80);
		ft_putchar((c & 0x3F) | 0x80);
		return (3);
	}
	else if (ft_putwcharsuite(c) == 4)
		return (4);
	return (-1);
}
