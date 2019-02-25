/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_print_ou.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lgarcia- <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/27 16:58:51 by lgarcia-     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/02 14:03:11 by lgarcia-    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../incs/ft_printf.h"

int	ft_print_ou(t_modif *modif, t_flags *flags)
{
	int	count;

	count = 0;
	if (ft_strchr("oO", flags->tipo))
		count = ft_print_o(modif, flags);
	else if (ft_strchr("uU", flags->tipo))
		count = ft_print_u(modif, flags);
	return (count);
}
