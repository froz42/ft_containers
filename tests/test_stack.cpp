/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_stack.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 12:11:45 by tmatis            #+#    #+#             */
/*   Updated: 2021/09/11 12:32:24 by tmatis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.hpp"

static void test_relational_operators()
{
	TESTED_NAMESPACE::stack<int> stack;
	TESTED_NAMESPACE::stack<int> stack2;
	TESTED_NAMESPACE::stack<int> stack3;
	TESTED_NAMESPACE::stack<int> stack4;

	for (int i = 0; i < 10; i++)
		stack.push(i);
	for (int i = 0; i < 10; i++)
		stack2.push(i);
	for (int i = 0; i < 10; i++)
		stack3.push(6);
	for (int i = 0; i < 10; i++)
		stack4.push(7);
	
	module_test("stack::operator==", stack == stack2);
	module_test("stack::operator!=", stack != stack3);
	module_test("stack::operator<", stack < stack4);
	module_test("stack::operator<=", stack <= stack4);
	module_test("stack::operator>", stack > stack3);
	module_test("stack::operator>=", stack >= stack3);
}

void test_stack()
{
	TESTED_NAMESPACE::stack<int> stack;

	module_test("stack::empty (default constructor)", stack.empty());
	module_test("stack::size (default constructor)", stack.size());
	module_head("stack::push");
	for (int i = 0; i < 100; i++)
		stack.push(i);
	module_test("stack::empty (push)", !stack.empty());
	module_test("stack::size (push)", stack.size());
	module_head("stack::pop");
	for (int i = 0; i < 50; i++)
		stack.pop();
	module_test("stack::empty (pop)", stack.empty());
	module_test("stack::size (pop)", stack.size());
	module_test("stack::top", stack.top());	
	
	test_relational_operators();
}


