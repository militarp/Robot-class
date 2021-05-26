#include "project.h"


Robot::Robot() //default constructors
{

}

Robot::Robot(int xL, int yL, bool cargobed, char load) //constructors with parameter
{
    this->xLocation = xL;
    this->yLocation = yL;
    this->cargobed = cargobed;
    this->load = load;
}

int Robot::getX() const //obtains x location
{
    return xLocation;
}

int Robot::getY() const //obtains y location
{
    return yLocation;
}

bool Robot::getCargo() const //returns if there is cargo; true or false
{
    return cargobed;
}

char Robot::getLoad() const //obtains load
{
    return load; 
}
void Robot::setX(int xLocation) //sets x location of robot
{
    this->xLocation = xLocation;
}

void Robot::setY(int yLocation) //sets y location of robot
{
    this->yLocation = yLocation;
}

void Robot::setCargo(bool cargobed) //sets if cargo is true or false
{
    this->cargobed = cargobed;
}

void Robot::setLoad(char load) //sets previous load into new load
{
    this->load = load;
}

bool Robot::MoveTo(int x, int y, char Board[10][10]) //moves to specified location on board
{
    if (x >= 0 && x < 10 && y >= 0 && y < 10)
    {
        int i = xLocation;
        int j = yLocation;
        for (i; i != x; )
        {
            if (x < i)
            {
                i--;
            }
            if (x > i)
            {
                i++;
            }
            for (j; j != y; )
            {
                if (y < j)
                {
                    j--;
                }
                if (y > j)
                {
                    j++;
                }
            }
        }
        xLocation = i;
        yLocation = j;
        return true;
    }
    return false;
}

bool Robot::pickUp(int x, int y, char Board[10][10]) //picks up load on given location
{
    if (Board[x][y] != '.' && cargobed == false && load == '.')
    {
        MoveTo(x, y, Board);
        load = Board[x][y];
        cargobed = true;
        Board[x][y] = '.';
        return true;
    }
    return false;
}

bool Robot::dropOff(int x, int y, char Board[10][10]) //drops off load on given location
{
    if (Board[x][y] == '.' && cargobed == true && load != '.')
    {
        MoveTo(x, y, Board);
        Board[x][y] = load;
        cargobed = false;
        load = '.';
    }
    return false;
}

Robot::~Robot() //destructor
{

}