#include <iostream>

const int deadTag = 1;
//const int peopleNum = 30;
//const int deadNum = 9;
//const int circleNum = 15;
#include "Class/LinkList.h"

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
				Cout << "第" << i + 1 << "个死者位置是：        " << temp.m_pos << std::endl;
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

		Cout << "是否退出？（Y/y)--Yes\n";
		char ifExit;
		Cin >> ifExit;
		if (ifExit == 'y' || ifExit == 'Y')
		{
			break;
		}
	}
	

	//2.0
	//for (int i = 0; i < circleNum; )
	//{
	//	if (pos > MaxPeopleNum)
	//	{
	//		pos = 1;//return to the first people
	//	}
	//	if (count == deadNum )
	//	{

	//		linkList.Remove(pos, temp);//you removed many people, so the length of the linked list has been changed, however, the pos is not been changed, so the error occurred
	//		std::cout << "第" << i + 1 << "个死者位置是：        " << temp.m_pos << std::endl;
	//		i++;//when a people die, you can actually go on the next circle
	//		count = 1;//start with number one
	//		pos++;//go to the next people
	//		MaxPeopleNum--;

	//		if (!MaxPeopleNum) {
	//			Cout << "ERROR: maxPeopleNum is wrong and its value is " << MaxPeopleNum << '\n';
	//		}
	//		continue;
	//	}
	//	count++;
	//	pos++;
	//}













	//1.0
	//int people[peopleNum+1] = {};//initialize the array with zero
	//int pos = 1;//begin with the first people
	//int count = 1;//begin with the number one

 // 	for (int i = 0; i < circleNum; ) 
	//{
	//	if (pos > peopleNum)
	//	{
	//		pos = 1;//return to the first people
	//	}
	//	while (people[pos] == deadTag)
	//		//you must use a circle to keep it normal when people are dead continuously
	//	{
	//		pos++;//ignore the dead people
	//		if (pos > peopleNum)
	//		{
	//			pos = 1;
	//		}
	//	}
	//	if (count == deadNum && people[pos] != deadTag)
	//	{
	//		people[pos] = deadTag;
	//		std::cout << "第" << i + 1 << "个死者位置		" << pos << std::endl;
	//		i++;//when a people die, you can actually go on the next circle
	//		count = 1;//start with number one
	//		pos++;//go to the next people

	//		continue;
	//	}
	//	count++;
	//	pos++;		
	//}
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
