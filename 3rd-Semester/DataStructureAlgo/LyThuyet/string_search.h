#ifndef STRING_SEARCH_H
#define STRING_SEARCH_H

// T: Text, P: Patern
// Follow lecture
int bruteForce(const char *T, const char *P);
int strSearchDFA(const char *T, const char *P);
int strSearchKMP(const char *T, const char *P);

#endif