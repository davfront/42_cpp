/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapereir <dapereir@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 16:01:12 by dapereir          #+#    #+#             */
/*   Updated: 2023/09/15 14:39:30 by dapereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <stdint.h>
# include <string>
# include <iostream>

typedef struct s_data {
	std::string	name;
	int			age;
	bool		isMale;
}				Data;

class Serializer {

	private:

		Serializer(void);
		Serializer(Serializer const & src);

		~Serializer(void);

		Serializer &	operator=(Serializer const & rhs);

	public:

		static uintptr_t	serialize(Data* ptr);
		static Data*		deserialize(uintptr_t raw);

};

#endif
