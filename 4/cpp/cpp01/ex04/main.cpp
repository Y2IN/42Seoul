/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yje <yje@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 19:50:42 by yje               #+#    #+#             */
/*   Updated: 2023/03/03 17:01:50 by yje              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include <fstream>


int main(int argc, char **argv)
{
	std::ifstream ifs;
	std::ofstream ofs;
	std::string readline;

	if (argc != 4)
	{
		std::cerr << "Error : invalid arguments" <<std::endl;
		return (1);
	}
	std::string file = argv[1];
	ifs.open(file);
	if(ifs.fail())
	{
		std::cerr << "Error : file open failed" << std::endl;
		return (1);
	}
	std::string outfile = file;
	outfile.append(".replace");
	ofs.open(outfile);
	if(ofs.fail())
	{
		std::cerr << "Error : file failed" << std::endl;
		return (1);
	}
	std::string findline = argv[2]; //s1
	std::string changeline = argv[3]; //s2
	if (findline.empty())
	{
		std::cerr << "Error : Invalid s1" << std::endl;
		return (1);
	}
	while (std::getline(ifs, readline)) //file -> readline에 저장
	{
		size_t pos = 0;
		while(1)
		{
			pos = readline.find(findline);
			if (pos == std::string::npos) // not match
				break;
			readline.erase(pos, findline.length());
			readline.insert(pos, changeline);
			pos += changeline.length();
		}
		ofs << readline << std::endl;
	}
	return (0);
}




