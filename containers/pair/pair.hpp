/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 17:17:23 by tmatis            #+#    #+#             */
/*   Updated: 2021/09/06 17:31:17 by tmatis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PAIR_HPP
#define PAIR_HPP

namespace ft
{
	template <typename T, typename U>
	class pair
	{
	public:
		// alias
		typedef T first_type;
		typedef U second_type;

		first_type first;
		second_type second;
		//constructors
		pair() : first(first_type()), second(second_type()){};
		pair(const first_type &x, const second_type &y) : first(x), second(y){};
		pair(const pair &p) : first(p.first), second(p.second){};

		//destructor
		~pair(){};

		//assignment operator
		pair &operator=(const pair &p)
		{
			first = p.first;
			second = p.second;
			return (*this);
		}
	};
	template <class T1, class T2>
	bool operator==(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
	{
		return (lhs.first == rhs.first && lhs.second == rhs.second);
	}

	template <class T1, class T2>
	bool operator!=(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
	{
		return (lhs.first != rhs.first || lhs.second != rhs.second);
	}

	template <class T1, class T2>
	bool operator<(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
	{
		return (lhs.first < rhs.first || lhs.second < rhs.second);
	}

	template <class T1, class T2>
	bool operator<=(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
	{
		return (lhs.first <= rhs.first || lhs.second <= rhs.second);
	}

	template <class T1, class T2>
	bool operator>(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
	{
		return (lhs.first > rhs.first || lhs.second > rhs.second);
	}

	template <class T1, class T2>
	bool operator>=(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
	{
		return (lhs.first >= rhs.first || lhs.second >= rhs.second);
	}
}

#endif
