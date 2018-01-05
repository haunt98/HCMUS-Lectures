#ifndef _BIKE_H
#define _BIKE_H

class Bike
{
      private:
	char *m_brand; // hiệu xe
      public:
	Bike(char *brand);
	~Bike();
	virtual void move(int t1);
};

class EBike : public Bike
{
      public:
	EBike(char *brand) : Bike(brand)
	{
	}
	void move(int t2);
};

void display(Bike &a, EBike &b);

#endif