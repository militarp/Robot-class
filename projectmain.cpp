#include <iostream>
#include "project.h"
using namespace std;

char Board[10][10];

ostream& operator<<(ostream& os, const Robot& Obj) //friend function that can be given special grant access to private members
{
   os << "ROBOT: (" << Obj.getX() << ", " << Obj.getY() << ") :" << Obj.getLoad() << endl;
   return os;
}

void print2D(char Board[10][10]) //prints grid
{
   for (int i = 0; i < 10; i++)
   {
       for (int j = 0; j < 10; j++)
       {
           cout << Board[i][j] << " ";
       }
       cout << endl;
   }
   cout << endl << endl;
}

void initialize2D(char Board[10][10]) //initial place of loads
{
   for (int i = 0; i < 10; i++)
   {
       for (int j = 0; j < 10; j++)
       {
           Board[i][j] = '.';
       }
   }
   Board[3][8] = 'B';
   Board[2][6] = 'C';
}

void clear(char Board[10][10]) //deletes robot if there is no load
{
   for (int i = 0; i < 10; i++)
   {
       for (int j = 0; j < 10; j++)
       {
           if (Board[i][j] != '.')
           {
               Robot R(0, 0, false, '.');
               R.pickUp(i, j, Board);
           }
       }
   }
}

bool isClear(char Board[10][10]) //checks if there is load on the grid and summons robot
{
   for (int i = 0; i < 10; i++)
   {
       for (int j = 0; j < 10; j++)
       {
           if (Board[i][j] != '.')
           {
               return false;          
           }
       }
   }
   return true;
}

int main()
{
   initialize2D(Board);
   print2D(Board);
   Robot R1(0, 0, false, '.');
   Robot R2(1, 1, false, '.');
   cout << R1;
   cout << R2;
   R1.pickUp(3, 8, Board);
   R1.dropOff(9, 9, Board);
   print2D(Board);
   R2.pickUp(2, 6, Board);
   R2.dropOff(0, 0, Board);
   print2D(Board);
   while (!isClear(Board))
   {
       clear(Board);
   }
   print2D(Board);

   return 0;
}