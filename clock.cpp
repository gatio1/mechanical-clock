#include "fstrl.h"
#include<ctime>
using namespace std;
int main()
{
  time_t rawtime;

  time (&rawtime);
  printf ("The current local time is: %s", ctime (&rawtime));

  return 0;
}

