/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 13:17:42 by tmatis            #+#    #+#             */
/*   Updated: 2021/09/06 17:43:22 by tmatis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef TEST_HPP
# define TEST_HPP

#include <iostream>
#include "../containers/ft.hpp"
#include "test.hpp"
#include <vector>

#ifndef TESTED_NAMESPACE
# define TESTED_NAMESPACE std
#endif

void module_foot(void);
void module_head(std::string name);

template <typename T>
void module_test(std::string name, T result)
{
	module_head(name);
	std::cout << result << std::endl;
	module_foot();
}

void test_vector(void);
void test_iterator(void);
void test_sfinae(void);
void test_pair(void);
#endif
