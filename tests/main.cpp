/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 19:04:30 by tmatis            #+#    #+#             */
/*   Updated: 2021/09/01 19:29:04 by tmatis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

void module_head(std::string module_name)
{
	std::cout << ">>> " << module_name << std::endl;
}

void module_foot(void)
{
	std::cout << "<<<" << std::endl;
}

int main(void)
{
	module_head("witness test");
	std::cout << "Hello World!" << std::endl;
	module_foot();
	module_head("witness test 2");
	std::cout << "Hello World!" << std::endl;
	std::cout << "Hello World!" << std::endl;
	module_foot();
}
