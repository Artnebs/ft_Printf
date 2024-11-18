/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anebbou <anebbou@student42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 14:19:45 by anebbou           #+#    #+#             */
/*   Updated: 2024/11/18 12:39:32 by anebbou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

/* ************************************************************************** */
/* INCLUDES */
/* ************************************************************************** */

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include "./libft/libft.h"

/* ************************************************************************** */
/* STRUCTURES */
/* ************************************************************************** */

// Réservé pour une future extension avec des flags et précisions
typedef struct s_format
{
	int flag_minus;
	int flag_zero;
	int width;
	int precision;
	int flag_hash;
	int flag_plus;
	int flag_space;
}               t_format;

/* ************************************************************************** */
/* PROTOTYPES */
/* ************************************************************************** */

// Fonctions principales
int     ft_printf(const char *format, ...);
int     ft_handle_conversion(char specifier, va_list args);

// Fonctions utilitaires
void    ft_put_padding(char c, int count);
char	*ft_ltoa_base(unsigned long n, int base);
char    *ft_ltoa_base_upper(unsigned long n, int base, int is_upper);

// Conversions
int     ft_printf_char(char c);
int     ft_printf_str(char *str);
int     ft_printf_int(int n);
int     ft_printf_uint(unsigned int n);
int     ft_printf_hex(unsigned int n, int is_upper);
int     ft_printf_ptr(void *ptr);

/* ************************************************************************** */
/* BONUS (Pour une éventuelle extension) */
/* ************************************************************************** */

// Parsing (réservé pour gérer les flags et largeurs)
void    init_format(t_format *fmt);
int     parse_format(const char **format, va_list args, t_format *fmt);
int     parse_flags(const char **format, t_format *fmt);
int     parse_width(const char **format, t_format *fmt);
int     parse_precision(const char **format, va_list args, t_format *fmt);

// Gestion des flags (bonus uniquement)
void    ft_handle_flag_minus(int *padding_len, int width, int len);
void    ft_handle_flag_zero(int *padding_len, int width, int len, int flag_minus);
int     ft_handle_flag_dot(int precision, int len);
int     ft_handle_minimum_width(int width, int len);
void    ft_handle_flag_hash(int is_upper);
void    ft_handle_flag_plus(int n);
void    ft_handle_flag_space(int n, int flag_plus);

/* ************************************************************************** */
/* DEBUG */
/* ************************************************************************** */

#endif
