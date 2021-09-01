/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   VectorIterator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 16:15:11 by tmatis            #+#    #+#             */
/*   Updated: 2021/09/01 16:24:11 by tmatis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTORITERATOR_HPP

# define VECTORITERATOR_HPP

# include <iterator>

namespace ft
{
	template <typename T>
	class VectorIterator
	{
		
		public:
			typedef T value_type;
			typedef value_type& reference;
			typedef value_type* pointer;
			typedef const value_type& const_reference;
			typedef const value_type* const_pointer;
			typedef std::ptrdiff_t difference_type;

			VectorIterator(void) : _ptr(NULL) {};
			VectorIterator(pointer ptr) : _ptr(ptr) {};
			VectorIterator(const VectorIterator& other) : _ptr(other._ptr) {};
			virtual ~VectorIterator(void) {};

			VectorIterator& operator=(const VectorIterator& other)
			{
				this->_ptr = other._ptr;
				return (*this);
			}

			bool operator==(VectorIterator const &other) const
			{
				return (this->_ptr == other._ptr);
			}
			bool operator!=(VectorIterator const &other) const
			{
				return (this->_ptr != other._ptr);
			}
			bool operator<(VectorIterator const &other) const
			{
				return (this->_ptr < other._ptr);
			}
			bool operator>(VectorIterator const &other) const
			{
				return (this->_ptr > other._ptr);
			}
			bool operator<=(VectorIterator const &other) const
			{
				return (this->_ptr <= other._ptr);
			}
			bool operator>=(VectorIterator const &other) const
			{
				return (this->_ptr >= other._ptr);
			}

			VectorIterator operator+(difference_type n) const
			{
				return (VectorIterator(this->_ptr + n));
			}
			VectorIterator operator-(difference_type n) const
			{
				return (VectorIterator(this->_ptr - n));
			}

			VectorIterator& operator+=(difference_type n)
			{
				this->_ptr += n;
				return (*this);
			}
			VectorIterator& operator-=(difference_type n)
			{
				this->_ptr -= n;
				return (*this);
			}

			VectorIterator& operator++(void)
			{
				++this->_ptr;
				return (*this);
			}
			VectorIterator& operator--(void)
			{
				--this->_ptr;
				return (*this);
			}
			
			VectorIterator operator++(int)
			{
				VectorIterator tmp(*this);
				++this->_ptr;
				return (tmp);
			}
			VectorIterator operator--(int)
			{
				VectorIterator tmp(*this);
				--this->_ptr;
				return (tmp);
			}

			reference operator*(void)
			{
				return (*this->_ptr);
			}
			const_reference operator*(void) const
			{
				return (*this->_ptr);
			}

			reference operator[](difference_type n)
			{
				return (*(this->_ptr + n));
			}
			const_reference operator[](difference_type n) const
			{
				return (*(this->_ptr + n));
			}

			pointer operator->(void)
			{
				return (this->_ptr);
			}
			const_pointer operator->(void) const
			{
				return (this->_ptr);
			}

		private:
			pointer _ptr;
	};
}
#endif
