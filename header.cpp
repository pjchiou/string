#include "header.h"

cStr::cStr()
{
  cout << "[" << this << "] call constructor" << endl;

  iLength=0;
  buff=NULL;
}

cStr::cStr(const char *s)
{
  cout << "[" << this << "] call const char*s constructor";

  int i=0;
  iLength=0;
  while( s && s[++iLength]!='\0' );
  buff = new char[iLength+1];

  for(i=0;i<iLength;i++)
    buff[i] = s[i];
  buff[i]='\0';

  cout << ", value:" << buff << endl;
}

cStr::cStr(const cStr& s)
{
  cout << "[" << this << "] call const cStr& constructor";

  int i=0;
  iLength=0;
  while( s.buff && s.buff[++iLength]!='\0');
  buff = new char[iLength+1];

  for(i=0;i<iLength;i++)
    buff[i] = s.buff[i];
  buff[i]='\0';

  cout << ", value:" << buff << endl;
}

cStr::~cStr()
{
  cout << '[' << this << "] call destructor, value:" << buff << endl;

  iLength=0;
  delete [] buff;
  buff = NULL;
}

ostream& operator << (ostream& os,const cStr& s)
{
  os << s.buff;
  return(os);
}

void cStr::operator=(const char *s)
{
  int i=0;
  iLength=0;

  while(s && s[++iLength]!='\0');

  if(buff) delete [] buff;
  buff = new char[iLength+1];

  for(i=0;i<iLength;i++)
    buff[i] = s[i];
  buff[i]= '\0';
}

void cStr::operator=(const cStr& s)
{
  int i=0;
  iLength=0;

  while( s.buff && s.buff[++iLength]!='\0');

  if(buff) delete [] buff;
  buff = new char[iLength+1];

  for(i=0;i<iLength;i++)
    buff[i] = s.buff[i];
  buff[i]= '\0';
}

cStr cStr::operator+(const char *s)
{
  int len2=0;
  cStr temp;

  while( s && s[++len2]!='\0' );
  temp.buff = new char[iLength+len2+1];

  for(int i=0;i<iLength;i++)
    temp.buff[i] = buff[i];
  for(int i=0;i<len2;i++)
    temp.buff[iLength+i] = s[i];
  temp.buff[iLength+len2]='\0';
  temp.iLength = iLength+len2;

  return(temp);
}

cStr cStr::operator+(const cStr& s)
{
  cStr temp;
  temp.buff = new char[iLength+s.iLength+1];

  for(int i=0;i<iLength;i++)
    temp.buff[i] = buff[i];
  for(int i=0;i<s.iLength;i++)
    temp.buff[iLength+i] = s.buff[i];
  temp.buff[iLength+s.iLength]='\0';
  temp.iLength = iLength+s.iLength;

  return(temp);
}
