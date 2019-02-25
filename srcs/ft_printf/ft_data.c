/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_data.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lgarcia- <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/13 10:42:46 by lgarcia-     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/02 16:59:55 by lgarcia-    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../incs/ft_printf.h"

void	ft_data(va_list va, t_flags *flags)
{
	if (flags->tipo == 'S')
		flags->data = (intmax_t)va_arg(va, wchar_t*);
	else if (flags->tipo == 's')
		flags->data = (intmax_t)va_arg(va, char*);
	else if (flags->tipo == 'C')
		flags->data = (intmax_t)va_arg(va, wchar_t);
	else if (flags->tipo == 'S')
		flags->data = (intmax_t)va_arg(va, wchar_t*);
	else if (ft_strchr("c", flags->tipo))
		flags->data = (intmax_t)va_arg(va, int);
	else if (ft_strchr("oOuUxX", flags->tipo))
		flags->data = (uintmax_t)va_arg(va, unsigned long long);
	else if (ft_strchr("diD", flags->tipo))
		flags->data = (intmax_t)va_arg(va, intmax_t);
	else if (flags->tipo == '%')
		flags->data = (intmax_t)'%';
	else if (flags->tipo == 'p')
		flags->data = va_arg(va, uintmax_t);
	else if (flags->tipo == 'b')
		flags->data = (intmax_t)va_arg(va, int);
}
