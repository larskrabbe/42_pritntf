/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrabbe <lkrabbe@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 13:48:48 by lkrabbe           #+#    #+#             */
/*   Updated: 2022/07/05 18:35:05 by lkrabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

const static char	g_char_str[] = "0123456789abcdefghjklmonpqrstuvwxyz";
const static char	g_char_str_c[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const static char	g_hash[] = "0x";
const static char	g_hash_c[] = "0X";
const static char	g_null[] = "(null)";

//struct that store flags and string related values
typedef struct s_arg
{
	char	num[64];
	char	dta_typ;
	char	*dta_str;
	int		dta_len;
	int		width;
	char	wth_chr;
	int		precision;
	char	sign;
	char	side;
	char	hash;
	char	*out_str;
	int		max_len;
	int		output;
	int		total_length;
}			t_arg;

//sturcture that store typedependig data
typedef struct s_type
{
	size_t		cast;
	const char	*fix_str;
	int			fix_len;
	void		(*f_len)(t_arg *input);
	const char	*hash_str;
	int			hash_len;
	int			base;
	const char	*base_str;
}t_type;

void	calc_width( t_arg *input, t_type *type);
void	create_str( t_arg *input, t_type *type);
char	*my_strlchr(char *dst, const char c, int n);
void	fill_str( t_arg *input, t_type *type);
void	print_struct( t_arg *input);
char	*fill_list(char *str, struct s_arg *input, va_list va_ptr);
int		lenght_to_pcnt(char *str);
char	*my_putstring_length(t_arg *input, char *str, int n);
char	search_typ(const char *str, t_arg *input);
char	*convert_to_str(const char *str, void *ptr, t_arg *list);
int		ft_printf(const char *str, ...);
void	set_default(t_arg *input);
void	convert_num_to_str(t_arg *input, t_type *type);

//Funktion for calc the length of the input string depending on type
void	f_str_len(struct s_arg *input);
void	f_c_len(struct s_arg *input);
void	f_int_len(struct s_arg *input);

//Funktion that set some value depending on the type
void	setter_setter(t_arg *input, t_type *type, va_list va_ptr);
void	f_setter_u(t_type *type, va_list va_ptr);
void	f_setter_i(t_type *type, t_arg *input, va_list va_ptr);
void	f_setter_x(t_type *type, va_list va_ptr, char dta_typ);
void	f_setter_p(t_type *type, va_list va_ptr);
void	f_setter_o(t_type *type, va_list va_ptr);

#endif
