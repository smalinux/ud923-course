/*
	strlen()    Get length of a string.
	strcpy()    Copy one string to another.
	strcat()    Link together (concatenate) two strings.
	strcmp()    Compare two strings.
	strchr()    Find character in string.
	strstr()    Find string in string.
	strlwr()    Convert string to lowercase. 	X not included in c lib
	strupr()    Convert string to uppercase.	X not included in c lib

	Reference:
		https://en.wikibooks.org/wiki/A_Little_C_Primer/C_String_Function_Library
		gets is dangerous!: https://stackoverflow.com/q/1694036/5688267
*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define ANSWER "blue"
char *t_sma = "Hey Barney hey!";

/*
	sma_ is my prefix! )
*/
static void sma_strlen(void);
static void sma_strcpy(void);
static void sma_strcat(void);
static void sma_strcmp(void);
static void sma_strchr(void);
static void sma_strstr(void);
static void sma_casecvt(void);
/* Utilities */
char *sma_strlwr(char *str);
char *sma_gets(char *buffer);

/* Main func!
*/
int main()
{
	/* 
		strlen()
	*/
	sma_strlen();

	/*
		strcpy()
	*/
	sma_strcpy();

	/*
		strcat()
	*/
	sma_strcat();

	/*
		strcmp()
	*/
	sma_strcmp();

	/*
		strchr()	
	*/
	sma_strchr();

	/*
		strstr()
	*/
	sma_strstr();
	// printf("%s\n", "Test_____________________________");

	/*
		Upper & lower: strlwr() && strupr()
		strlwr and strupr are not exists in C lib of linux
	*/
	sma_casecvt();
	// printf("%s\n", "Test_____________________________");

	return 0;
}

static void sma_strlen(void)
{
	char *t = "lorem ipsum";
	printf( "Length of <%s> is %d.\n", t, strlen( t ));
}

static void sma_strcpy(void)
{
	char s1[100],
		s2[100];
	strcpy( s1, "xxxxxx 1" );
	strcpy( s2, "zzzzzz 2" );

	puts( "Original strings: " );
	puts( "" );
	puts( s1 );
	puts( s2 );
	puts( "" );

	strcpy( s2, s1 );

	puts( "New strings: " );
	puts( "" );
	puts( s1 );
	puts( s2 );
}

static void sma_strcat(void)
{
	char s1[50],
		s2[50];
	strcpy( s1, "Tweedledee " );
	strcpy( s2, "Tweedledum" );
	strcat( s1, s2 );
	puts( s1 );
}

/*
	gets is dangerous!: https://stackoverflow.com/q/1694036/5688267
*/
static void sma_strcmp(void)
{
	char t[100];
	puts( (const char *)"What is the secret color?" );
	sma_gets( t );
	while ( strcmp( t, ANSWER ) != 0 )
	{
		puts( (const char *)"Wrong, try again." );
		sma_gets( t );
	}
	puts( (const char *)"Right!" );
}

static void sma_strchr(void)
{
	char *t = "MEAS:VOLT:DC?";
	char *p;
	p = t;
	puts( p );
	while(( p = strchr( p, ':' )) != NULL )
	{
		puts( ++p );
	}
}

static void sma_strstr(void)
{
	char *s = "Black White Brown Blue Green";
	puts( strstr( s, "Blue" ) );
}

static void sma_casecvt(void)
{
	puts( (const char *)sma_strlwr( (char *)&t_sma ) );
	// puts( (const char *) strupr( t ) );
}

/*
	Simple impl for strlwr in linux ))
	Ref: https://stackoverflow.com/a/23618467/5688267
*/
char *sma_strlwr(char *str)
{
  unsigned char *p = (unsigned char *)str;

  while (*p) {
	*p = tolower((unsigned char)*p);
	p++;
  }

  return str;
}

char *sma_gets(char *s) {
  // Use int to distinguish the typical 257 different returns values of getchar() 
  int ch;
  char *p = s;

  // stop when a \n or EOF encountered 
  // while ( (ch=getchar()) != '0' )
  while ( (ch=getchar()) != '\n' && ch != EOF) {
    // Note lack of check for adequate array space
    *s = (char) ch;
    s++;
  }

  // Append a null character, not assign a zero to the pointer
  // s='\0';
  *s = '\0';
  return p;
}