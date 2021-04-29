/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosfryd <rosfryd@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 23:32:32 by rosfryd           #+#    #+#             */
/*   Updated: 2021/04/29 17:05:54 by rosfryd          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define SPEC "cspdiuxX%"
# define HEX_B "0123456789ABCDEF"
# define HEX_SM "0123456789abcdef"

# include "../libft/libft.h"
# include <stdarg.h>

typedef struct s_parsero
{
	char		flag;
	int			width;
	int			precision;
	char		type;
}t_parser;

int				ft_printf(const char *s, ...);
void			ft_width_pars(char ****ps, t_parser *pos_proc, va_list *pa);
void			ft_flag_pars(char ****ps, t_parser *pos);
void			ft_precision_pars(char ****ps, t_parser *pos_proc, va_list *pa);
void			ft_type_pars(char ****ps, t_parser *pos_proc);
int				ft_putchar(char c);
int				ft_putnbr(long src);
int				ft_putstr(const char *s);
int				ft_intlen(int i);
int				ft_un_intlen(unsigned int i);
void			ft_int_w(t_parser *pos_proc, va_list *pa, int *length);
void			ft_char_w(t_parser *pos_proc, va_list *pa, int *length);
int				ft_fill_char(char ch, int i);
int				ft_only_prec(int *num, t_parser *pos_proc);
void			ft_string_w(t_parser *pos_proc, va_list *pa, int *length);
int				ft_putstr_n(const char *s, int n);
void			ft_procent_w(t_parser *pos_proc, int *length);
void			ft_un_w(t_parser *pos_proc, va_list *pa, int *length);
int				ft_only_prec_un(unsigned int *num, t_parser *pos_proc);
void			ft_pointer_w(t_parser *pos_proc, va_list *pa, int *length);
char			*dec_to_hex_b(unsigned int num);
char			*dec_to_hex_sm(unsigned int num);
char			*dec_to_hex_point(unsigned long num);
char			*revers_str(char *src);
void			ft_sm_and_big_x_w(t_parser *pos_proc, va_list *pa, int *length);
int				ft_only_prec_x(char *str, t_parser *pos_proc);
char			*depend_on_case(unsigned int *num, t_parser *pos_proc);
int				reduce_for_width(char *str, t_parser *pos_proc);
int				reduce_for_precision(char *str, t_parser *pos_proc);
void			fill_and_putnbr_x(char *str, t_parser *pos_proc);
void			putnbr_and_fill_x(char *str, t_parser *pos_proc);
void			precision_fill_and_putnbr_x(char *str, t_parser *pos_proc);
void			precision_putnbr_and_fill_x(char *str, t_parser *pos_proc);
int				ft_putnbr_uns_int(unsigned int src);
int				ft_intlen_un_int(unsigned int i);
void			free_null(char *str);
int				sokrashenie_un_write(unsigned int *num, t_parser *pos_proc);
int				putnbr_and_fill_un(unsigned int *num, t_parser *pos_proc);
int				fill_and_putnbr_un(unsigned int *num, t_parser *pos_proc);
int				ft_wid_great_pres(int *num, t_parser *pos_proc);
int				precision_putnbr_and_fill(int *num, t_parser *pos_proc);
int				precision_fill_and_putnbr(int *num, t_parser *pos_proc);

#endif
