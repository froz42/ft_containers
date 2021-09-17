/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 12:34:25 by tmatis            #+#    #+#             */
/*   Updated: 2021/09/17 17:57:58 by tmatis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
#define MAP_HPP

#include <iostream>
#include <memory>
#include "../rbtree/tree.hpp"
#include "../pair/make_pair.hpp"

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

		// help compare key
		class value_compare
		{
		public:
			bool operator()(const value_type &a, const value_type &b) const
			{
				return (key_compare()(a.first, b.first));
			}
			value_compare &operator=(const value_compare &) { return *this; }
		};

		typedef
			typename _rb_tree<value_type, value_compare>::iterator
				iterator;
		typedef
			typename _rb_tree<value_type, value_compare>::const_iterator
				const_iterator;
		typedef
			typename _rb_tree<value_type, value_compare>::reverse_iterator
				reverse_iterator;
		typedef
			typename _rb_tree<value_type, value_compare>::const_reverse_iterator
				const_reverse_iterator;

		// constructors
		explicit map(const key_compare &comp = key_compare(),
					 const allocator_type &alloc = allocator_type())
			: _tree()
		{
			this->_allocator = alloc;
			this->_key_comp = comp;
			this->_value_comp = value_compare();
		}

		template <class InputIt>
		map(InputIt first, InputIt last, const Compare &comp = Compare(),
			const Allocator &alloc = Allocator());

		map(const map &other)
		{
			this->_allocator = other._allocator;
			this->_key_comp = other._key_comp;
			this->_value_comp = other._value_comp;
			this->_tree = other._tree;
		}

		~map(void) {}

		map &operator=(const map &other)
		{
			this->_allocator = other._allocator;
			this->_key_comp = other._key_comp;
			this->_value_comp = other._value_comp;
			this->_tree = other._tree;
		}

		allocator_type get_allocator() const
		{
			return (_allocator);
		}

		// element access //

		mapped_type &at(const key_type &key)
		{
			value_type *v =
				_tree.find(ft::make_pair(key, mapped_type()));
			if (v)
				return (v->second);
			throw std::out_of_range("map::at");
		}

		const mapped_type &at(const key_type &key) const
		{
			value_type *v =
				_tree.find(ft::make_pair(key, mapped_type()));
			if (v)
				return (v->second);
			throw std::out_of_range("map::at");
		}

		mapped_type &operator[](const key_type &key)
		{
			ft::pair<iterator, bool> res = _tree.find(ft::make_pair(key, mapped_type()));
			if (res.second)
				return (res.first->second);
			else
			{
				res = _tree.insert(ft::make_pair(key, mapped_type()));
				return (res.first->second);
			}
		}

		// iterator //

		iterator begin(void)
		{
			return (this->_tree.begin());
		}

		const_iterator begin(void) const
		{
			return (this->_tree.begin());
		}

		iterator end(void)
		{
			return (this->_tree.end());
		}

		const_iterator end(void) const
		{
			return (this->_tree.end());
		}

		reverse_iterator rbegin(void)
		{
			return (this->_tree.rbegin());
		}

		const_reverse_iterator rbegin(void) const
		{
			return (this->_tree.rbegin());
		}

		reverse_iterator rend(void)
		{
			return (this->_tree.rend());
		}

		const_reverse_iterator rend(void) const
		{
			return (this->_tree.rend());
		}

		// capacity //

		bool empty(void) const
		{
			return (this->_tree.size() == 0);
		}

		size_type size(void) const
		{
			return (this->_tree.size());
		}

		size_type max_size(void) const
		{
			return (this->_tree.max_size());
		}

		// modifiers //

		void clear(void)
		{
			this->_tree.clear();
		}

		ft::pair<iterator, bool> insert(const value_type &value)
		{
			return (this->_tree.insert(value));
		}

		template <class InputIt>
		void insert(InputIt first, InputIt last)
		{
			for (; first != last; ++first)
				this->_tree.insert(*first);
		}

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

	private:
		_rb_tree<value_type, value_compare> _tree;
		allocator_type _allocator;
		key_compare _key_comp;
		value_compare _value_comp;
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
