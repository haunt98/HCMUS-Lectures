#include "Vehicle.h"

// Vehicle
Vehicle::Vehicle() : m_root(), m_prev()
{
}

Vehicle::Vehicle(const ToaDo &td) : m_root(td), m_prev(td)
{
}

Vehicle::Vehicle(const Vehicle &ve) : m_root(ve.m_root), m_prev(ve.m_prev)
{
}

ToaDo Vehicle::getRoot()
{
	return m_root;
}

ToaDo Vehicle::getPrev()
{
	return m_prev;
}

void Vehicle::setRoot(const ToaDo &td)
{
	m_root = td;
}

void Vehicle::setPrev(const ToaDo &td)
{
	m_prev = td;
}

void Vehicle::Reset()
{
	m_root.X = WIDTH_BOARD - 2; // The most right
}

Vehicle &Vehicle::operator=(const Vehicle &ve)
{
	m_root = ve.m_root;
	m_prev = ve.m_prev;
	return *this;
}

// Truck
// TTTTTTT
// TTT TTT
void Truck::setrpos()
{
	m_rpos[0] = ToaDo(0, 0);
	m_rpos[1] = ToaDo(0, 1);
	m_rpos[2] = ToaDo(-1, 1);
	m_rpos[3] = ToaDo(-2, 1);
	m_rpos[4] = ToaDo(-1, 0);
	m_rpos[5] = ToaDo(-2, 0);
	m_rpos[6] = ToaDo(-3, 0);
	m_rpos[7] = ToaDo(-4, 0);
	m_rpos[8] = ToaDo(-5, 0);
	m_rpos[9] = ToaDo(-6, 0);
	m_rpos[10] = ToaDo(-4, 1);
	m_rpos[11] = ToaDo(-5, 1);
	m_rpos[12] = ToaDo(-6, 1);
}

Truck::Truck() : Vehicle()
{
	setrpos();
}

Truck::Truck(const ToaDo &td) : Vehicle(td)
{
	setrpos();
}

Truck::Truck(const Truck &tr) : Vehicle(tr)
{
	setrpos();
}

void Truck::Draw(int ch)
{
	if (m_root == m_prev) {
		for (int i = 0; i < SIZE_TRUCK; ++i) {
			(m_root + m_rpos[i]).Draw(ch);
		}
	} else {
		ToaDo old_pos[SIZE_TRUCK];
		ToaDo new_pos[SIZE_TRUCK];
		for (int i = 0; i < SIZE_TRUCK; ++i) {
			old_pos[i] = m_prev + m_rpos[i];
			new_pos[i] = m_root + m_rpos[i];
		}
		bool isDup;
		// Only remove not duplicate
		for (int i = 0; i < SIZE_TRUCK; ++i) {
			isDup = false;
			ToaDo old_temp = old_pos[i];
			for (int j = 0; j < SIZE_TRUCK; ++j) {
				if (old_temp == new_pos[j]) {
					isDup = true;
					break;
				}
			}
			if (!isDup) {
				old_temp.Draw(' ');
			}
		}
		// Only write what new
		for (int i = 0; i < SIZE_TRUCK; ++i) {
			isDup = false;
			ToaDo new_temp = new_pos[i];
			for (int j = 0; j < SIZE_TRUCK; ++j) {
				if (new_temp == old_pos[i]) {
					isDup = true;
					break;
				}
			}
			if (!isDup) {
				new_temp.Draw(ch);
			}
		}
		m_prev = m_root;
	}
}

void Truck::MoveLeft()
{
	ToaDo endrpos = m_root + m_rpos[SIZE_TRUCK - 1];
	if (endrpos.X > 2) {
		m_root = m_root.Left();
	} else {
		Reset();
	}
}

bool Truck::isHit(const ToaDo &td)
{
	for (int i = 0; i < SIZE_TRUCK; ++i) {
		if (m_root + m_rpos[i] == td) {
			return true;
		}
	}
	return false;
}

Truck &Truck::operator=(const Truck &tr)
{
	Vehicle::operator=(tr);
	for (int i = 0; i < SIZE_TRUCK; ++i) {
		m_rpos[i] = tr.m_rpos[i];
	}
	return *this;
}

// Car
// CCCCC
// CC CC

void Car::setrpos()
{
	m_rpos[0] = ToaDo(0, 0);
	m_rpos[1] = ToaDo(0, 1);
	m_rpos[2] = ToaDo(-1, 1);
	m_rpos[3] = ToaDo(-1, 0);
	m_rpos[4] = ToaDo(-2, 0);
	m_rpos[5] = ToaDo(-3, 0);
	m_rpos[6] = ToaDo(-4, 0);
	m_rpos[7] = ToaDo(-3, 1);
	m_rpos[8] = ToaDo(-4, 1);
}

Car::Car() : Vehicle()
{
	setrpos();
}

Car::Car(const ToaDo &td) : Vehicle(td)
{
	setrpos();
}

Car::Car(const Car &ca) : Vehicle(ca)
{
	setrpos();
}

void Car::Draw(int ch)
{
	if (m_root == m_prev) {
		for (int i = 0; i < SIZE_CAR; ++i) {
			(m_root + m_rpos[i]).Draw(ch);
		}
	} else {
		ToaDo old_pos[SIZE_CAR];
		ToaDo new_pos[SIZE_CAR];
		for (int i = 0; i < SIZE_CAR; ++i) {
			old_pos[i] = m_prev + m_rpos[i];
			new_pos[i] = m_root + m_rpos[i];
		}
		bool isDup;
		// Only remove not duplicate
		for (int i = 0; i < SIZE_CAR; ++i) {
			isDup = false;
			ToaDo old_temp = old_pos[i];
			for (int j = 0; j < SIZE_CAR; ++j) {
				if (old_temp == new_pos[j]) {
					isDup = true;
					break;
				}
			}
			if (!isDup) {
				old_temp.Draw(' ');
			}
		}
		// Only write what new
		for (int i = 0; i < SIZE_CAR; ++i) {
			isDup = false;
			ToaDo new_temp = new_pos[i];
			for (int j = 0; j < SIZE_CAR; ++j) {
				if (new_temp == old_pos[i]) {
					isDup = true;
					break;
				}
			}
			if (!isDup) {
				new_temp.Draw(ch);
			}
		}
		m_prev = m_root;
	}
}

void Car::MoveLeft()
{
	ToaDo endrpos = m_root + m_rpos[SIZE_CAR - 1];
	if (endrpos.X > 2) {
		m_root = m_root.Left();
	} else {
		Reset();
	}
}

bool Car::isHit(const ToaDo &td)
{
	for (int i = 0; i < SIZE_CAR; ++i) {
		if (m_root + m_rpos[i] == td) {
			return true;
		}
	}
	return false;
}

Car &Car::operator=(const Car &ca)
{
	Vehicle::operator=(ca);
	for (int i = 0; i < SIZE_CAR; ++i) {
		m_rpos[i] = ca.m_rpos[i];
	}
	return *this;
}