/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_access_iterator.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 18:49:56 by tmatis            #+#    #+#             */
/*   Updated: 2021/09/06 21:38:05 by tmatis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RANDOM_ACCESS_ITERATOR_HPP
#define RANDOM_ACCESS_ITERATOR_HPP
#include <iterator>

namespace ft
{
	template <class T>
	class random_access_iterator
	{
	public:
		typedef T value_type;
		typedef value_type &reference;
		typedef value_type *pointer;
		typedef std::ptrdiff_t difference_type;
		typedef std::random_access_iterator_tag iterator_category;

		random_access_iterator() : _ptr(NULL){};
		random_access_iterator(pointer ptr) : _ptr(ptr){};
		random_access_iterator(const random_access_iterator &other) : _ptr(other._ptr){};

		virtual ~random_access_iterator(){};

		random_access_iterator &operator=(const random_access_iterator &other)
		{
			_ptr = other._ptr;
			return (*this);
		}

		operator random_access_iterator<value_type const>() const
		{
			return random_access_iterator<value_type const>(_ptr);
		}

		bool operator==(const random_access_iterator &other) const
		{
			return (_ptr == other._ptr);
		}

		bool operator!=(const random_access_iterator &other) const
		{
			return (_ptr != other._ptr);
		}

		bool operator<(const random_access_iterator &other) const
		{
			return (_ptr < other._ptr);
		}

		bool operator>(const random_access_iterator &other) const
		{
			return (_ptr > other._ptr);
		}

		bool operator<=(const random_access_iterator &other) const
		{
			return (_ptr <= other._ptr);
		}

		bool operator>=(const random_access_iterator &other) const
		{
			return (_ptr >= other._ptr);
		}

		random_access_iterator &operator++()
		{
			++_ptr;
			return (*this);
		}

		random_access_iterator operator++(int)
		{
			random_access_iterator tmp(*this);
			++_ptr;
			return (tmp);
		}

		random_access_iterator &operator--()
		{
			--_ptr;
			return (*this);
		}

		random_access_iterator operator--(int)
		{
			random_access_iterator tmp(*this);
			--_ptr;
			return (tmp);
		}

		random_access_iterator &operator+=(difference_type n)
		{
			_ptr += n;
			return (*this);
		}

		random_access_iterator &operator-=(difference_type n)
		{
			_ptr -= n;
			return (*this);
		}

		random_access_iterator
		operator+(difference_type val) const
		{
			return random_access_iterator<T>(_ptr + val);
		}

		difference_type
		operator+(random_access_iterator const &rhs) const
		{
			return _ptr + rhs._ptr;
		}

		random_access_iterator
		operator-(difference_type val) const
		{
			return random_access_iterator<T>(_ptr - val);
		}

		difference_type
		operator-(random_access_iterator const &rhs) const
		{
			return _ptr - rhs._ptr;
		}

		reference operator*() const
		{
			return (*_ptr);
		}

		pointer operator->() const
		{
			return (_ptr);
		}

		reference operator[](difference_type n) const
		{
			return (_ptr[n]);
		}

	private:
		pointer _ptr;
	};
	template <class T>
	random_access_iterator<T> operator+(typename random_access_iterator<T>::difference_type n, const random_access_iterator<T> &it)
	{
		return (it + n);
	}

	template <class T>
	random_access_iterator<T> operator-(typename random_access_iterator<T>::difference_type n, const random_access_iterator<T> &it)
	{
		return (it - n);
	}
}

#endif
