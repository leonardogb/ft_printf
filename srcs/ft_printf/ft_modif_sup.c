/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_modif_sup.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lgarcia- <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/06 18:55:31 by lgarcia-     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/02 14:01:54 by lgarcia-    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../incs/ft_printf.h"

int		ft_errorsup(t_flags *flags, wchar_t *str)
{
	if (ft_wstrlen(str) == -1)
	{
		flags->error = 1;
		return (-1);
	}
	return (0);
}

void	ft_anchosup(t_flags *flags, t_modif *modif, wchar_t *str)
{
	if (flags->menos)
		modif->sp_apres = flags->ancho - ft_wstrlen(str);
	else
	{
		modif->sp_avant = flags->ancho - ft_wstrlen(str);
		if (flags->cero)
		{
			modif->ze_avant = modif->sp_avant;
			modif->sp_avant = 0;
		}
	}
}

void	ft_modif_sup(t_modif *modif, t_flags *flags)
{
	wchar_t	*str;
	int		libero;

	libero = 0;
	str = (wchar_t*)flags->data;
	if (flags->data && ft_errorsup(flags, str) == 0)
	{
		if (flags->punto && (int)ft_wstrlen(str) > flags->precision)
		{
			str = ft_wstrsub(str, 0, flags->precision);
			libero = 1;
		}
		if (flags->ancho > (int)ft_wstrlen(str))
		{
			ft_anchosup(flags, modif, str);
		}
		flags->data = (intmax_t)str;
	}
	if (libero)
		free(str);
}
