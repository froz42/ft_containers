/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 02:29:40 by tmatis            #+#    #+#             */
/*   Updated: 2021/09/11 12:42:57 by tmatis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
#define STACK_HPP

#include "../vector/vector.hpp"

namespace ft
{
	template <class T, class Container = ft::vector<T> >
	class stack
	{
		/* relational operator friend */
		template <class U, class V>
		friend bool operator==(const stack<U, V> &, const stack<U, V> &);
		template <class U, class V>
		friend bool operator!=(const stack<U, V> &, const stack<U, V> &);
		template <class U, class V>
		friend bool operator<(const stack<U, V> &, const stack<U, V> &);
		template <class U, class V>
		friend bool operator>(const stack<U, V> &, const stack<U, V> &);
		template <class U, class V>
		friend bool operator<=(const stack<U, V> &, const stack<U, V> &);
		template <class U, class V>
		friend bool operator>=(const stack<U, V> &, const stack<U, V> &);

	public:

		/* typedefs */
		typedef T value_type;
		typedef Container container_type;
		typedef typename container_type::size_type size_type;

		/* constructors */
		explicit stack(const container_type &ctnr = container_type()) : _ctnr(ctnr) {}

		/* destructor */
		~stack(void) {}

		bool empty(void) const
		{
			return (this->_ctnr.empty());
		}

		size_type size(void) const
		{
			return (this->_ctnr.size());
		}

		value_type &top(void)
		{
			return (this->_ctnr.back());
		}

		const value_type &top(void) const
		{
			return (this->_ctnr.back());
		}

		void push(const value_type &val)
		{
			this->_ctnr.push_back(val);
		}

		void pop(void)
		{
			this->_ctnr.pop_back();
		}

	private:
		container_type _ctnr;
	};
	
	/* non relational operators */
	template <class T, class Container>
	bool operator==(const stack<T, Container> &lhs, const stack<T, Container> &rhs)
	{
		return (lhs._ctnr == rhs._ctnr);
	}

	template <class T, class Container>
	bool operator!=(const stack<T, Container> &lhs, const stack<T, Container> &rhs)
	{
		return (lhs._ctnr != rhs._ctnr);
	}

	template <class T, class Container>
	bool operator<(const stack<T, Container> &lhs, const stack<T, Container> &rhs)
	{
		return (lhs._ctnr < rhs._ctnr);
	}

	template <class T, class Container>
	bool operator<=(const stack<T, Container> &lhs, const stack<T, Container> &rhs)
	{
		return (lhs._ctnr <= rhs._ctnr);
	}

	template <class T, class Container>
	bool operator>(const stack<T, Container> &lhs, const stack<T, Container> &rhs)
	{
		return (lhs._ctnr > rhs._ctnr);
	}

	template <class T, class Container>
	bool operator>=(const stack<T, Container> &lhs, const stack<T, Container> &rhs)
	{
		return (lhs._ctnr >= rhs._ctnr);
	}
}

#endif
