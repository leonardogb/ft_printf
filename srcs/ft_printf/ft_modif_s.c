/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_modif_s.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lgarcia- <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/05 11:51:51 by lgarcia-     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/02 14:01:44 by lgarcia-    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../incs/ft_printf.h"

void	ft_modif_s(t_modif *modif, t_flags *flags)
{
	char*str;

	if (flags->data)
		str = ft_strdup((char*)flags->data);
	else
		str = ft_strdup("(null)");
	if (flags->punto && (int)ft_strlen(str) > flags->precision)
		str = ft_strsub(str, 0, flags->precision);
	if (flags->ancho > (int)ft_strlen(str))
	{
		if (flags->menos)
			modif->sp_apres = flags->ancho - ft_strlen(str);
		else
		{
			modif->sp_avant = flags->ancho - ft_strlen(str);
			if (flags->cero)
			{
				modif->ze_avant = modif->sp_avant;
				modif->sp_avant = 0;
			}
		}
	}
	flags->data = (intmax_t)str;
	free(str);
}
