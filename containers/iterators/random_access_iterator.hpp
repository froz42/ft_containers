/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_access_iterator.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 18:49:56 by tmatis            #+#    #+#             */
/*   Updated: 2021/09/03 19:43:52 by tmatis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RANDOM_ACCESS_ITERATOR_HPP
# define RANDOM_ACCESS_ITERATOR_HPP

# include "iterator_traits.hpp"

namespace ft
{
	template <class T>
	class random_access_iterator
	{
			typedef T value_type;
			typedef value_type& reference;
			typedef value_type* pointer;
			typedef const value_type& const_reference;
			typedef const value_type* const_pointer;
			typedef std::ptrdiff_t difference_type;
	};
}

#endif
