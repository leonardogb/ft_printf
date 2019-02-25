/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.h                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lgarcia- <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/01 13:35:07 by lgarcia-     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/02 14:43:29 by lgarcia-    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <wchar.h>
# include "libft.h"
# include <locale.h>
# include <limits.h>

typedef struct	s_flags
{
	int			error;
	int			error2;
	intmax_t	data;
	int			menos;
	int			mas;
	int			cero;
	int			espacio;
	int			almohadilla;
	int			punto;
	int			ancho;
	int			precision;
	char		tamano;
	char		tipo;
}				t_flags;

typedef struct	s_modif
{
	int			sp_avant;
	int			sp_apres;
	int			ze_avant;
	int			ze_apres;
	int			plus;
	int			moins;
	int			espace;
	int			ze_x;
	int			ze_gx;
}				t_modif;

int				ft_printf(const char *format, ...);
int				ft_print(t_flags *flags, t_modif *modif, va_list va, int nb);
int				ft_nbrlen(intmax_t nb);
int				ft_putnbrlenu(unsigned long long nb);
int				ft_putnbrlen(intmax_t n);
char			*ft_itoa_base(unsigned int nbr, unsigned int base);
char			*ft_uitoa_basel(unsigned long long nbr, unsigned int base);
char			*ft_itoa_basel(long nbr, unsigned int base);
t_flags			*ft_params(va_list va, char **format);
void			ft_data(va_list va, t_flags *flags);
t_modif			*ft_modif(t_flags *flags);
void			ft_modif_s(t_modif *modif, t_flags *flags);
void			ft_modif_sup(t_modif *modif, t_flags *flags);
void			ft_modif_d(t_modif *modif, t_flags *flags);
void			ft_modif_o(t_modif *modif, t_flags *flags);
void			ft_modif_p(t_modif *modif, t_flags *flags);
void			ft_modif_u(t_modif *modif, t_flags *flags);
void			ft_modif_c(t_modif *modif, t_flags *flags);
void			ft_modif_dif(t_modif *modif, t_flags *flags);
void			ft_castdiu(t_flags *flags);
char			*ft_strtoupper(char *str);
int				ft_print_avant(t_modif *modif);
int				ft_print_apres(t_modif *modif);
int				ft_print_o(t_modif *modif, t_flags *flags);
int				ft_print_x(t_modif *modif, t_flags *flags);
int				ft_print_u(t_modif *modif, t_flags *flags);
int				ft_wcharlen(wchar_t c);
int				ft_putwchar(wchar_t c);
int				ft_putwstr(wchar_t *str);
int				ft_wstrlen(wchar_t *str);
wchar_t			*ft_wstrsub(wchar_t const *s, unsigned int start, size_t len);
void			ft_modif_x(t_modif *modif, t_flags *flags);
int				ft_countsuma(t_modif *modif);
int				ft_print_nulls(t_flags *flags);
t_flags			*ft_inicializa(void);
wchar_t			*ft_wstrdup(wchar_t *s1);
int				ft_freestruct(t_flags *flags, t_modif *modif);
void			ft_bonusn(t_flags *flags, va_list va, int count);
int				ft_print_ou(t_modif *modif, t_flags *flags);

#endif
