/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_modif_d.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lgarcia- <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/07 15:42:47 by lgarcia-     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/02 14:01:00 by lgarcia-    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../incs/ft_printf.h"

int		ft_nbrlen(intmax_t nb)
{
	int	i;

	i = 0;
	if (nb < 0)
		nb *= -1;
	if (nb == 0)
		return (1);
	while (nb > 0)
	{
		i++;
		nb /= 10;
	}
	return (i);
}

void	ft_castdiu(t_flags *flags)
{
	if (flags->tipo == 'u' && flags->tamano == 'H')
		flags->data = (unsigned char)flags->data;
	else if (flags->tipo == 'u' && flags->tamano == 'z')
		flags->data = (size_t)flags->data;
	else if (flags->tipo == 'u' && flags->tamano != 'l' &&
			flags->tamano != 'L' && flags->tamano != 'j')
		flags->data = (unsigned)flags->data;
	else if ((flags->tipo == 'u' && flags->tamano == 'l') || flags->tipo == 'U')
		flags->data = (unsigned long)flags->data;
	else if (flags->tamano == 'h' && flags->tipo != 'U' && flags->tipo != 'D')
		flags->data = (short int)flags->data;
	else if (flags->tamano == 'H' && flags->tipo != 'U' && flags->tipo != 'D')
		flags->data = (signed char)flags->data;
	else if (!flags->tamano && flags->tipo != 'U' && flags->tipo != 'D')
		flags->data = (int)flags->data;
	else if (flags->tamano == 'l')
		flags->data = (long)flags->data;
	else if (flags->tipo == 'd' && flags->tamano == 'L')
		flags->data = (unsigned long long)flags->data;
}

void	ft_norme(t_flags *flags, t_modif *modif)
{
	if (flags->tipo == 'D')
	{
		modif->ze_avant = modif->sp_avant - flags->espacio;
		modif->sp_avant = 0 + flags->espacio;
	}
	else
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
}

int		ft_ajuste_d(t_modif *modif, t_flags *flags)
{
	int	ajuste;

	ajuste = 0;
	if (flags->data < 0)
		modif->moins = 1;
	if (flags->punto && flags->precision > ft_nbrlen(flags->data))
		modif->ze_avant = flags->precision - ft_nbrlen(flags->data);
	if (flags->mas && flags->data >= 0)
		modif->plus = 1;
	if (flags->data >= 0 && flags->espacio)
		modif->sp_avant = 1;
	ajuste = ft_nbrlen(flags->data) + modif->ze_avant + modif->plus
		+ modif->moins;
	return (ajuste);
}

void	ft_modif_d(t_modif *modif, t_flags *flags)
{
	int	ajuste;

	ft_castdiu(flags);
	ajuste = ft_ajuste_d(modif, flags);
	if (flags->ancho > ajuste)
	{
		if (flags->menos)
			modif->sp_apres = flags->ancho - ajuste - modif->sp_avant;
		else
			modif->sp_avant = flags->ancho - ajuste;
	}
	if (flags->cero && modif->sp_avant > 0 && !flags->punto)
		ft_norme(flags, modif);
	if (flags->data == 0 && flags->punto == 1 && flags->precision == 0
			&& flags->ancho > 0)
		modif->sp_avant++;
	if (flags->error2)
	{
		modif->ze_avant = 0;
	}
}
