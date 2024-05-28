/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapereir <dapereir@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 15:05:06 by dapereir          #+#    #+#             */
/*   Updated: 2023/09/18 16:27:54 by dapereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template <typename T>
Array<T>::Array(void): _size(0), _array(NULL) 
{
	return ;
}

template <typename T>
Array<T>::Array(unsigned int n): _size(n), _array(new T[n]) 
{
	return ;
}

template <typename T>
Array<T>::Array(Array const & src): _size(src.size()), _array(new T[src.size()]) 
{
	for (size_t i = 0; i < this->_size; i++) {
		this->_array[i] = src[i];
	}
	return ;
}

template <typename T>
Array<T>::~Array(void)
{
	delete [] this->_array;
	return ;
}

template <typename T>
Array<T> &	Array<T>::operator=(Array const & rhs)
{
	if (this != &rhs)
	{
		delete [] this->_array;
		this->_size = rhs.size();
		this->_array = new T[this->_size];
		for (size_t i = 0; i < this->_size; i++) {
			this->_array[i] = rhs[i];
		}
	}
	return (*this);
}

template <typename T>
T &	Array<T>::operator[](unsigned int index)
{
	if (index >= this->_size) {
		throw Array<T>::OutOfBoundsIndexException();
	}
	return (this->_array[index]);
}

template <typename T>
T const &	Array<T>::operator[](unsigned int index) const
{
	if (index >= this->_size) {
		throw Array<T>::OutOfBoundsIndexException();
	}
	return (this->_array[index]);
}

template <typename T>
unsigned int const &	Array<T>::size(void) const
{
	return (this->_size);
}

template <typename T>
std::ostream &	operator<<(std::ostream & o, Array<T> const & rhs)
{
	size_t	size = rhs.size();
	
	o << "[" << size << "]";
	
	o << "{";
	for (size_t i = 0; i < size; i++) {
		o << rhs[i] << ( (i + 1 < size) ? ", " : "" );
	}
	o << "}";

	return (o);
}
