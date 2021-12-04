#!/bin/bash

#Name of program: helpme
#Name of programmer: Sriram Mohan
#email: smohan6@student.gsu.edu

echo type command
read v
if [ "$v" = 'cat' ]
 then
  sed -n '1,76p;77q' mandatabase.txt 
elif [ "$v" = 'pwd' ]
 then
  sed -n '77,132p;133q' mandatabase.txt
elif [ "$v" = 'rm' ]
 then
 sed -n '134,245p;246q' mandatabase.txt
elif [ "$v" = 'mkdir' ]
 then
 sed -n '246,301p;302q' mandatabase.txt
elif [ "$v" = 'mv' ]
 then
 sed -n '302,399p;400q' mandatabase.txt
elif [ "$v" = 'chmod' ]
 then
 sed -n '400,537p;538q' mandatabase.txt
elif [ "$v" = 'chgrp' ]
 then
 sed -n '538,620p;621q' mandatabase.txt
elif [ "$v" = 'size' ]
 then
 sed -n '538,732p;733q' mandatabase.txt
elif [ "$v" = 'echo' ]
 then
 sed -n '734,804p;805q' mandatabase.txt
elif [ "$v" = 'open' ]
 then
 sed -n '805,879p;880q' mandatabase.txt
else
  echo sorry i cannot help you.
fi
