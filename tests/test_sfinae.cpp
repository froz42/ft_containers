/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_sfinae.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 21:30:40 by tmatis            #+#    #+#             */
/*   Updated: 2021/09/05 23:16:39 by tmatis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.hpp"
#include <iostream>

class A {};
 
enum E : int {};

template <class T>
typename ft::enable_if<ft::is_integral<T>::value, bool>::type
  is_odd (T i) {return bool(i%2);}


void test_sfinae()
{
	module_head("sfinae");
	std::cout << std::boolalpha;
    std::cout << ft::is_integral<A>::value << '\n';
    std::cout << ft::is_integral<E>::value << std::endl;
    std::cout << ft::is_integral<float>::value << std::endl;
    std::cout << ft::is_integral<int>::value << std::endl;
    std::cout << ft::is_integral<const int>::value << std::endl;
    std::cout << ft::is_integral<bool>::value << std::endl;
	std::cout << is_odd(2) << std::endl;
	//std::cout << is_odd(3.0) << std::endl;
	module_foot();
}
