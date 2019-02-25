/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_util.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lgarcia- <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/13 17:46:57 by lgarcia-     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/02 14:05:29 by lgarcia-    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../incs/ft_printf.h"

int		ft_putnbrlen(intmax_t n)
{
	intmax_t	nb;
	int			i;

	i = 0;
	nb = n;
	if (nb < 0)
		nb = nb * -1;
	if (nb >= 10)
	{
		i += ft_putnbrlen(nb / 10);
		i += ft_putnbrlen(nb % 10);
	}
	else
	{
		ft_putchar(nb + '0');
		i++;
	}
	return (i);
}

int		ft_putnbrlenu(unsigned long long n)
{
	int	i;

	i = 0;
	if (n >= 10)
	{
		i += ft_putnbrlenu(n / 10);
		i += ft_putnbrlenu(n % 10);
	}
	else
	{
		ft_putchar(n + '0');
		i++;
	}
	return (i);
}

int		ft_wcharlen(wchar_t c)
{
	if ((c >= 0xD800 && c <= 0xDFFF) || c < 0)
		return (-1);
	else if (c > 0 && c <= 0x7F && MB_CUR_MAX >= 1)
		return (1);
	else if (c > 0x7F && c <= 0x7FF && MB_CUR_MAX >= 2)
		return (2);
	else if (c > 0x7FF && c <= 0xFFFF && MB_CUR_MAX >= 3)
		return (3);
	else if (c > 0xFFFF && c <= 0x10FFFF && MB_CUR_MAX == 4)
		return (4);
	return (-1);
}

int		ft_wstrlen(wchar_t *str)
{
	int	i;

	i = 0;
	if (str)
	{
		while (*str)
		{
			if (ft_wcharlen(*str) != -1)
			{
				i += ft_wcharlen(*str);
			}
			else if (ft_wcharlen(*str) == -1)
				return (-1);
			str++;
		}
	}
	return (i);
}

wchar_t	*ft_wstrsub(wchar_t const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	wchar_t	*fraiche;

	i = 0;
	j = 0;
	if (s == NULL)
		return (NULL);
	if (!(fraiche = malloc(sizeof(wchar_t) * (len + 1))))
		return (NULL);
	while (j + ft_wcharlen(s[i + start]) <= len)
	{
		j += ft_wcharlen(s[start]);
		if (j < len)
		{
			fraiche[i] = s[start];
			i++;
			start++;
		}
	}
	fraiche[i] = '\0';
	return (fraiche);
}
