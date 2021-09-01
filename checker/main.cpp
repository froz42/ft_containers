/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 18:21:24 by tmatis            #+#    #+#             */
/*   Updated: 2021/09/01 19:29:42 by tmatis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <iostream>
#include <string>


void test_module(
		std::string module_name, std::ifstream &file1, std::ifstream &file2, int &test_ok)
{
	std::string line1;
	std::string line2;
	bool ko = false;

	//fancy blue output
	std::cout << "\033[1;36m";
	//cyan output
	std::cout << "   >>> \033[1;34m" << module_name << ":	";
	while (std::getline(file1, line1) && std::getline(file2, line2)
	&& line1 != "<<<")
	{
		if (line1 != line2)
		{
			if (!ko)
			{
				std::cout << "\033[0;31m[KO]\033[0m" << std::endl;
				ko = true;
			}
			std::cout << "	" << "\"\033[0;31m" << line1 << "\033[0m\"";
			std::cout << " != ";
			std::cout << "\"\033[0;31m" << line2 << "\033[0m\"";
			std::cout << std::endl;
		}
	}
	if (!ko)
	{
		std::cout << "\033[0;32m[OK]\033[0m" << std::endl;
		test_ok++;
	}
}

int main(void)
{
	std::ifstream in_stl("stl.out");
	std::ifstream in_ft("ft.out");
	std::string line_stl("");
	std::string line_ft("");
	int test_count = 0;
	int test_ok = 0;

	std::cout << "[[[ \033[1;33mtmatis\033[0m's \033[1;36mft_container \033[1;34mchecker\033[0m ]]]" << std::endl;
	if (!in_stl.is_open() || !in_ft.is_open())
	{
		std::cout << "Error: Can't open files" << std::endl;
		return (1);
	}

	while (!in_stl.eof() && !in_ft.eof())
	{
		std::getline(in_stl, line_stl);
		std::getline(in_ft, line_ft);
		if (line_stl != line_ft)
		{
			std::cout << "Error: unexpected difference" << std::endl;
			return (1);
		}
		if (line_stl.find(">>> ") == 0)
		{
			test_count++;
			test_module(line_stl.substr(4), in_stl, in_ft, test_ok);
		}
	}
	if (!in_stl.eof() || !in_ft.eof())
	{
		std::cout << "Error: Files are not the same size" << std::endl;
		return (1);
	}
	std::cout << "\033[1;36m>>> \033[1;35mtest sumary: ";

	if (test_count == test_ok)
		std::cout << "\033[0;32m" << test_ok << "/" << test_count << "\033[0m" << std::endl;
	else
		std::cout << "\033[0;31m" << test_ok << "/" << test_count << "\033[0m" << std::endl;

}
