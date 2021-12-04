# include <stdio.h>
# include <stdlib.h>
# include <string.h>


void passwdValidate(int* total,const char** passwd);

int main() {

	// Boolean used for verifying safety of the password
	_Bool safe = 0;

	// String used to store password
	char *passwd = malloc(sizeof(char));
	
	while (!safe)
	{
		// Score used to determine the safety of the password
		int total = 0;

		// Demanding the user the user to enter a password
		printf("Enter password: ");
		fgets(passwd, 255, stdin);

		// Passwords with lesser than 10 characters
		if (strlen(passwd) < 10)
		{
			total = (10 - strlen(passwd)) * 5;
			passwdValidate(&total, &passwd);
			total = total * -1;

			if (total < -30)
			{
				printf("Score: %d \n", total);
				printf("Password is unsafe! Please reset.\n");
			}

			else
			{
				printf("Score: %d \n", total);
				printf("The password is safe.");
				safe = 1;
			}
		}

		// Passwords with more than 10 characters
		else
		{
			passwdValidate(&total, &passwd);
			total = total * -1;

			if (total < -30)
			{
				printf("Score: %d \n", total);
				printf("Password is unsafe! Please reset.\n");
			}

			else
			{
				printf("Score: %d \n", total);
				printf("The password is safe.");
				safe = 1;
			}
		}

	}
	free(passwd);
	return 0;
}

// Check for Capital, lowercase, numbers, and consecutive
void passwdValidate(int* total,const char** passwd) {
	_Bool cap = 1, low = 1, num = 1,con=0;             // we want capital letters, lowercase letters, numbers, but no consecutive numbers
	int i = 0;
	char c ="",d="",e="";
	char buff[255] ="";
	strcpy(buff, *passwd);
	c = buff[i], d = buff[i + 1], e = buff[i + 2];
	while (c != '\0'&&!(!cap&&!low&&!num&&con))
	{

		if (c >= 'A' && c <= 'Z')                      // cap is false if there exists a capital letter
			cap = 0;
		if (c >= 'a' && c <= 'z')                      // num if false if there exists a number
			low = 0;
		if (c >= '0' && c <= '9')                      // num is false, if there exists a number
			num = 0;
		if (c == d - 1 && e == d + 1)                  // con is true, if exists three consecutive characters
			con = 1;
		i++;
		c = buff[i], d = buff[i + 1], e = buff[i + 2];
	}
	if (cap)
		*total = *total + 20;
	if (low)
		*total = *total + 20;
	if (num)
		*total = *total + 20;
	if (con)
		*total = *total + 20;
}