/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 12:34:25 by tmatis            #+#    #+#             */
/*   Updated: 2021/09/17 13:41:57 by tmatis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
#define MAP_HPP

#include <iostream>
#include <memory>
#include "../rbtree/tree.hpp"
#include "../pair/pair.hpp"

namespace ft
{
	template <
		class Key,
		class T,
		class Compare = std::less<Key>,
		class Allocator = std::allocator<ft::pair<Key, T> > >
	class map
	{
	public:
		// typedef
		typedef Key key_type;
		typedef T mapped_type;
		typedef ft::pair<key_type, mapped_type> value_type;
		typedef std::size_t size_type;
		typedef std::ptrdiff_t difference_type;
		typedef Compare key_compare;
		typedef Allocator allocator_type;
		typedef value_type &reference;
		typedef const value_type &const_reference;
		typedef value_type *pointer;
		typedef const value_type *const_pointer;
		typedef
			typename _rb_tree<value_type, key_compare>::iterator
				iterator;
		typedef
			typename _rb_tree<value_type, key_compare>::const_iterator
				const_iterator;
		typedef
			typename _rb_tree<value_type, key_compare>::reverse_iterator
				reverse_iterator;
		typedef
			typename _rb_tree<value_type, key_compare>::const_reverse_iterator
				const_reverse_iterator;

		// help compare key
		class value_compare
		{
		public:
			bool operator()(const value_type &a, const value_type &b) const
			{
				return (key_compare()(a.first, b.first));
			}
		};

		// constructors
		map(void);

		explicit map(const Compare &comp, const Allocator &alloc = Allocator());

		template <class InputIt>
		map(InputIt first, InputIt last, const Compare &comp = Compare(),
			const Allocator &alloc = Allocator());

		map(const map &other);

		~map(void);

		map &operator=(const map &other);

		allocator_type get_allocator() const;

		// element access //

		mapped_type &at(const key_type &key);

		const mapped_type &at(const key_type &key) const;

		mapped_type &operator[](const key_type &key);

		const mapped_type &operator[](const key_type &key) const;

		// iterator //

		iterator begin(void);

		const_iterator begin(void) const;

		iterator end(void);

		const_iterator end(void) const;

		reverse_iterator rbegin(void);

		const_reverse_iterator rbegin(void) const;

		reverse_iterator rend(void);

		const_reverse_iterator rend(void) const;

		// capacity //

		bool empty(void) const;

		size_type size(void) const;

		size_type max_size(void) const;

		// modifiers //

		void clear(void);

		ft::pair<iterator, bool> insert(const value_type &value);

		template <class InputIt>
		void insert(InputIt first, InputIt last);

		void erase(iterator pos);

		void erase(iterator first, iterator last);

		size_type erase(const key_type &key);

		void swap(map &other);

		// lookups //

		size_type count(const key_type &key) const;

		iterator find(const key_type &key);

		const_iterator find(const key_type &key) const;

		ft::pair<iterator, iterator> equal_range(const Key &key);

		ft::pair<const_iterator, const_iterator> equal_range(const Key &key) const;

		iterator lower_bound(const Key &key);

		const_iterator lower_bound(const Key &key) const;

		iterator upper_bound(const Key &key);

		const_iterator upper_bound(const Key &key) const;

		// observers //

		key_compare key_comp(void) const;

		value_type value_comp(void) const;
	};

	// non-member functions //

	template <class Key, class T, class Compare, class Alloc>
	bool operator==(const ft::map<Key, T, Compare, Alloc> &lhs,
					const ft::map<Key, T, Compare, Alloc> &rhs);

	template <class Key, class T, class Compare, class Alloc>
	bool operator!=(const ft::map<Key, T, Compare, Alloc> &lhs,
					const ft::map<Key, T, Compare, Alloc> &rhs);

	template <class Key, class T, class Compare, class Alloc>
	bool operator<(const ft::map<Key, T, Compare, Alloc> &lhs,
				   const ft::map<Key, T, Compare, Alloc> &rhs);

	template <class Key, class T, class Compare, class Alloc>
	bool operator>(const ft::map<Key, T, Compare, Alloc> &lhs,
				   const ft::map<Key, T, Compare, Alloc> &rhs);

	template <class Key, class T, class Compare, class Alloc>
	bool operator<=(const ft::map<Key, T, Compare, Alloc> &lhs,
					const ft::map<Key, T, Compare, Alloc> &rhs);

	template <class Key, class T, class Compare, class Alloc>
	bool operator>=(const ft::map<Key, T, Compare, Alloc> &lhs,
					const ft::map<Key, T, Compare, Alloc> &rhs);

	template <class Key, class T, class Compare, class Alloc>
	void swap(ft::map<Key, T, Compare, Alloc> &lhs,
			  ft::map<Key, T, Compare, Alloc> &rhs);
}

#endif
