/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_util2.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lgarcia- <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/23 15:44:34 by lgarcia-     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/02 14:05:40 by lgarcia-    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../incs/ft_printf.h"

int		ft_countsuma(t_modif *modif)
{
	int	count;

	count = 0;
	if (modif->plus || modif->moins)
		count++;
	else if (modif->ze_x || modif->ze_gx)
		count += 2;
	return (count);
}

int		ft_print_nulls(t_flags *flags)
{
	int count;

	count = 0;
	if (ft_strchr("Ss", flags->tipo) && !flags->data)
	{
		write(1, "(null)", 6);
		count += 6;
	}
	return (count);
}

t_flags	*ft_inicializa(void)
{
	t_flags	*flags;

	if (!(flags = malloc(sizeof(t_flags))))
		return (NULL);
	flags->error = 0;
	flags->error2 = 0;
	flags->menos = 0;
	flags->mas = 0;
	flags->cero = 0;
	flags->espacio = 0;
	flags->almohadilla = 0;
	flags->punto = 0;
	flags->ancho = 0;
	flags->precision = 0;
	flags->tamano = '\0';
	flags->tipo = '\0';
	return (flags);
}
