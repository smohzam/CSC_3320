#!/bin/bash

while [ "$m" != 'Quit' ]
do 
echo Menu: Add, Delete, Search, Edit, Quit
read m
if [ "$m" = 'Add' ]
 then
  echo Enter Name
  read Name
  echo Enter Address
  read Address
  echo Enter Phone Number
  read Pno
  echo $Name ", " $Address ", " $Pno  >> phoneBook.txt

elif [ "$m" = 'Delete' ]
 then
  echo Enter Name/Address/Pno
  read del
  awk  '!/'$del'/'  phoneBook.txt > tempBook.txt
  mv tempBook.txt  phoneBook.txt

elif [ "$m" = 'Search' ]
 then
  echo Enter Name/Address/Pno
  read s
  awk -F ,  '{print $1  "," ,$2 "," ,$3}' phoneBook.txt | grep $s

elif [ "$m" = 'Edit' ]
 then
  echo Enter Name/Address/Pno
  read e 
  echo Enter edit
  read ed
  sed 's/'$e'/'$ed'/'  phoneBook.txt > tempBook.txt
  mv tempBook.txt phoneBook.txt

fi
done
