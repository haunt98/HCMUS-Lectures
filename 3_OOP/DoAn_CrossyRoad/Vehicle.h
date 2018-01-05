#ifndef VEHICLE_H
#define VEHICLE_H

#include "Board.h"
#include "ToaDo.h"

#define SIZE_TRUCK 13
#define SIZE_CAR 9

class Vehicle
{
      protected:
	ToaDo m_root;
	ToaDo m_prev;

      public:
	Vehicle();
	Vehicle(const ToaDo &);
	Vehicle(const Vehicle &);
	virtual ToaDo getRoot();
	virtual ToaDo getPrev();
	virtual void setRoot(const ToaDo &);
	virtual void setPrev(const ToaDo &);
	virtual void Reset();
	virtual void Draw(int ch) = 0;
	virtual void MoveLeft() = 0;
	virtual bool isHit(const ToaDo &) = 0;
	virtual Vehicle &operator=(const Vehicle &);
};

class Truck : public Vehicle
{
      private:
	ToaDo m_rpos[SIZE_TRUCK];
	void setrpos();

      public:
	Truck();
	Truck(const ToaDo &);
	Truck(const Truck &);
	void Draw(int ch);
	void MoveLeft();
	bool isHit(const ToaDo &);
	Truck &operator=(const Truck &);
};

class Car : public Vehicle
{
      private:
	ToaDo m_rpos[SIZE_CAR];
	void setrpos();

      public:
	Car();
	Car(const ToaDo &);
	Car(const Car &);
	void Draw(int ch);
	void MoveLeft();
	bool isHit(const ToaDo &);
	Car &operator=(const Car &);
};

#endif