/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_print_o.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lgarcia- <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/07 15:40:53 by lgarcia-     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/02 14:02:50 by lgarcia-    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../incs/ft_printf.h"

void	ft_casto(t_flags *flags)
{
	char	*str;

	str = NULL;
	if (flags->tamano == 'H' && flags->tipo == 'o')
		flags->data = (uintmax_t)ft_uitoa_basel((unsigned char)flags->data, 8);
	else if (flags->tamano == 'h' && flags->tipo == 'o')
		flags->data = (uintmax_t)ft_uitoa_basel((unsigned short)flags->data, 8);
	else if (flags->tipo == 'O' || (flags->tipo == 'o' && flags->tamano == 'l'))
		flags->data = (uintmax_t)ft_uitoa_basel(flags->data, 8);
	else if (flags->tipo == 'o' && flags->tamano == 'L')
		flags->data =
			(uintmax_t)ft_uitoa_basel((unsigned long long)flags->data, 8);
	else if (flags->tipo == 'o' && (flags->tamano == 'j'
				|| flags->tamano == 'z'))
		flags->data = (uintmax_t)ft_uitoa_basel((uintmax_t)flags->data, 8);
	else if (flags->tipo == 'o')
	{
		str = ft_uitoa_basel((unsigned int)flags->data, 8);
		flags->data = (uintmax_t)str;
		free(str);
	}
}

int		ft_print_o(t_modif *modif, t_flags *flags)
{
	int		count;
	char	*str;

	count = 0;
	str = NULL;
	count += ft_print_avant(modif);
	ft_casto(flags);
	if (!(*(char*)flags->data == '0' && flags->punto == 1 &&
				flags->precision == 0 &&
				!flags->almohadilla))
	{
		ft_putstr((char*)flags->data);
		count += ft_strlen((char*)flags->data);
	}
	count += ft_print_apres(modif);
	return (count);
}
