/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strsub.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lgarcia- <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/23 13:53:39 by lgarcia-     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/02 14:08:51 by lgarcia-    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../incs/libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*fraiche;

	i = 0;
	if (s == NULL)
		return (NULL);
	if (!(fraiche = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (i < len)
	{
		fraiche[i] = s[start];
		i++;
		start++;
	}
	fraiche[i] = '\0';
	return (fraiche);
}
