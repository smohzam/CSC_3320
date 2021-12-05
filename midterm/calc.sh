#!/bin/bash

# Name of Program: Calculator
# Name of Programmer: Sriram Mohan
# email: smohan6@student.gsu.edu

x=0
echo type number "(C to cancel)"
read a
 if [ "$a" != 'C' ]
  then
  echo type operand: +,-,x,/,%,=,C
  read o
if [ "$o" == 'C' ]
 then
  x=0
elif [ "$o" == '=' ]
 then
  x=$a
else
  echo type number "(C to cancel)"
  read b
if [ "$b" != 'C' ]
 then
if [ "$o" = '+' ]
 then
  x=` expr $a \+ $b `
elif [ "$o" = '-' ]
 then
  x=` expr $a - $b `
elif [ "$o" = 'x' ]
 then
 x=` expr $a \* $b `
elif [ "$o" = '/' ]
 then
 x=` expr $a / $b `
elif [ "$o" = '%' ]
 then
 x=` expr $a % $b `
else
 x="Invalid"
 fi
fi
fi
fi
echo Result: $x
