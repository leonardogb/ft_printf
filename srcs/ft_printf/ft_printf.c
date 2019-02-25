/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lgarcia- <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/01 16:56:41 by lgarcia-     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/02 16:57:54 by lgarcia-    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../incs/ft_printf.h"

int		ft_freestruct(t_flags *flags, t_modif *modif)
{
	free(flags);
	free(modif);
	return (1);
}

int		ft_imprime(const char **format)
{
	int	count;

	count = 0;
	if (**format)
	{
		ft_putchar(**format);
		(*format)++;
		count++;
	}
	return (count);
}

void	ft_bonusn(t_flags *flags, va_list va, int nb)
{
	if (flags->tipo == 'n')
	{
		if (!flags->tamano)
			*(va_arg(va, int*)) = nb;
		else if (flags->tamano == 'L')
			*(va_arg(va, long long*)) = nb;
		else if (flags->tamano == 'H')
			*(va_arg(va, signed char*)) = nb;
		else if (flags->tamano == 'l')
			*(va_arg(va, long*)) = nb;
		else if (flags->tamano == 'j')
			*(va_arg(va, intmax_t*)) = nb;
		else if (flags->tamano == 'h')
			*(va_arg(va, short*)) = nb;
		else if (flags->tamano == 'z')
			*(va_arg(va, short*)) = nb;
	}
	else if (flags->tipo == 'b')
	{
		if (flags->data < 0)
			flags->data = 0;
		ft_putstr(ft_itoa_base(flags->data, 2));
	}
}

int		ft_printf(const char *format, ...)
{
	va_list	va;
	int		count;
	t_flags	*flags;
	t_modif	*modif;

	count = 0;
	va_start(va, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (!(*format))
				break ;
			flags = ft_params(va, (char**)&format);
			modif = ft_modif(flags);
			if (flags->error == 1 && ft_freestruct(flags, modif))
				return (-1);
			count += ft_print(flags, modif, va, count);
		}
		else if (*format)
			count += ft_imprime(&format);
	}
	va_end(va);
	return (count);
}
