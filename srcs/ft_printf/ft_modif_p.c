/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_modif_p.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lgarcia- <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/05 13:52:57 by lgarcia-     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/02 14:01:34 by lgarcia-    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../incs/ft_printf.h"

void	ft_modif_p(t_modif *modif, t_flags *flags)
{
	char	*str;

	str = ft_uitoa_basel(flags->data, 16);
	if (flags->tipo == 'p')
		modif->ze_x = 1;
	if (flags->punto)
		modif->ze_avant = flags->precision - ft_strlen(str);
	if (flags->ancho)
	{
		if (flags->menos)
			modif->sp_apres = flags->ancho - ft_strlen(str) - 2;
		else
			modif->sp_avant = flags->ancho - ft_strlen(str) - 2;
	}
	if (flags->cero)
	{
		modif->ze_apres = modif->sp_avant;
		modif->sp_avant = 0;
	}
	free(str);
}
