/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_modif.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lgarcia- <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/07 15:38:07 by lgarcia-     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/02 16:39:19 by lgarcia-    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../incs/ft_printf.h"

t_modif		*ft_ini_modif(void)
{
	t_modif	*modif;

	if (!(modif = malloc(sizeof(t_modif))))
		return (NULL);
	modif->sp_avant = 0;
	modif->sp_apres = 0;
	modif->ze_avant = 0;
	modif->ze_apres = 0;
	modif->plus = 0;
	modif->moins = 0;
	modif->espace = 0;
	modif->ze_x = 0;
	modif->ze_gx = 0;
	return (modif);
}

t_modif		*ft_modif(t_flags *flags)
{
	t_modif	*modif;

	modif = ft_ini_modif();
	if (flags->tipo)
	{
		if (ft_strchr("s", flags->tipo) && flags->tamano != 'l')
			ft_modif_s(modif, flags);
		else if (ft_strchr("sS", flags->tipo))
			ft_modif_sup(modif, flags);
		if (ft_strchr("cC%", flags->tipo))
			ft_modif_c(modif, flags);
		if (ft_strchr("diD", flags->tipo))
			ft_modif_d(modif, flags);
		if (ft_strchr("uU", flags->tipo))
			ft_modif_u(modif, flags);
		if (ft_strchr("oO", flags->tipo))
			ft_modif_o(modif, flags);
		if (ft_strchr("xX", flags->tipo))
			ft_modif_x(modif, flags);
		if (flags->tipo == 'p')
			ft_modif_p(modif, flags);
	}
	else
		ft_modif_dif(modif, flags);
	return (modif);
}
