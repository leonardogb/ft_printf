/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_modif_u.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lgarcia- <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/05 16:10:04 by lgarcia-     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/02 14:02:05 by lgarcia-    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../incs/ft_printf.h"

int		ft_nbrlenu(unsigned long long n)
{
	int	i;

	i = 0;
	if (n >= 10)
	{
		i += ft_nbrlenu(n / 10);
		i += ft_nbrlenu(n % 10);
	}
	else
		i++;
	return (i);
}

int		ft_ajuste(t_modif *modif, t_flags *flags)
{
	int	ajuste;

	ajuste = 0;
	if (flags->data < 0 && flags->tipo != 'u' && flags->tipo != 'U')
		modif->moins = 1;
	if (flags->punto && flags->precision > ft_nbrlen(flags->data))
		modif->ze_avant = flags->precision - ft_nbrlenu(flags->data);
	if (flags->mas && flags->data >= 0 && flags->tipo != 'u')
		modif->plus = 1;
	if (flags->data >= 0 && flags->espacio && flags->tipo != 'u')
		modif->sp_avant = 1;
	ajuste = ft_nbrlenu(flags->data) + modif->ze_avant
		+ modif->plus + modif->moins;
	return (ajuste);
}

void	ft_norme_u(t_modif *modif, t_flags *flags, int ajuste)
{
	if (flags->ancho > ajuste)
	{
		if (flags->menos)
			modif->sp_apres = flags->ancho - ajuste - modif->sp_avant;
		else
			modif->sp_avant = flags->ancho - ajuste;
	}
}

void	ft_modif_u(t_modif *modif, t_flags *flags)
{
	int	ajuste;

	ft_castdiu(flags);
	ajuste = ft_ajuste(modif, flags);
	ft_norme_u(modif, flags, ajuste);
	if (flags->cero && modif->sp_avant > 0 && !flags->punto)
	{
		if (flags->espacio && flags->cero)
		{
			modif->ze_avant = modif->sp_avant - 1;
			modif->sp_avant = 1;
		}
		else
		{
			modif->ze_avant = modif->sp_avant;
			modif->sp_avant = 0;
		}
	}
	if (flags->data == 0 && flags->punto == 1 && flags->precision == 0
			&& flags->ancho > 0)
		modif->sp_avant++;
}
