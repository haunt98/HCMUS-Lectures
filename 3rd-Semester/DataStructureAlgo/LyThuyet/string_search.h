#ifndef STRING_SEARCH_H
#define STRING_SEARCH_H

// T: Text, P: Patern
// Follow lecture
int bruteForce(const char *T, const char *P);
int strSearchDFA(const char *T, const char *P);
int strSearchKMP(const char *T, const char *P);

// My mod with the help of Google
int strSearchDFABrute(const char *T, const char *P); // On Geek for Geek site

#endif