/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_modif_o.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lgarcia- <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/07 15:39:08 by lgarcia-     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/02 14:01:24 by lgarcia-    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../incs/ft_printf.h"

void	ft_modif_o(t_modif *modif, t_flags *flags)
{
	char	*str;
	int		ajuste;

	str = ft_uitoa_basel(flags->data, 8);
	if (flags->punto && flags->precision > (int)ft_strlen(str))
		modif->ze_avant = flags->precision - ft_strlen(str);
	if (flags->almohadilla && ft_strchr("oO", flags->tipo) &&
			flags->data != 0 && !modif->ze_avant)
		modif->ze_avant++;
	ajuste = ft_strlen(str) + modif->ze_avant + modif->ze_x + modif->ze_gx;
	if (flags->ancho > ajuste)
	{
		if (flags->menos)
			modif->sp_apres = flags->ancho - ajuste;
		else if (flags->cero && !flags->punto)
			modif->ze_avant = flags->ancho - ajuste;
		else
			modif->sp_avant = flags->ancho - ajuste;
	}
	if (flags->data == 0 && flags->punto == 1 && flags->precision == 0
			&& (flags->ancho > 0))
		modif->sp_avant++;
	free(str);
}
