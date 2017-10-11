#include "Arduino.h"

extern int LED ;
extern int in1 ;
extern int in2 ;
extern int in3 ;
extern int in4 ;
extern int ENA ;
extern int ENB ;

void _mForward() ;
void _mBack() ;
void _mLeft(int ABS) ;
void _mRight(int ABS) ;
void _mStop() ;
void stateChange(int state) ;
