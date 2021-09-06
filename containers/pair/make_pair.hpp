/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_pair.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 17:31:39 by tmatis            #+#    #+#             */
/*   Updated: 2021/09/06 17:34:57 by tmatis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAKE_PAIR_HPP
# define MAKE_PAIR_HPP

# include "pair.hpp"

namespace ft
{
	template <typename T1, typename T2>
	pair<T1, T2> make_pair(T1 const &t1, T2 const &t2)
	{
		return (ft::pair<T1, T2>(t1, t2));
	}
}

#endif
