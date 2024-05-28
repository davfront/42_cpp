/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cli_utils.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapereir <dapereir@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 13:47:32 by dapereir          #+#    #+#             */
/*   Updated: 2023/05/12 18:26:17 by dapereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLI_UTILS_HPP
# define CLI_UTILS_HPP

# include <iostream>
# include <iomanip>

namespace Txt {
	const std::string MOVEUP = "\033[A";
	const std::string CLEAR = "\033[2K";
	const std::string RESET = "\033[0m";
	const std::string BOLD = "\033[1m";
	const std::string FAINT = "\033[2m";
	const std::string UNDERLINE = "\033[4m";
	const std::string RED = "\033[31m";
	const std::string GREEN = "\033[32m";
	const std::string YELLOW = "\033[33m";
	const std::string BLUE = "\033[34m";
	const std::string PURPLE = "\033[35m";
	const std::string CYAN = "\033[36m";
}

namespace Cli {
	void	title(std::string title);
	void	msg(std::string msg);
	void	remove_previous_line(void);
	bool	field_read(std::string label, std::string &value);
	void	field_print(std::string label, std::string value, bool is_valid);
	bool	field(std::string label, std::string &value, bool is_required, bool (*is_valid)(std::string));
}

#endif
