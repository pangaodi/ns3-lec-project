/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */
/*
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation;
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#include "ns3/core-module.h"

#include <iostream>

using namespace ns3;

NS_LOG_COMPONENT_DEFINE ("HelloSimulator");

static void printHello(std::string word,float f) {
	std::cout<<Simulator::Now()<<" Hello "<<word<<" "<<f<<std::endl;
	Simulator::Schedule(Seconds(f),&printHello,word,f);
}
// ./test arg0 arg1 arg2
// argc=4
// argv[0] -> "test"
// argv[1] -> "arg0"
// argv[2] -> "arg1"
// argv[3] -> "arg2"
// argv[4] -> NULL

int
main (int argc, char *argv[])
{
	CommandLine cmd;
	std::string name;////////
	std::string num;
	float f;
//std::string nameNumF;
	cmd.AddValue ("name", "my name 123123", name);
	cmd.AddValue ("num", "my num", num);
	cmd.AddValue ("f", "my f", f);
//cmd.AddValue ("nameNumF", "my name 123123", nameNumF);
	cmd.Parse(argc,argv);

	printHello(name,f);
	printHello(num,f);
	
//printHello(nameNumF);
	//std::cout<<"hello commit"<<std::endl;

	Simulator::Stop(Seconds(5));
	Simulator::Run ();
	Simulator::Destroy ();
}  




/*
int main()
{
        std::string name;
	std::string number;
	int f;
	int i=0;
	std::cin>>name;
	std::cin>>number;
	std::cin>>f;
 	for(;i<5;i++)
	{
	  std::cout<<"my name"<<name<<std::endl;
	  std::cout<<"my number"<<number<<std::endl;
	  std::cout<<"output f"<<f<<std::endl;
	}
	
   	return 0;
}*/
