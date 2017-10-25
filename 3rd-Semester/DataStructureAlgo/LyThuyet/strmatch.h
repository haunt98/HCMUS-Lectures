#ifndef STRMATCH_H
#define STRMATCH_H

class dfaTable
{
private:
    int **m_table;
    int m_state;
    int m_alphabet;
    dfaTable();
    dfaTable(const dfaTable &);
    dfaTable &operator=(const dfaTable &);

public:
    dfaTable(const char *P);
    ~dfaTable();

    int *operator[](int i);
};

int naiveMatch(const char *T, const char *P);
int dfaMatch(const char *T, const char *P);
int kmpMatch(const char *T, const char *P);

#endif
