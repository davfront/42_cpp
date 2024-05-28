/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapereir <dapereir@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 13:42:24 by dapereir          #+#    #+#             */
/*   Updated: 2023/09/21 15:22:50 by dapereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template <typename T, typename Container>
MutantStack<T, Container>::MutantStack(void):
	std::stack<T, Container>()
{
	return ;
}

template <typename T, typename Container>
MutantStack<T, Container>::MutantStack(MutantStack<T, Container> const & src):
	std::stack<T, Container>(src)
{
	return ;
}

template <typename T, typename Container>
MutantStack<T, Container>::~MutantStack(void)
{
	return ;
}

template <typename T, typename Container>
MutantStack<T, Container> &	MutantStack<T, Container>::operator=(MutantStack<T, Container> const & rhs)
{
	if (this != &rhs)
		static_cast< std::stack<T, Container> >(*this) = rhs;
	return (*this);
}

template <typename T, typename Container>
typename MutantStack<T, Container>::iterator	MutantStack<T, Container>::begin(void)
{
	return (this->c.begin());
}

template <typename T, typename Container>
typename MutantStack<T, Container>::const_iterator	MutantStack<T, Container>::begin(void) const
{
	return (this->c.begin());
}

template <typename T, typename Container>
typename MutantStack<T, Container>::iterator	MutantStack<T, Container>::end(void)
{
	return (this->c.end());
}

template <typename T, typename Container>
typename MutantStack<T, Container>::const_iterator	MutantStack<T, Container>::end(void) const
{
	return (this->c.end());
}

template <typename T, typename Container>
typename MutantStack<T, Container>::reverse_iterator	MutantStack<T, Container>::rbegin(void)
{
	return (this->c.rbegin());
}

template <typename T, typename Container>
typename MutantStack<T, Container>::const_reverse_iterator	MutantStack<T, Container>::rbegin(void) const
{
	return (this->c.rbegin());
}

template <typename T, typename Container>
typename MutantStack<T, Container>::reverse_iterator	MutantStack<T, Container>::rend(void)
{
	return (this->c.rend());
}

template <typename T, typename Container>
typename MutantStack<T, Container>::const_reverse_iterator	MutantStack<T, Container>::rend(void) const
{
	return (this->c.rend());
}
