/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_integral.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 21:57:36 by tmatis            #+#    #+#             */
/*   Updated: 2021/09/11 17:20:33 by tmatis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IS_INTEGRAL_HPP
#define IS_INTEGRAL_HPP

#ifdef __APPLE__
#include <stdint.h>
#else
#include <uchar.h>
#endif

namespace ft
{

	template <typename T>
	struct is_integral
	{
		const static bool value = false;
	};

	template <>
	struct is_integral<char>
	{
		const static bool value = true;
	};

	template <>	
	struct is_integral<char16_t>
	{
		const static bool value = true;
	};

	template <>
	struct is_integral<char32_t>
	{
		const static bool value = true;
	};

	template <>
	struct is_integral<wchar_t>
	{
		const static bool value = true;
	};

	template <>
	struct is_integral<short>
	{
		const static bool value = true;
	};

	template <>
	struct is_integral<int>
	{
		const static bool value = true;
	};

	template <>
	struct is_integral<long>
	{
		const static bool value = true;
	};

	template <>
	struct is_integral<long long>
	{
		const static bool value = true;
	};
}
#endif
