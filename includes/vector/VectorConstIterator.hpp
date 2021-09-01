/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   VectorConstIterator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 16:15:11 by tmatis            #+#    #+#             */
/*   Updated: 2021/09/01 16:24:11 by tmatis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_CONST_ITERATOR_HPP
# define VECTOR_CONST_ITERATOR_HPP

# include <iterator>

namespace ft
{
	template <typename T>
	class VectorConstIterator
	{
		
		public:
			typedef T value_type;
			typedef value_type& reference;
			typedef value_type* pointer;
			typedef const value_type& const_reference;
			typedef const value_type* const_pointer;
			typedef std::ptrdiff_t difference_type;

			VectorConstIterator(void) : _ptr(NULL) {};
			VectorConstIterator(pointer ptr) : _ptr(ptr) {};
			VectorConstIterator(const VectorConstIterator& other) : _ptr(other._ptr) {};
			virtual ~VectorConstIterator(void) {};

			VectorConstIterator& operator=(const VectorConstIterator& other)
			{
				this->_ptr = other._ptr;
				return (*this);
			}

			bool operator==(VectorConstIterator const &other) const
			{
				return (this->_ptr == other._ptr);
			}
			bool operator!=(VectorConstIterator const &other) const
			{
				return (this->_ptr != other._ptr);
			}
			bool operator<(VectorConstIterator const &other) const
			{
				return (this->_ptr < other._ptr);
			}
			bool operator>(VectorConstIterator const &other) const
			{
				return (this->_ptr > other._ptr);
			}
			bool operator<=(VectorConstIterator const &other) const
			{
				return (this->_ptr <= other._ptr);
			}
			bool operator>=(VectorConstIterator const &other) const
			{
				return (this->_ptr >= other._ptr);
			}

			VectorConstIterator operator+(difference_type n) const
			{
				return (VectorConstIterator(this->_ptr + n));
			}
			VectorConstIterator operator-(difference_type n) const
			{
				return (VectorConstIterator(this->_ptr - n));
			}

			VectorConstIterator& operator+=(difference_type n)
			{
				this->_ptr += n;
				return (*this);
			}
			VectorConstIterator& operator-=(difference_type n)
			{
				this->_ptr -= n;
				return (*this);
			}

			VectorConstIterator& operator++(void)
			{
				++this->_ptr;
				return (*this);
			}
			VectorConstIterator& operator--(void)
			{
				--this->_ptr;
				return (*this);
			}
			
			VectorConstIterator operator++(int)
			{
				VectorConstIterator tmp(*this);
				++this->_ptr;
				return (tmp);
			}
			VectorConstIterator operator--(int)
			{
				VectorConstIterator tmp(*this);
				--this->_ptr;
				return (tmp);
			}

			const_reference operator*(void) const
			{
				return (*this->_ptr);
			}
			const_reference operator[](difference_type n) const
			{
				return (*(this->_ptr + n));
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
