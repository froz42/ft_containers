/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 12:35:36 by tmatis            #+#    #+#             */
/*   Updated: 2021/09/19 12:06:50 by tmatis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP

# include "iterator_traits.hpp"
# include "random_access_iterator.hpp"

namespace ft
{
	template <class Iter>
	class reverse_iterator
	{
		public:
			typedef typename iterator_traits<Iter>::value_type value_type;
			typedef typename iterator_traits<Iter>::difference_type difference_type;
			typedef typename iterator_traits<Iter>::pointer pointer;
			typedef typename iterator_traits<Iter>::reference reference;
			typedef typename iterator_traits<Iter>::iterator_category iterator_category;
			typedef Iter iterator_type;

			//constructors
			reverse_iterator() : _base(Iter()) {};
			explicit reverse_iterator (iterator_type it) : _base(it) {};
  			reverse_iterator (const reverse_iterator<Iter>& rev_it) : _base(rev_it._base) {};

			//operators
			reverse_iterator& operator=(const reverse_iterator& it)
			{
				_base = it._base;
				return (*this);
			}

			// derive from random_access_iterator
			operator reverse_iterator<random_access_iterator<value_type const> >() const
			{
				return reverse_iterator<random_access_iterator<value_type const> >(_base);
			}

			operator reverse_iterator<random_access_iterator<value_type> >()
			{
				return reverse_iterator<random_access_iterator<value_type> >(_base);
			}

			reverse_iterator& operator++()
			{
				--_base;
				return (*this);
			}

			reverse_iterator operator++(int)
			{
				reverse_iterator tmp = *this;
				--_base;
				return (tmp);
			}

			reverse_iterator& operator--()
			{
				++_base;
				return (*this);
			}

			reverse_iterator operator--(int)
			{
				reverse_iterator tmp = *this;
				++_base;
				return (tmp);
			}

			reverse_iterator& operator+=(difference_type n)
			{
				_base -= n;
				return (*this);
			}

			reverse_iterator& operator-=(difference_type n)
			{
				_base += n;
				return (*this);
			}

			reverse_iterator operator+(difference_type n) const
			{
				reverse_iterator tmp = *this;
				tmp += n;
				return (tmp);
			}

			reverse_iterator operator-(difference_type n) const
			{
				reverse_iterator tmp = *this;
				tmp -= n;
				return (tmp);
			}

			difference_type operator-(const reverse_iterator& it) const
			{
				return (_base - it._base);
			}

			reference operator[](difference_type n) const
			{
				return (*(_base - n - 1));
			}

			reference operator*() const
			{
				Iter tmp = _base;

				return (*(--tmp));
			}

			pointer operator->() const
			{
				return &(operator*());
			}

			iterator_type base() const
			{
				return (_base);
			}
			
		private:
			iterator_type _base;
		
	};
	// non member functions
	template <class Iterator>
	bool operator== (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
	{
		return (lhs.base() == rhs.base());
	}

	template <class Iterator>
	bool operator!= (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
	{
		return (lhs.base() != rhs.base());
	}

	template <class Iterator>
	bool operator< (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
	{
		return (lhs.base() > rhs.base());
	}

	template <class Iterator>
	bool operator> (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
	{
		return (lhs.base() < rhs.base());
	}

	template <class Iterator>
	bool operator<= (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
	{
		return (lhs.base() >= rhs.base());
	}

	template <class Iterator>
	bool operator>= (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
	{
		return (lhs.base() <= rhs.base());
	}

	template <class Iterator>
	reverse_iterator<Iterator> operator+ (typename reverse_iterator<Iterator>::difference_type n, const reverse_iterator<Iterator>& rev_it)
	{
		return (rev_it + n);
	}

	template <class Iterator>
	reverse_iterator<Iterator> operator- (typename reverse_iterator<Iterator>::difference_type n, const reverse_iterator<Iterator>& rev_it)
	{
		return (rev_it - n);
	}
}

#endif
