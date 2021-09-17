/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_map.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 17:12:49 by tmatis            #+#    #+#             */
/*   Updated: 2021/09/17 17:15:43 by tmatis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.hpp"


void test_map(void)
{
	TESTED_NAMESPACE::map<std::string, int> m;

	module_test("map::size", m.size());
	module_test("map::empty", m.empty());
	module_test("map::max_size", m.max_size());
}
