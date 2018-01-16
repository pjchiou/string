#ifndef __header_h__
#define __header_h__

#include <iostream>
#include <cstdlib>

using namespace std;

class cStr
{
private:
  int iLength;
  char *s;
public:
  cStr();
  cStr(char *s);
  cStr(const cStr& s);
  ~cStr();
};

#endif
