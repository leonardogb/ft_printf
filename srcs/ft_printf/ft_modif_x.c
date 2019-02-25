/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_modif_x.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lgarcia- <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/23 14:47:38 by lgarcia-     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/02 14:02:15 by lgarcia-    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../incs/ft_printf.h"

void	ft_modif_x(t_modif *modif, t_flags *flags)
{
	char	*str;
	int		ajuste;

	str = ft_uitoa_basel(flags->data, 16);
	if (flags->punto && flags->precision > (int)ft_strlen(str))
		modif->ze_avant = flags->precision - ft_strlen(str);
	if (flags->almohadilla && flags->tipo == 'x' && flags->data != 0)
		modif->ze_x = 2;
	else if (flags->almohadilla && flags->tipo == 'X' && flags->data != 0)
		modif->ze_gx = 2;
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
