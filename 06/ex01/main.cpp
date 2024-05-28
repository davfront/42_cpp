/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapereir <dapereir@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 10:48:14 by dapereir          #+#    #+#             */
/*   Updated: 2023/09/15 14:45:28 by dapereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int	main(void)
{
	std::cout << std::endl;
		Data	data;
		data.name = "John";
		data.age = 32;
		data.isMale = true;
		std::cout << "data: (name: " << data.name << ", age: " << data.age << ", isMale: " << data.isMale << ")" << std::endl;
		std::cout << "&data: " << &data << std::endl;

	std::cout << std::endl;
		uintptr_t	raw = Serializer::serialize(&data);
		std::cout << "raw: " << raw << std::endl;

	std::cout << std::endl;
		Data*	ptr = Serializer::deserialize(raw);
		std::cout << "ptr: " << ptr << std::endl;
		std::cout << "*ptr: (name: " << ptr->name << ", age: " << ptr->age << ", isMale: " << ptr->isMale << ")" << std::endl;

	std::cout << std::endl;

	return (0);
}
