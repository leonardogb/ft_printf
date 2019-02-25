/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_modif_c.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lgarcia- <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/06 17:47:47 by lgarcia-     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/02 14:00:49 by lgarcia-    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../incs/ft_printf.h"

int		ft_errorc(t_flags *flags)
{
	if (ft_wcharlen(flags->data) == -1)
	{
		flags->error = 1;
		return (1);
	}
	return (0);
}

void	ft_modif_cup(t_modif *modif, t_flags *flags)
{
	if (flags->ancho && flags->menos && ft_errorc(flags) == 0)
		modif->sp_apres = flags->ancho - ft_wcharlen(flags->data);
	else if (flags->ancho && !flags->menos && ft_errorc(flags) == 0)
	{
		if (flags->cero)
			modif->ze_avant = flags->ancho - ft_wcharlen(flags->data);
		else
			modif->sp_avant = flags->ancho - ft_wcharlen(flags->data);
	}
	if (ft_wcharlen(flags->data) == -1 && flags->data != 0)
		flags->error = 1;
}

void	ft_modif_c(t_modif *modif, t_flags *flags)
{
	if (ft_strchr("c%", flags->tipo) && flags->tamano != 'l')
	{
		if (flags->ancho && flags->menos)
			modif->sp_apres = flags->ancho - 1;
		else if (flags->ancho && !flags->menos)
		{
			if (flags->cero)
				modif->ze_avant = flags->ancho - 1;
			else
				modif->sp_avant = flags->ancho - 1;
		}
	}
	else if (flags->tipo == 'C' || (flags->tipo == 'c' && flags->tamano == 'l'))
		ft_modif_cup(modif, flags);
}
