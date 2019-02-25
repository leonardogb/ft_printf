/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_itoa_base.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lgarcia- <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/09 18:37:39 by lgarcia-     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/02 14:00:25 by lgarcia-    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../incs/ft_printf.h"

int		ft_size(unsigned int nb, unsigned int base)
{
	int	i;

	i = 0;
	while (nb != 0)
	{
		nb /= base;
		i++;
	}
	return (i);
}

char	*ft_itoa_base(unsigned int nbr, unsigned int base)
{
	char	*str;
	char	*tab;
	int		i;
	int		size;

	size = ft_size(nbr, base);
	i = size - 1;
	tab = NULL;
	tab = ft_strsub("0123456789abcdef", 0, 17);
	if (nbr == 0)
		return (ft_strdup("0"));
	if (!(str = malloc(sizeof(char) * (size + 1))))
		return (NULL);
	while (nbr != 0)
	{
		str[i] = tab[nbr % base];
		nbr /= base;
		i--;
	}
	str[size] = '\0';
	free(tab);
	return (str);
}
