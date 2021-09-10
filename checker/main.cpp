/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 18:21:24 by tmatis            #+#    #+#             */
/*   Updated: 2021/09/10 17:41:24 by tmatis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>
#include <limits.h>
#include <math.h>

bool show_ok = false;

void show_module_result(std::string &module_name, bool ok)
{
	std::cout << "\033[1;36m";
	std::cout << "   >>> \033[1;34m" << module_name << " ";
	if (ok)
	{
		std::cout << std::right << std::setw(70 - module_name.length())
			<< "\033[0;32m[OK]\033[0m" << std::endl;
	}
	else
	{
		std::cout << std::right << std::setw(70 - module_name.length())
			<< "\033[0;31m[KO]\033[0m" << std::endl;
	}
}

void test_module(
		std::string module_name, std::ifstream &file1, std::ifstream &file2, int &test_ok)
{
	std::string line1;
	std::string line2;
	bool ko = false;
	
	while (std::getline(file1, line1) && std::getline(file2, line2)
	&& line1.find("<<< ") != 0)
	{
		if (line1 != line2)
		{
			if (!ko)
			{
				show_module_result(module_name, false);
				ko = true;
			}
			std::cout << "\"\033[0;31m" << line1 << "\033[0m\"";
			std::cout << " != ";
			std::cout << "\"\033[0;31m" << line2 << "\033[0m\"";
			std::cout << " (slt != ft)";
			std::cout << std::endl;
		}
	}
	if (!ko && show_ok)
		show_module_result(module_name, true);
	if (line1.find("<<< ") == 0)
	{
		std::string time_to_parse_stl = line1.substr(4);
		std::string time_to_parse_ft = line2.substr(4);
		double		time_slt = atof(time_to_parse_stl.c_str());
		double		time_ft = atof(time_to_parse_ft.c_str());

		//check if time_ft is less that time_stl * 20
		if (time_ft > time_slt * 20)
		{
			if (!ko && !show_ok)
				show_module_result(module_name, true);
			std::cout << "\033[0;31m    >>> \033[1;34m test too slow:"
			<< std::fixed << "\x1B[0m [\033[0;31m" << time_ft << "\x1B[0m] / [\033[0;32m" << time_slt << "\x1B[0m]" << std::endl;
		}
		else if (!ko)
			test_ok++;
	}
}

int main(int argc, char **argv)
{
	std::ifstream in_stl("stl.out");
	std::ifstream in_ft("ft.out");
	std::string line_stl("");
	std::string line_ft("");
	int test_count = 0;
	int test_ok = 0;

	//detect if argv[1] is equal to "--show-ok"
	if (argc >= 2 && std::string(argv[1]) == "--show-ok")
		show_ok = true;
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
		std::cout << "stl.out: " << line_stl << std::endl;
		std::cout << "ft.out: " << line_ft << std::endl;
		return (1);
	}
	std::cout << "\033[1;36m>>> \033[1;35mtest sumary: ";

	if (test_count == test_ok)
		std::cout << "\033[0;32m" << test_ok << "/" << test_count << "\033[0m" << std::endl;
	else
		std::cout << "\033[0;31m" << test_ok << "/" << test_count << "\033[0m" << std::endl;
	return (test_ok != test_count);
}
