/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_print.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lgarcia- <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/05 14:18:01 by lgarcia-     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/02 16:36:11 by lgarcia-    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../incs/ft_printf.h"

int	ft_print_avant(t_modif *modif)
{
	int	count;

	count = 0;
	while (modif->sp_avant > 0)
	{
		ft_putchar(' ');
		modif->sp_avant--;
		count++;
	}
	if (modif->plus)
		ft_putchar('+');
	if (modif->moins)
		ft_putchar('-');
	if (modif->ze_x)
		ft_putstr("0x");
	if (modif->ze_gx)
		ft_putstr("0X");
	while (modif->ze_avant > 0)
	{
		ft_putchar('0');
		modif->ze_avant--;
		count++;
	}
	count += ft_countsuma(modif);
	return (count);
}

int	ft_print_apres(t_modif *modif)
{
	int	count;

	count = 0;
	while (modif->sp_apres > 0)
	{
		ft_putchar(' ');
		modif->sp_apres--;
		count++;
	}
	while (modif->ze_apres > 0)
	{
		ft_putchar('0');
		modif->ze_apres--;
		count++;
	}
	return (count);
}

int	ft_print_str(t_modif *modif, t_flags *flags)
{
	int		count;

	count = 0;
	count += ft_print_avant(modif);
	count += ft_print_nulls(flags);
	if (ft_strchr("s", flags->tipo) && flags->data && flags->tamano != 'l')
	{
		ft_putstr((char*)flags->data);
		count += ft_strlen((char*)flags->data);
	}
	else if (((flags->tipo == 'S' && flags->data) || (flags->tipo == 's'
					&& flags->tamano == 'l')) && flags->error == 0)
		count += ft_putwstr((wchar_t*)flags->data);
	else if ((flags->tipo == 'c' || flags->tipo == '%') && flags->tamano != 'l')
	{
		ft_putchar(flags->data);
		count++;
	}
	else if (flags->tipo == 'C' || (flags->tipo == 'c' && flags->tamano == 'l'))
		count += ft_putwchar(flags->data);
	count += ft_print_apres(modif);
	return (count);
}

int	ft_print_nbr(t_modif *modif, t_flags *flags)
{
	int	count;

	count = 0;
	count += ft_print_avant(modif);
	if (flags->data < 0)
		flags->data *= -1;
	if (flags->data == -9223372036854775807 - 1)
	{
		write(1, "9223372036854775808", 19);
		count += 19;
	}
	else if (!(flags->data == 0 && flags->punto == 1 && flags->precision == 0))
		count += ft_putnbrlen(flags->data);
	count += ft_print_apres(modif);
	return (count);
}

int	ft_print(t_flags *flags, t_modif *modif, va_list va, int nb)
{
	int	count;

	count = 0;
	if (flags->error == 0)
	{
		if (flags->tipo)
		{
			if (ft_strchr("sScC%", flags->tipo))
				count += ft_print_str(modif, flags);
			else if (ft_strchr("xXp", flags->tipo))
				count += ft_print_x(modif, flags);
			else if (ft_strchr("diD", flags->tipo))
				count += ft_print_nbr(modif, flags);
			else if (ft_strchr("uUoO", flags->tipo))
				count += ft_print_ou(modif, flags);
			ft_bonusn(flags, va, nb);
		}
		else
		{
			count += ft_print_avant(modif);
			count += ft_print_apres(modif);
		}
		ft_freestruct(flags, modif);
	}
	return (count);
}
