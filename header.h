#ifndef __header_h__
#define __header_h__

#include <iostream>
#include <cstdlib>

using namespace std;

class cStr
{
private:
  int iLength;
  char *buff;
public:
  cStr();
  cStr(const char *s);
  cStr(const cStr& s);  
  ~cStr();
  int Length(){return(iLength);}
  char& operator[](int i){ return(buff[i]); }
  friend ostream& operator <<(ostream& os,const cStr& s);
  void operator=(const char *s);
  void operator=(const cStr& s);
  cStr operator +(const char *s);
  cStr operator +(const cStr& s);
  friend cStr operator +(const char *s,const cStr& s2);
};

#endif
