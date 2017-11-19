#ifndef _LOGGER_H
#define _LOGGER_H

class Logger
{
protected:
    Logger *m_next;

public:
    Logger(Logger *next) : m_next(next) {}
};

#endif