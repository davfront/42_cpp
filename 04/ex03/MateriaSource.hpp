/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapereir <dapereir@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 13:08:20 by dapereir          #+#    #+#             */
/*   Updated: 2023/06/01 22:12:07 by dapereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIA_SOURCE_HPP
# define MATERIA_SOURCE_HPP

# include <iostream>
# include "text_formatting.hpp"
# include "IMateriaSource.hpp"
# include "AMateria.hpp"

# define SRC_INVENTORY_SIZE	4

class MateriaSource: public IMateriaSource
{

	private:

		AMateria*	_inventory[SRC_INVENTORY_SIZE];

	public:

		MateriaSource(void);
		MateriaSource(MateriaSource const & src);
		virtual ~MateriaSource(void);

		MateriaSource&	operator=(MateriaSource const & rhs);

		virtual void		learnMateria(AMateria* m);
		virtual AMateria*	createMateria(std::string const & type);

};

#endif
