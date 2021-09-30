#include <iostream>
#include "Class/LinkList.h"
#include <iomanip>

#define  Cout std::cout
#define  Cin std::cin

void Input(int& peopleNum, int& initPos, int& deadNum, int& aliveNum);

int main()
{

	Cout << "现有N人围成一圈，从第S个人开始报数，报M的人出局，再由下一个人开始报数，如此循环，直到剩下K个人为止\n";
	int peopleNum = 0, initPos = 0, deadNum = 0, aliveNum = 0;

	while (true)
	{
		Input(peopleNum, initPos, deadNum, aliveNum);
		const int circleNum = peopleNum - aliveNum;

		Cout << "\n";

		LinkList linkList;
		linkList.initList(peopleNum);//so everyone has a position

		int count = 1;//begin with the number one

		Passenger temp;//store the element that is removed temporarily
		Passenger* current = linkList.Locate(initPos);

		for (int i = 0; i < circleNum; )
		{
			if (current == linkList.getHead()) {
				current = current->m_next;
			}
			if (count == deadNum)
			{
				Passenger* keepData = current->m_next;
				linkList.Remove(current, temp);

				Cout << "第" << std::setw(3) << std::setfill(' ') << 
					std::setiosflags(std::ios::left) << i + 1 
					<< "个死者位置是:" << std::setw(4) << temp.m_pos << std::endl;

				i++;//when a people die, you can actually go on the next circle
				count = 1;//start with number one
				current = keepData;

				continue;
			}
			current = current->m_next;
			if (current == linkList.getHead()) {
				current = current->m_next;
			}
			count++;
		}
		Cout << "最后剩下" << aliveNum << "人\n";
		linkList.Output();

		Cout << "是否退出？（Y/y)--Yes, (N/n)--No\n";
		char ifExit;
		Cin >> ifExit;
		if (ifExit == 'y' || ifExit == 'Y')
		{
			break;
		}
	}

}

void Input(int& peopleNum, int& initPos, int& deadNum, int& aliveNum)
{
	Cout << "请输入生死游戏的总人数N：";
	Cin >> peopleNum;
	while (Cin.fail() || peopleNum < 1)
	{
		Cout << "输入错误，请重新输入！\n";
		Cin.clear();
		Cin.ignore(65535, '\n');
		Cin >> peopleNum;
	}

	Cout << "请输入游戏开始的位置S：  ";
	Cin >> initPos;
	while (Cin.fail() || initPos < 1 || initPos > peopleNum)
	{
		Cout << "输入错误，请重新输入！\n";
		Cin.clear();
		Cin.ignore(65535, '\n');
		Cin >> initPos;
	}

	Cout << "请输入死亡数字M：        ";
	Cin >> deadNum;
	while (Cin.fail() || deadNum < 1)
	{
		Cout << "输入错误，请重新输入！\n";
		Cin.clear();
		Cin.ignore(65535, '\n');
		Cin >> deadNum;
	}

	Cout << "请输入剩余的生者人数K：  ";
	Cin >> aliveNum;
	while (Cin.fail() || aliveNum < 1 || aliveNum >= peopleNum)
	{
		Cout << "输入错误，请重新输入！\n";
		Cin.clear();
		Cin.ignore(65535, '\n');
		Cin >> aliveNum;
	}
}
