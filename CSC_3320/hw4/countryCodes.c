# include <stdio.h>
# include <stdlib.h>
# include <string.h>

char* lookUp(char* code);

int main() {

	// String used to process code
	char* code = malloc(sizeof(char));

	// String used to retrieve correspnding country
	char* result = malloc(sizeof(char));

	// Demanding the user the user to enter a country code
	printf("Enter code here: ");
	scanf("%s", code);

	result = lookUp(&code);

	printf("\nCountry: %s", result);

	free(code);
	free(result);
	return 0;
}

// Function that checks for the country from its code
char* lookUp(char** code) {
	int i = 0;
	char tri[255] = "";

	// There are two fields to this structure array: name and code respectively
	struct part { char name[255]; char code[255]; } country_code[20];

	strcpy(country_code[0].name, "USA/Canada"); strcpy(country_code[0].code,"001");
	strcpy(country_code[1].name, "India"); strcpy(country_code[1].code, "091");
	strcpy(country_code[2].name, "Japan"); strcpy(country_code[2].code, "081");
	strcpy(country_code[3].name, "Russia"); strcpy(country_code[3].code, "007");
	strcpy(country_code[4].name, "Netherlands"); strcpy(country_code[4].code, "031");
	strcpy(country_code[5].name, "China"); strcpy(country_code[5].code, "086");
	strcpy(country_code[6].name, "France"); strcpy(country_code[6].code, "033");
	strcpy(country_code[7].name, "UK"); strcpy(country_code[7].code, "44");
	strcpy(country_code[8].name, "Sweden"); strcpy(country_code[8].code, "046");
	strcpy(country_code[9].name, "Switzerland"); strcpy(country_code[9].code, "041");
	strcpy(country_code[10].name, "Australia"); strcpy(country_code[10].code, "061");
	strcpy(country_code[11].name, "Mexico"); strcpy(country_code[11].code, "052");
	strcpy(country_code[12].name, "Portugal"); strcpy(country_code[12].code, "351");
	strcpy(country_code[13].name, "Germany"); strcpy(country_code[13].code, "049");
	strcpy(country_code[14].name, "Brazil"); strcpy(country_code[14].code, "055");
	strcpy(country_code[15].name, "Botswana"); strcpy(country_code[15].code, "267");
	strcpy(country_code[16].name, "UAE"); strcpy(country_code[16].code, "971");
	strcpy(country_code[17].name, "Denmark"); strcpy(country_code[17].code, "045");
	strcpy(country_code[18].name, "Czech Republic"); strcpy(country_code[18].code, "420");
	strcpy(country_code[19].name, "Ukraine"); strcpy(country_code[19].code, "380");

	if (strlen(*code) == 0)                                             // null codes are not allowed
	{
		return "Entry does not exist.";
	}

	else if (strlen(*code) == 1)                                        // single digits are concatenated with 00
	{
		strcat(tri, "00");
		strcat(tri, *code);
	}

    else if (strlen(*code) == 2)                                             // double digits are concatenated with 0
	{
		strcat(tri, "0");
		strcat(tri, *code);
	}

	else
	  strcpy(tri, *code);

		while (i < 20 && strcmp(tri, country_code[i].code) != 0)        // these digits are processed and compared with the codes of all entries
		{
			i++;
		}

		if (i >= 20)
			return "Entry does not exist.";

		else
			return country_code[i].name;
}
