/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_putwstr.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lgarcia- <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/26 14:50:21 by lgarcia-     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/02 14:04:11 by lgarcia-    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../incs/ft_printf.h"

int	ft_putwstr(wchar_t *str)
{
	int	i;

	i = 0;
	if (ft_wstrlen(str) != -1)
	{
		while (*str)
		{
			if (ft_wcharlen(*str) != -1)
				i += ft_putwchar(*str);
			else
				return (-1);
			str++;
		}
		return (i);
	}
	return (-1);
}
