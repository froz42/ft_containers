/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_vector.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 13:23:22 by tmatis            #+#    #+#             */
/*   Updated: 2021/09/02 13:39:55 by tmatis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.hpp"

void test_empty_vector(void)
{
	TESTED_NAMESPACE::vector<int> v;
	TESTED_NAMESPACE::vector<int> v2(v);
	TESTED_NAMESPACE::vector<int> v3;
	v3 = v;
	module_test("[empty] vector::max_size", v.max_size());
	module_test("[empty] vector::size", v.size());
	module_test("[empty] vector::empty", v.empty());
	module_test("[empty] vector::operator=", v3.size() == v.size());
	module_test("[empty] vector::operator=", v3.empty() == v.empty());
	module_test("[empty] vector::begin", &*v.begin());
	module_test("[empty] vector::end", &*v.end());
	module_test("[empty] vector::rbegin", &*v.rbegin());
	module_test("[empty] vector::rend", &*v.rend());

}

void test_vector(void)
{
	test_empty_vector();
}
