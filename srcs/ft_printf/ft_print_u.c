/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_print_u.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lgarcia- <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/01 12:12:27 by lgarcia-     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/02 14:03:23 by lgarcia-    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../incs/ft_printf.h"

int	ft_print_u(t_modif *modif, t_flags *flags)
{
	int	count;

	count = 0;
	count += ft_print_avant(modif);
	if (!(flags->data == 0 && flags->punto == 1 && flags->precision == 0))
		count += ft_putnbrlenu(flags->data);
	count += ft_print_apres(modif);
	return (count);
}
