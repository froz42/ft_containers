/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 14:04:49 by tmatis            #+#    #+#             */
/*   Updated: 2021/09/19 14:08:15 by tmatis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SET_HPP
#define SET_HPP

#include <iostream>
#include <memory>
#include "../rbtree/tree.hpp"
#include "../iterators/lexicographical_compare.hpp"
#include "../iterators/equal.hpp"

namespace ft
{
	template <
		class Key,
		class Compare = std::less<Key>,
		class Allocator = std::allocator<Key> >
	class set
	{

	};
}

#endif
