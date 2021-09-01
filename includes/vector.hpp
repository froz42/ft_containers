/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 14:53:40 by tmatis            #+#    #+#             */
/*   Updated: 2021/09/01 15:17:08 by tmatis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <memory>

namespace ft
{
	template <typename T, class Alloc = std::allocator<T>>
	class vector
	{
		public:
		
			// All typedef for the vector but not for iterator
			typedef T	value_type; // syntax for vector<int>::value_type == int
			typedef Alloc	allocator_type; // syntax for vector::allocator_type
			typedef typename allocator_type::reference reference; // T&
			typedef typename allocator_type::const_reference const_reference; // const T&
			typedef typename allocator_type::pointer pointer; // T*
			typedef typename allocator_type::const_pointer const_pointer; // const T*
			typedef size_t size_type; // unsigned int
			typedef ptrdiff_t difference_type; // int

			explicit vector (const allocator_type& alloc = allocator_type());
			explicit vector (size_type n, const value_type& val = value_type(),
				const allocator_type& alloc = allocator_type());
			template <class InputIterator>
         	vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type());
			virtual ~vector(void);

	};
}

#endif
