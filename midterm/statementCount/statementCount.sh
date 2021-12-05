#!/bin/bash

# Name of program: statementCount
# Name of programmer: Sriram Mohan
# email: smohan6@student.gsu.edu

echo Number of sentences:
grep -o '[\"\.]$\|[\"\.][\[\s]' myexamfile.txt | wc -l

echo Number of words \| characters:
grep -o '^[A-Z].*[\.\"\?]$\|\s[A-Z].*[\.\?\"]\[' myexamfile.txt | awk '{print $0}' | awk '{print NF, " |", length}'
 
