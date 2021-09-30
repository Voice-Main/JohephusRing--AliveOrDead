#include <iostream>
#include "Class/LinkList.h"
#include <iomanip>

#define  Cout std::cout
#define  Cin std::cin

void Input(int& peopleNum, int& initPos, int& deadNum, int& aliveNum);

int main()
{

	Cout << "����N��Χ��һȦ���ӵ�S���˿�ʼ��������M���˳��֣�������һ���˿�ʼ���������ѭ����ֱ��ʣ��K����Ϊֹ\n";
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

				Cout << "��" << std::setw(3) << std::setfill(' ') << 
					std::setiosflags(std::ios::left) << i + 1 
					<< "������λ����:" << std::setw(4) << temp.m_pos << std::endl;

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
		Cout << "���ʣ��" << aliveNum << "��\n";
		linkList.Output();

		Cout << "�Ƿ��˳�����Y/y)--Yes, (N/n)--No\n";
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
	Cout << "������������Ϸ��������N��";
	Cin >> peopleNum;
	while (Cin.fail() || peopleNum < 1)
	{
		Cout << "����������������룡\n";
		Cin.clear();
		Cin.ignore(65535, '\n');
		Cin >> peopleNum;
	}

	Cout << "��������Ϸ��ʼ��λ��S��  ";
	Cin >> initPos;
	while (Cin.fail() || initPos < 1 || initPos > peopleNum)
	{
		Cout << "����������������룡\n";
		Cin.clear();
		Cin.ignore(65535, '\n');
		Cin >> initPos;
	}

	Cout << "��������������M��        ";
	Cin >> deadNum;
	while (Cin.fail() || deadNum < 1)
	{
		Cout << "����������������룡\n";
		Cin.clear();
		Cin.ignore(65535, '\n');
		Cin >> deadNum;
	}

	Cout << "������ʣ�����������K��  ";
	Cin >> aliveNum;
	while (Cin.fail() || aliveNum < 1 || aliveNum >= peopleNum)
	{
		Cout << "����������������룡\n";
		Cin.clear();
		Cin.ignore(65535, '\n');
		Cin >> aliveNum;
	}
}
