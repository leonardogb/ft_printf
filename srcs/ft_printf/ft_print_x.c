/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_print_x.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lgarcia- <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/22 15:50:43 by lgarcia-     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/02 14:03:33 by lgarcia-    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../incs/ft_printf.h"

void	ft_castx(t_flags *flags)
{
	char	*str;

	str = NULL;
	if ((flags->tipo == 'X' || flags->tipo == 'x') && flags->tamano == 'H')
		flags->data = (uintmax_t)ft_uitoa_basel((unsigned char)flags->data, 16);
	else if ((flags->tipo == 'x' || flags->tipo == 'X') && flags->tamano == 'z')
		flags->data = (uintmax_t)ft_uitoa_basel((size_t)flags->data, 16);
	else if ((flags->tamano == 'l' || flags->tamano == 'L'
				|| flags->tamano == 'j'))
		flags->data = (uintmax_t)ft_uitoa_basel(flags->data, 16);
	else if (flags->tipo == 'p')
	{
		str = ft_uitoa_basel(flags->data, 16);
		flags->data = (intmax_t)str;
		free(str);
	}
	else
	{
		str = ft_itoa_base(flags->data, 16);
		flags->data = (intmax_t)str;
		free(str);
	}
}

int		ft_print_x(t_modif *modif, t_flags *flags)
{
	int		count;
	char	*str;

	count = 0;
	str = NULL;
	count += ft_print_avant(modif);
	ft_castx(flags);
	if (flags->tipo == 'X')
		flags->data = (intmax_t)ft_strtoupper((char*)flags->data);
	if (!(*(char*)flags->data == '0' && flags->punto == 1 &&
				flags->precision == 0))
	{
		ft_putstr((char*)flags->data);
		count += ft_strlen((char*)flags->data);
	}
	flags->data = 0;
	count += ft_print_apres(modif);
	return (count);
}
