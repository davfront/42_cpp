/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapereir <dapereir@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 22:01:25 by dapereir          #+#    #+#             */
/*   Updated: 2023/05/24 21:26:19 by dapereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

bool	read_file(std::string file, std::string& str)
{
	std::ifstream	ifs(file.c_str());
	std::string		line;

	if (!ifs)
	{
		std::cerr << "[ERROR] \"" << file << "\" cannot be read" << std::endl;
		return (false);
	}
	str = "";
	while (std::getline(ifs, line))
	{
		str += line;
        if (!ifs.eof())
            str += '\n';
	}
	return (true);
}

bool	write_file(std::string file, std::string str)
{
	std::ofstream	ofs(file.c_str());

	if (!ofs)
	{
		std::cerr << "[ERROR] \"" << file << "\" cannot be updated" << std::endl;
		return (false);
	}
	ofs << str;
	return (true);
}

void	replace_all(std::string& s, std::string a, std::string b)
{
	size_t	pos;

	if (s.empty() || a.empty())
		return ;
	pos = s.find(a);
	while (pos != std::string::npos)
	{
		s.erase(pos, a.length());
		s.insert(pos, b);
		pos = s.find(a, pos + b.length());
	}
}

int main(int argc, char **argv)
{
	std::string		str;

	if (argc != 4)
	{
		std::cout << "[USAGE] " << argv[0] << " <infile> <string_to_replace> <replacement>" << std::endl;
		return (1);
	}
	if (!read_file(argv[1], str))
		return (1);
	replace_all(str, argv[2], argv[3]);
	if (!write_file(argv[1] + std::string(".replace"), str))
		return (1);
	return (0);
}
