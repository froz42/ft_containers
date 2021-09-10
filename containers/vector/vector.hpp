/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 14:53:40 by tmatis            #+#    #+#             */
/*   Updated: 2021/09/10 17:27:24 by tmatis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <memory>
#include "../iterators/random_access_iterator.hpp"
#include "../iterators/reverse_iterator.hpp"
#include "../iterators/equal.hpp"
#include "../iterators/lexicographical_compare.hpp"
#include "../sfinae/enable_if.hpp"
#include "../sfinae/is_integral.hpp"
#include <unistd.h>
#include <iostream>


namespace ft
{
	template <typename T, class Alloc = std::allocator<T> >
	class vector
	{
	public:
		// All typedef for the vector
		typedef T value_type;											  // syntax for vector<int>::value_type == int
		typedef Alloc allocator_type;									  // syntax for vector::allocator_type
		typedef typename allocator_type::reference reference;			  // T&
		typedef typename allocator_type::const_reference const_reference; // const T&
		typedef typename allocator_type::pointer pointer;				  // T*
		typedef typename allocator_type::const_pointer const_pointer;	  // const T*
		typedef size_t size_type;										  // unsigned int
		typedef std::ptrdiff_t difference_type;							  // int

		// Iterators
		typedef ft::random_access_iterator<value_type> iterator;			 // syntax for vector<int>::iterator == vector<int>::iterator
		typedef ft::random_access_iterator<value_type const> const_iterator; // syntax for vector<int>::const_iterator == vector<int>::const_iterator
		typedef ft::reverse_iterator<iterator> reverse_iterator;			 // syntax for vector<int>::reverse_iterator == vector<int>::reverse_iterator
		typedef ft::reverse_iterator<iterator> const_reverse_iterator;

		// Constructors
		explicit vector(const allocator_type &alloc = allocator_type())
			: _alloc(alloc), _size(0), _capacity(0), _data(NULL){};

		explicit vector(size_type n, const value_type &val = value_type(),
						const allocator_type &alloc = allocator_type())
			: _alloc(alloc), _size(0), _capacity(0), _data(NULL)
		{
			this->reserve(n);
			this->_size = n;
			this->_capacity = n;
			for (size_type i = 0; i < n; i++)
				_alloc.construct(&_data[i], val);
		}
		template <class InputIterator>
		vector(InputIterator first, InputIterator last, const allocator_type &alloc = allocator_type(),
				typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = NULL)
			: _alloc(alloc), _size(0), _capacity(0), _data(NULL)
		{
			size_type n = std::distance(first, last);
			this->reserve(n);
			this->_size = n;
			this->_capacity = n;
			for (size_type i = 0; i < this->_size; i++)
				_alloc.construct(&_data[i], *(first + i));
		}

		vector(const vector &x) : _alloc(x._alloc), _size(x._size), _capacity(x._capacity), _data(NULL)
		{
			if (x._data)
			{
				this->_data = _alloc.allocate(_capacity);
				for (size_type i = 0; i < _size; i++)
					_alloc.construct(&_data[i], x._data[i]);
			}
		}

		// Destructor
		virtual ~vector(void)
		{
			this->clear();
			if (_data)
				_alloc.deallocate(_data, _capacity);
		};

		vector &operator=(const vector &x)
		{
			if (this != &x)
			{
				this->clear();
				if (_data)
					_alloc.deallocate(_data, _capacity);
				this->_size = x._size;
				this->_capacity = x._capacity;
				this->_data = _alloc.allocate(_capacity);
				for (size_type i = 0; i < _size; i++)
					_alloc.construct(&_data[i], x._data[i]);
			}
			return *this;
		}

		size_type size(void) const
		{
			return _size;
		}

		size_type max_size(void) const
		{
			return _alloc.max_size();
		}

		size_type capacity(void) const
		{
			return (_capacity);
		}

		iterator begin(void)
		{
			return iterator(_data);
		}
		iterator end(void)
		{
			return iterator(_data + _size);
		}
		reverse_iterator rbegin(void)
		{
			return reverse_iterator(_data + _size);
		}
		reverse_iterator rend(void)
		{
			return reverse_iterator(_data);
		}
		const_iterator begin(void) const
		{
			return const_iterator(_data);
		}
		const_iterator end(void) const
		{
			return const_iterator(_data + _size);
		}
		const_reverse_iterator rbegin(void) const
		{
			return const_reverse_iterator(_data);
		}
		const_reverse_iterator rend(void) const
		{
			return const_reverse_iterator(_data);
		}

		bool empty(void) const
		{
			return (_size == 0);
		}

		void clear(void)
		{
			for (size_type i = 0; i < _size; i++)
				_alloc.destroy(&_data[i]);
			_size = 0;
		}

		void reserve(size_type n)
		{
			if (n > this->max_size())
				throw std::length_error("n greater than vector::max_size()");
			if (n > _capacity)
			{
				value_type *tmp = _alloc.allocate(n);

				for (size_type i = 0; i < _size; i++)
				{
					_alloc.construct(&tmp[i], _data[i]);
					_alloc.destroy(&_data[i]);
				}
				if (_data)
					_alloc.deallocate(_data, _capacity);
				_capacity = n;
				_data = tmp;
			}
		}
		void resize(size_type n, value_type val = value_type())
		{
			if (n > _capacity)
				this->reserve(n);
			if (n > _size)
			{
				for (size_type i = _size; i < n; i++)
					_alloc.construct(&_data[i], val);
				_size = n;
			}
			else if (n < _size)
			{
				for (size_type i = n; i < _size; i++)
					_alloc.destroy(&_data[i]);
				_size = n;
			}
		}
		reference operator[](size_type n)
		{
			return _data[n];
		}
		const_reference operator[](size_type n) const
		{
			return _data[n];
		}
		reference at(size_type n)
		{
			if (n >= _size)
				throw std::out_of_range("out of range");
			return _data[n];
		}
		const_reference at(size_type n) const
		{
			if (n >= _size)
				throw std::out_of_range("out of range");
			return _data[n];
		}
		reference front(void)
		{
			return _data[0];
		}
		const_reference front(void) const
		{
			return _data[0];
		}
		reference back(void)
		{
			return _data[_size - 1];
		}
		const_reference back(void) const
		{
			return _data[_size - 1];
		}

		void push_back(const value_type &val)
		{
			if (_size == _capacity)
				this->_extend();
			_alloc.construct(&_data[_size], val);
			_size++;
		}

		void pop_back(void)
		{
			_alloc.destroy(&_data[_size - 1]);
			_size--;
		}

		void swap(vector &x)
		{
			std::swap(_data, x._data);
			std::swap(_size, x._size);
			std::swap(_capacity, x._capacity);
			std::swap(_alloc, x._alloc);
		}


		iterator insert(iterator position, const value_type &val)
		{
			size_type i = &*position - &*begin();

			if (_size == _capacity)
				this->_extend();
			this->_shift_right(i, 1);
			_alloc.construct(&_data[i], val);
			_size++;
			return iterator(&_data[i]);
		}
		
		//TODO: rewrite this function
		void insert(iterator position, size_type n, const value_type &val)
		{
			size_type i = &*position - &*begin();

			if (_size + n > _capacity)
				this->reserve(_size + n);
			this->_shift_right(i, n);
			for (size_type j = 0; j < n; j++)
				_alloc.construct(&_data[i + j], val);
			_size += n;
		}

		//TODO: rewrite this function
		template <class InputIterator>
		void insert(iterator position, InputIterator first, InputIterator last,
				typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = NULL)
		{
			size_type i = &*position - &*begin();
			size_type n = std::distance(first, last);

			if (_size + n > _capacity)
				this->reserve(_size + n);
			this->_shift_right(i, n);
			for (size_type j = 0; j < n; j++)
				_alloc.construct(&_data[i + j], *(first + j));
			_size += n;
		}

		iterator erase(iterator position)
		{
			size_type i = &*position - &*begin();

			_alloc.destroy(&_data[i]);
			this->_shift_left(i, 1);
			_size--;
			return iterator(&_data[i]);			
		}

		iterator erase(iterator first, iterator last)
		{
			size_type i = &*first - &*begin();
			size_type j = &*last - &*begin();

			for (size_type k = i; k < j; k++)
				_alloc.destroy(&_data[k]);
			this->_shift_left(i, j - i);
			_size -= j - i;
			return iterator(&_data[i]);
		}

		template <class InputIterator>
		void assign(InputIterator first, InputIterator last, 
			typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = NULL)
		{
			size_type n = std::distance(first, last);
			if (n > _capacity)
				this->reserve(n);
			for (size_type i = 0; i < _size; i++)
				_alloc.destroy(&_data[i]);
			for (size_type i = 0; i < n; i++)
				_alloc.construct(&_data[i], *first++);
			this->_size = n;
		}
		
		void assign(size_type n, const value_type &val)
		{
			if (n > _capacity)
				this->reserve(n);
			for (size_type i = 0; i < _size; i++)
				_alloc.destroy(&_data[i]);
			for (size_type i = 0; i < n; i++)
				_alloc.construct(&_data[i], val);
			this->_size = n;
		}

		allocator_type get_allocator() const
		{
			return _alloc;
		}

	private:
		allocator_type _alloc;
		size_type _size;
		size_type _capacity;
		pointer _data;

		void _extend(void)
		{
			if (_capacity == 0)
				this->reserve(1);
			else
			{
				size_type new_capacity = _capacity * 2;
				this->reserve(new_capacity);
			}
		}
		void _extend(size_type n)
		{
			size_type new_capacity = _capacity + n;
			this->reserve(new_capacity);
		}
		void _shift_right(size_type position, size_type n)
		{
			if (empty())
				return;
			for (size_type i = _size - 1; i >= position; i--)
			{
				_alloc.construct(&_data[i + n], _data[i]);
				_alloc.destroy(&_data[i]);
			}
		}
		void _shift_left(size_type position, size_type n)
		{
			if (empty())
				return;
			for (size_type i = position; i < _size - n; i++)
			{
				_alloc.construct(&_data[i], _data[i + n]);
				_alloc.destroy(&_data[i + n]);
			}
		}
	};
	template <class T, class Alloc>
	bool operator==(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
	{
		if (lhs.size() != rhs.size())
			return false;
		return (ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
	}

	template <class T, class Alloc>
	bool operator!=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
	{
		return !(lhs == rhs);
	}

	template <class T, class Alloc>
	bool operator<(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
	{
		return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
	}

	template <class T, class Alloc>
	bool operator<=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
	{
		if (lhs == rhs)
			return true;
		return (lhs < rhs);
	}

	template <class T, class Alloc>
	bool mycomp(const T &lhs, const T &rhs)
	{
		return (lhs > rhs);
	}

	template <class T, class Alloc>
	bool operator>(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
	{
		return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end(), mycomp);
	}

	template <class T, class Alloc>
	bool operator>=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
	{
		if (lhs == rhs)
			return true;
		return (lhs > rhs);
	}

	template <class T, class Alloc>
	void swap (vector<T,Alloc>& x, vector<T,Alloc>& y)
	{
		x.swap(y);
	}
}

#endif
