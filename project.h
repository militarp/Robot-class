#pragma once
#include <iostream>
using namespace std;

class Robot
{

private:  //data fields
	int xLocation; 
	int yLocation;
	bool cargobed;
	char load;

public: //constructors
	Robot();
	Robot(int x, int y, bool cargo, char load);
	int getX() const;
	int getY() const;
	bool getCargo() const;
	char getLoad() const;
	void setX(int xLocation);
	void setY(int yLocation);
	void setCargo(bool cargobed);
	void setLoad(char load);
	bool MoveTo(int x, int y, char Board[10][10]);
	bool pickUp(int x, int y, char Board[10][10]);
	bool dropOff(int x, int y, char Board[10][10]);
	friend ostream& operator << (ostream& os, const Robot& Obj);
	~Robot();

};
