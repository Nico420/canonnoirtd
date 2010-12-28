// alea.cpp

#include "alea.h"

#include <iostream>
#include <time.h>
#include <math.h>

// NOTE : DEBUT CODE pour palier au manque de gettimeofday
// Copié du net
#include <windows.h>


#if defined(_MSC_VER) || defined(_MSC_EXTENSIONS)
  #define DELTA_EPOCH_IN_MICROSECS  11644473600000000Ui64
#else
  #define DELTA_EPOCH_IN_MICROSECS  11644473600000000ULL
#endif
 
struct timezone 
{
  int  tz_minuteswest; /* minutes W of Greenwich */
  int  tz_dsttime;     /* type of dst correction */
};
 
int gettimeofday(struct timeval *tv, struct timezone *tz)
{
  FILETIME ft;
  unsigned __int64 tmpres = 0;
  static int tzflag;
 
  if (NULL != tv)
  {
    GetSystemTimeAsFileTime(&ft);
 
    tmpres |= ft.dwHighDateTime;
    tmpres <<= 32;
    tmpres |= ft.dwLowDateTime;
 
    /*converting file time to unix epoch*/
    tmpres -= DELTA_EPOCH_IN_MICROSECS; 
    tmpres /= 10;  /*convert into microseconds*/
    tv->tv_sec = (long)(tmpres / 1000000UL);
    tv->tv_usec = (long)(tmpres % 1000000UL);
  }
 
  if (NULL != tz)
  {
    if (!tzflag)
    {
      _tzset();
      tzflag++;
    }
    tz->tz_minuteswest = _timezone / 60;
    tz->tz_dsttime = _daylight;
  }
 
  return 0;
}

// NOTE : FIN CODE pour palier au manque de gettimeofday

int hasard(int n)
{
  struct timeval tp;
  struct timezone tzp;
  double x;
  int q, y;
  long r;

  gettimeofday(&tp,&tzp);
  r = tp.tv_usec;
  x = (double) r/n;
  q = (int) floor(x);
  y = (int) r - n*q + 1;
  //cout << "Nombre au hasard entre 1 et " << n << ": " << d << "\n";
  return y;
}


int Alea::engendrer(int n) {
  int a = hasard(n);
  // cout << "n = " << n << " a = " << a << endl;
  return a;
}
