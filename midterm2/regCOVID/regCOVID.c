# include <stdio.h>
# include <stdlib.h>
# include <string.h>

// The database for registration
typedef struct { char fname[255]; char lname[255]; char DOB[255]; int dNo; char DOPd[255]; char TOV[255]; char ZIP[255]; } database;

_Bool valReg(char** in);

_Bool valQuit(char** in);

void reg(database* db, int n);

void generate_code(database* db, int n);

char retrieve(char *in);

char retrieveAge(char *in);

void printZIP(char* z);

int main() {

	// The variable that stores the input 
	char* in = malloc(sizeof(char));

	// Title at the top
	printf("REG COVID\n");

	// The database for registration
	database* COVID_DB = malloc(sizeof(database));

	// The boolean that will terminate the program, when the user inputs the terminating character
	_Bool v = 1;

	int n = 0;

	while (!valQuit(&in))
	{
		// Prompts the user to enter a float
		printf("\nMenu: Register(R) or Exit(X)?: ");

		// Stores value in the in variable
		scanf("\n %s", in);

		// User should enter R to register
		if (valReg(&in))
		{
			n++;
			COVID_DB = realloc(COVID_DB, sizeof(database)* (n + 1));
			reg(COVID_DB,n);                                           // starts a registry for the user
		}
	}

	free(COVID_DB);
	free(in);
	return 0;
}

// initializes new records for the database
void reg(database* db, int n) {

	// Important records for the database
	db[n-1].dNo = 0;
	strcpy(db[n - 1].fname, "");
	strcpy(db[n - 1].lname, "");
	strcpy(db[n - 1].DOB, "");
	strcpy(db[n - 1].TOV, "");
	strcpy(db[n - 1].DOPd, "");
	strcpy(db[n - 1].ZIP, "");

	printf("\nEnter Details\n");

	// Demanding the user to enter first name
	printf("\nEnter First Name: ");
	scanf("\n %s", db[n-1].fname);

	// Demanding the user to enter last name
	printf("\nEnter Last Name: ");
	scanf("\n %s", db[n-1].lname);

	// Demanding the user to enter date
	printf("\nEnter Date of Birth (mm/dd/yyyy): ");
	scanf("\n %s", db[n-1].DOB);

	// Demanding the user to enter dose number
	printf("\nEnter Dose # (1 or 2): ");
	scanf("\n %d", &db[n-1].dNo);


	// Demanding the user to enter date of previous dose
	printf("\nEnter Date of Previous Dose (mm/dd/yyyy or 'N/A' if you entered 1 ): ");
	scanf("\n %s", db[n - 1].DOPd);


	// Demanding the user to enter type of dose
	printf("\nEnter Type of Vaccine (Pfizer, Moderna, J&J): ");
	scanf("\n %s", db[n - 1].TOV);

	// Demanding the user to enter ZIP Code
	printf("\nEnter ZIP Code: ");
	scanf("\n %s", db[n - 1].ZIP);
	
	// generate the code based on the given information
	generate_code(db,n);

	// printing out all the entered details
	printf("\n\nName: %s %s", db[n - 1].fname, db[n - 1].lname);
	printf("\nDate of Birth: %s", db[n - 1].DOB);
	printf("\nShot # : %d", db[n - 1].dNo);
	printf("\nDate of last Shot : %s", db[n - 1].DOPd);
	printf("\nType of Vaccine: %s", db[n - 1].TOV);
	printf("\nZIP: %s\n\n", db[n - 1].ZIP);

}
// generates a code from the records of database db
void generate_code(database* db,int n) {

	char code[255] = "";
	
	printf("\n\nYour code is: ");
	printf("%c", retrieve(&db[n-1].fname));                        // print first char of first name
	printf("%c", retrieve(&db[n-1].lname));                        // print first char of last name
	printf("%d", retrieveAge(&db[n-1].DOB));                       // print age
	printf("%c", retrieve(&db[n-1].TOV));                          // print first char of type of vaccine
	printZIP(&db[n-1].ZIP);                                        // print last 3 digits of ZIP
}

// retrieves first character of in
char retrieve(char* in)
{
	char buff[255] = "";

	strcpy(buff,in);

	return buff[0];
}

// retrieves age from in w.r.t. 2021
char retrieveAge(char *in)
{
	char year[] = "2021";

	char buff[255] = "";

	char cmpYear[255] = "";

	int i = 6, j = 0;

	strcpy(buff, in);

	char c = buff[i];

	strcpy(buff, in);

	while(c!='\0')
	{
		strncat(cmpYear,&c,1);
		i++;
		c = buff[i];
	}

	return year - cmpYear;
}

// checks if in is 'A'
_Bool valReg(char** in) {

	_Bool a = 0;

	int i = 0;

	char buff[255] = "";

	strcpy(buff, *in);

	char c = buff[i];

	if (c == 'R' || c == 'r')
		a = 1;

	return a;
}

// checks if in is 'Q'
_Bool valQuit(char** in) {

	_Bool a = 0;

	int i = 0;

	char buff[255] = "";

	strcpy(buff, *in);

	char c = buff[i];

	if (c == 'X' || c == 'x')
		a = 1;

	return a;
}

//  prints last 3 characters of z
void printZIP(char* z) {

	int i = strlen(z)-3;

	char buff[255] = "";

	strcpy(buff, z);

	while (i != strlen(z))
	{
		printf("%c", buff[i]);                                       // print last 3 digits
		i++;
	}
}