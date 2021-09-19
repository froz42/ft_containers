/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 14:04:49 by tmatis            #+#    #+#             */
/*   Updated: 2021/09/19 15:48:12 by tmatis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SET_HPP
#define SET_HPP

#include <iostream>
#include <memory>
#include "../rbtree/tree.hpp"
#include "../iterators/lexicographical_compare.hpp"
#include "../iterators/equal.hpp"

namespace ft
{
	template <
		class Key,
		class Compare = std::less<Key>,
		class Allocator = std::allocator<Key> >
	class set
	{
	public:
		typedef Key key_type;
		typedef Key value_type;
		typedef std::size_t size_type;
		typedef std::ptrdiff_t difference_type;
		typedef Compare value_compare;
		typedef Compare key_compare;
		typedef Allocator allocator_type;
		typedef value_type &reference;
		typedef const value_type &const_reference;
		typedef value_type *pointer;
		typedef const value_type *const_pointer;
		typedef typename _rb_tree<value_type, value_compare>::iterator iterator;
		typedef typename _rb_tree<value_type, value_compare>::const_iterator const_iterator;
		typedef typename _rb_tree<value_type, value_compare>::reverse_iterator reverse_iterator;
		typedef typename _rb_tree<value_type, value_compare>::const_reverse_iterator const_reverse_iterator;

		// Constructors & destructor //
		explicit set(const key_compare &comp = key_compare(),
					 const allocator_type &alloc = allocator_type());

		template <class InputIterator>
		set(InputIterator first, InputIterator last,
			const key_compare &comp = key_compare(),
			const allocator_type &alloc = allocator_type());

		set(const set &s);

		~set(void);

		set &operator=(const set &s);

		allocator_type get_allocator(void) const;

		// iterators //

		iterator begin(void);

		const_iterator begin(void) const;

		iterator end(void);

		const_iterator end(void) const;

		reverse_iterator rbegin(void);

		const_reverse_iterator rbegin(void) const;

		reverse_iterator rend(void);

		const_reverse_iterator rend(void) const;

		// capacity //

		size_type size(void) const;

		size_type max_size(void) const;

		bool empty(void) const;

		// modifiers //

		void clear(void);

		ft::pair<iterator, bool> insert(const value_type &value);

		iterator insert(iterator hint, const value_type &value);

		template <class InputIt>
		void insert(InputIt first, InputIt last);

		void erase(iterator pos);

		void erase(iterator first, iterator last);

		size_type erase(const key_type &key);

		void swap(set &s);

		// lookup //

		size_type count(const key_type &key) const;

		iterator find(const Key &key);

		const_iterator find(const Key &key) const;

		iterator lower_bound(const Key &key);

		const_iterator lower_bound(const Key &key) const;

		iterator upper_bound(const Key &key);

		const_iterator upper_bound(const Key &key) const;

		ft::pair<iterator, iterator> equal_range(const Key &key);

		ft::pair<const_iterator, const_iterator>
		equal_range(const Key &key) const;

		// Observers //

		key_compare key_comp(void) const;

		value_compare value_comp(void) const;

	private:
		_rb_tree<value_type, value_compare> _tree;
		allocator_type _alloc;
		key_compare _comp;
	};

	template <class Key, class Compare, class Alloc>
	bool operator==(const ft::set<Key, Compare, Alloc> &lhs,
					const ft::set<Key, Compare, Alloc> &rhs);

	template <class Key, class Compare, class Alloc>
	bool operator!=(const ft::set<Key, Compare, Alloc> &lhs,
					const ft::set<Key, Compare, Alloc> &rhs);
					
	template <class Key, class Compare, class Alloc>
	bool operator<(const ft::set<Key, Compare, Alloc> &lhs,
				   const ft::set<Key, Compare, Alloc> &rhs);

	template <class Key, class Compare, class Alloc>
	bool operator<=(const ft::set<Key, Compare, Alloc> &lhs,
					const ft::set<Key, Compare, Alloc> &rhs);

	template <class Key, class Compare, class Alloc>
	bool operator>(const ft::set<Key, Compare, Alloc> &lhs,
				   const ft::set<Key, Compare, Alloc> &rhs);

	template <class Key, class Compare, class Alloc>
	bool operator>=(const ft::set<Key, Compare, Alloc> &lhs,
					const ft::set<Key, Compare, Alloc> &rhs);
}

#endif
