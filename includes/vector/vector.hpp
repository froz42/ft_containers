/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 14:53:40 by tmatis            #+#    #+#             */
/*   Updated: 2021/09/01 20:22:33 by tmatis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <memory>
#include "VectorIterator.hpp"
#include "VectorReverseIterator.hpp"
#include "VectorConstIterator.hpp"
#include "VectorConstReverseIterator.hpp"

namespace ft
{
	template <typename T, class Alloc = std::allocator<T>>
	class vector
	{
	public:
		// All typedef for the vector
		typedef T value_type;											  // syntax for vector<int>::value_type == int
		typedef Alloc allocator_type;									  // syntax for vector::allocator_type
		typedef typename allocator_type::reference reference;			  // T&
		typedef typename allocator_type::const_reference const_reference; // const T&
		typedef typename allocator_type::pointer pointer;				  // T*
		typedef typename allocator_type::const_pointer const_pointer;	  // const T*
		typedef size_t size_type;										  // unsigned int
		typedef ptrdiff_t difference_type;								  // int

		// Iterators
		typedef ft::VectorIterator<T> iterator;
		typedef ft::VectorReverseIterator<T> reverse_iterator;
		typedef ft::VectorConstIterator<T> const_iterator;
		typedef ft::VectorConstReverseIterator<T> const_reverse_iterator;

		// Constructors
		explicit vector(const allocator_type &alloc = allocator_type())
			: _alloc(alloc), _size(0), _capacity(0), _data(NULL){};
		
		explicit vector(size_type n, const value_type &val = value_type(),
						const allocator_type &alloc = allocator_type())
						: _alloc(alloc), _size(0), _capacity(0), _data(NULL)
		{
			this->reserve(n);
			this->_size = n;
			this->_capacity = n;
			for (size_type i = 0; i < n; i++)
				_alloc.construct(&_data[i], val);
		}
		template <class InputIterator>
		vector(InputIterator first, InputIterator last, const allocator_type &alloc = allocator_type())
			: _alloc(alloc), _size(0), _capacity(0), _data(NULL)
		{
			this->reserve(last - first);
			this->_size = last - first;
			this->_capacity = last - first;
			for (size_type i = 0; i < this->_size; i++)
				_alloc.construct(&_data[i], *(first + i));
		}

		// Destructor
		virtual ~vector(void){
			this->clear();
			if (_data)
				_alloc.deallocate(_data, _capacity);
		};

		size_type size(void) const
		{
			return _size;
		}
		
		size_type max_size(void) const
		{
			return _alloc.max_size();
		}

		size_type capacity(void) const
		{
			return (_capacity);
		}

		bool empty(void) const
		{
			return (_size == 0);
		}
		
		void clear(void)
		{
			for (size_type i = 0; i < _size; i++)
				_alloc.destroy(&_data[i]);
			_size = 0;
		}

		void reserve(size_type n)
		{
			if (n > _capacity)
			{
				value_type *tmp = _alloc.allocate(n);

				for (size_type i = 0; i < _size; i++)
					_alloc.construct(&tmp[i], _data[i]);
				for (size_type i = 0; i < _size; i++)
					_alloc.destroy(&_data[i]);
				_capacity = n;
				_data = tmp;
			}
		}

	private:
		allocator_type _alloc;
		size_type _size;
		size_type _capacity;
		pointer _data;
	};
}

#endif
