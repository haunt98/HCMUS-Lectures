#ifndef ANIMAL_H
#define ANIMAL_H

class Animal
{
public:
    virtual int speed() = 0;
};

class Bao : public Animal
{
public:
    int speed();
};

class LinhDuong : public Animal
{
public:
    int speed();
};

class SuTu : public Animal
{
public:
    int speed();
};

class Cho : public Animal
{
public:
    int speed();
};
class Nguoi : public Animal
{
public:
    int speed();
};

class Ngua : public Animal
{
public:
    int speed();
};

int soSanh(Animal *a1, Animal *a2); // -1 0 1

#endif
