#pragma once
class Items
{
public:
	//! Constructor
	Items();
	//! Destructor
	~Items();

	int getX() { return x; }
	int setX(int newX) {return x = newX;}

	int getY() { return y; }
	int setY(int newY) { return y = newY; }

private:
	int x; int y;
};

