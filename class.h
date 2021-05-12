#pragma once
#ifdef
#define

class Robot
{

private:
	int xLocation;
	int yLocation;
	bool cargoBed;
	char load;

public:
	Robot();
	Robot(int x, int y, bool cargo, void load);
	int getX();
	int getY();
	bool getCargo();
	void getLoad();
	int setX();
	int setY();
	bool setCargo();
	void setLoad();

	void cargoNo();
	void cargoYes()
		bool MoveTo(int lx, int ly);
	bool pickUp(int lx, int ly);
	bool dropOff(int lx, ly);



};
