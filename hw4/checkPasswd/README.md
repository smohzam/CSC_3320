# Check Password

Author: Sriram Mohan

How to execute checkPasswd:
  1. Compile the program and type ./checkPasswd on the terminal (if required, enable w/ chmod a+x).
  2. The program asks you to enter passwords, and will evaluate their safety on a couple of criteria and a score.
   2.1 Initially, your score is zero, and from thereon it reduces based on the following:
     \•	Passwords with lesser than 10 characters lose 5 points per missing character. 
     \•	The below points are applicable to those with a score greater than -30:
      \ o	Passwords without lower case letters lose 20 points
       o	Passwords without upper case letters lose 20 points       
       o	Passwords without numbers lose 20 points
       o	Passwords with more than 2 consecutive characters lose 20 points   
  3. Any password with score lesser than -30 is considered unsafe.
  4. Any password with score greater than that is considered safe.
  5. The program continues to run until you have entered a safe password, after which it terminates.
     
