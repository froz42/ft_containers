/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator_traits.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 17:46:13 by tmatis            #+#    #+#             */
/*   Updated: 2021/09/03 18:49:31 by tmatis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_TRAITS_HPP
# define ITERATOR_TRAITS_HPP

# include <iterator>
# include <cstddef>

// more info here: https://www.lix.polytechnique.fr/~liberti/public/computing/prog/libstdc++/iterator_traits.html

namespace ft 
{
	template <class Iterator>
	class iterator_traits
	{
		public:
			typedef typename Iterator::value_type value_type;
			typedef typename Iterator::difference_type difference_type;
			typedef typename Iterator::pointer pointer;
			typedef typename Iterator::reference reference;
			typedef typename Iterator::iterator_category iterator_category;
	};
	template <class T>
	class iterator_traits<T*>
	{
		public:
			typedef T value_type;
			typedef ptrdiff_t difference_type;
			typedef T* pointer;
			typedef T& reference;
			typedef std::random_access_iterator_tag iterator_category;
	};
	template <class T>
	class iterator_traits<const T*>
	{
		public:
			typedef T value_type;
			typedef ptrdiff_t difference_type;
			typedef const T* pointer;
			typedef const T& reference;
			typedef std::random_access_iterator_tag iterator_category;

	};
}

#endif
