#pragma once
class Passenger
{
public:
	int		   m_pos;
	Passenger* m_next;

public:
	void setPos(int pos) { m_pos = pos; }
	Passenger() { ; }
	Passenger(int pos);
};


class LinkList
{
public:
	LinkList();
	~LinkList() {
		makeEmpty();
		delete m_head;
	}

	void makeEmpty();
	int  Length()const;

	void initList(int number);
	void Output();

	Passenger* Locate(int i);
	Passenger* getHead()const { return m_head; }
	bool Remove(Passenger* target, Passenger& x);//the x is the element that is removed
private:
	Passenger* m_head;
};

