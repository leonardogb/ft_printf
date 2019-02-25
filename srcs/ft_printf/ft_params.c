/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_params.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lgarcia- <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/01 13:48:07 by lgarcia-     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/02 15:57:03 by lgarcia-    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../incs/ft_printf.h"

void		ft_flags_flags(t_flags *flags, char **format)
{
	int	i;

	i = 0;
	while (ft_strchr("-+0 #", (*format)[i]))
	{
		if ((*format)[i] == '-')
			flags->menos = 1;
		if ((*format)[i] == '+')
			flags->mas = 1;
		if ((*format)[i] == '0')
			flags->cero = 1;
		if ((*format)[i] == ' ')
			flags->espacio = 1;
		if ((*format)[i] == '#')
			flags->almohadilla = 1;
		i++;
	}
	if (flags->menos && flags->cero)
		flags->cero = 0;
	if (flags->espacio && flags->mas)
		flags->espacio = 0;
	*format += i;
}

void		ft_flags_ancho(t_flags *flags, char **format, va_list va)
{
	int	i;

	i = 0;
	if (**format == '*')
	{
		flags->ancho = va_arg(va, int);
		if (flags->ancho < 0)
		{
			flags->menos = 1;
			flags->ancho *= -1;
		}
		(*format)++;
	}
	else if (ft_isdigit((*format)[i]))
		flags->ancho = ft_atoi(*format);
	while (ft_isdigit((*format)[i]))
		i++;
	*format += i;
}

void		ft_flags_precision(t_flags *flags, char **format, va_list va)
{
	int	i;

	i = 0;
	if ((*format)[i] == '.')
	{
		(*format)++;
		flags->punto = 1;
		if (**format == '*')
		{
			flags->precision = va_arg(va, int);
			if (flags->precision < 0)
			{
				flags->precision *= -1;
				flags->error2 = 1;
			}
			(*format)++;
		}
		else
			flags->precision = ft_atoi(*format);
		while (ft_isdigit((*format)[i]))
			i++;
	}
	*format += i;
}

void		ft_flags_tamano(t_flags *flags, char **format)
{
	int	i;

	i = 0;
	while (ft_strchr("hljz", (*format)[i]))
	{
		if ((*format)[i] == 'h' && (*format)[i + 1] == 'h')
			flags->tamano = 'H';
		else if ((*format)[i] == 'h' && (*format)[i + 1] != 'h'
				&& flags->tamano == '\0')
			flags->tamano = 'h';
		else if ((*format)[i] == 'l' && (*format)[i + 1] == 'l')
			flags->tamano = 'L';
		else if ((*format)[i] == 'l' && (*format)[i + 1] != 'l'
				&& flags->tamano == '\0')
			flags->tamano = 'l';
		else if ((*format)[i] == 'j')
			flags->tamano = 'j';
		else if ((*format)[i] == 'z')
			flags->tamano = 'z';
		i++;
	}
	*format += i;
}

t_flags		*ft_params(va_list va, char **format)
{
	t_flags	*flag;

	flag = ft_inicializa();
	ft_flags_flags(flag, format);
	ft_flags_ancho(flag, format, va);
	ft_flags_precision(flag, format, va);
	ft_flags_tamano(flag, format);
	if (ft_strchr("sSdipouxcSDOUXCnb%", **format))
	{
		flag->tipo = **format;
		(*format)++;
	}
	ft_data(va, flag);
	return (flag);
}
