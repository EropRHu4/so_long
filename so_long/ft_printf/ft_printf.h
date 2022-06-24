/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syule <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 17:16:00 by syule             #+#    #+#             */
/*   Updated: 2022/06/24 17:16:01 by syule            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *format, ...);
char	*ft_strchr(const char *s, int c);
int		ft_strlen(char *s);
int		print_pointer(void *p);
int		print_decimal(int number);
int		print_unsigned_int(int num);
int		print_hexadecimal(int num, char x);
#endif
