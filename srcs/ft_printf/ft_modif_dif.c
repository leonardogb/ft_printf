/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_modif_dif.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lgarcia- <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/02 15:31:44 by lgarcia-     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/02 14:01:11 by lgarcia-    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../incs/ft_printf.h"

void	ft_modif_dif(t_modif *modif, t_flags *flags)
{
	if (flags->ancho)
	{
		if (flags->menos)
			modif->sp_apres = flags->ancho - 1;
		else
			modif->sp_avant = flags->ancho - 1;
	}
	if (flags->cero && modif->sp_avant > 0)
	{
		modif->ze_avant = modif->sp_avant;
		modif->sp_avant = 0;
	}
}
