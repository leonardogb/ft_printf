/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strchr.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lgarcia- <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/23 13:49:14 by lgarcia-     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/02 14:08:10 by lgarcia-    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../incs/libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t n;

	n = ft_strlen(s);
	if (c == 0)
		return ((char *)&s[n]);
	return (ft_memchr(s, c, n));
}
