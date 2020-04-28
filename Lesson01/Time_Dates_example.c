/*
	Time and Dates Full example
	References:
		https://www.codingunit.com/c-tutorial-how-to-use-time-and-date-in-c
		https://en.cppreference.com/w/cpp/header/ctime
*/
#include <stdio.h>
#include <time.h>

#define PST (-8)
#define CET (1)

/* Declarations
*/
void wait ( int sec );

/* Main func
*/
int main ()
{
	/*
		>> UNIX Time or POSIX Time
	*/
    time_t sec;
    sec = time (NULL);

    printf ("Number of hours since January 1, 1970 is %ld \n", sec/3600);

    /*
		>> Readable Current Local Time using ctime
    */
    time_t mytime;
	mytime = time(NULL);
    printf(ctime(&mytime));

    /*
    	>> Manipulating the time structure with mktime()

		Www = which day of the week.
		Mmm = month in letters.
		dd = the day of the month.
		hh:mm:ss = the time in hour, minutes, seconds.
		yyyy = the year.

		Output example:
			Tue Feb 26 09:01:47 2009
    */
    struct tm str_time;
    time_t time_of_day;

    str_time.tm_year = 2012-1900;
	str_time.tm_mon = 6;
	str_time.tm_mday = 5;
	str_time.tm_hour = 10;
	str_time.tm_min = 3;
	str_time.tm_sec = 5;
	str_time.tm_isdst = 0;

	time_of_day = mktime(&str_time);
	printf(ctime(&time_of_day));

	/*
		>> Using the function difftime
	*/
	time_t start,end;
	volatile long unsigned counter;

	start = time(NULL);

	for(counter = 0; counter < 500000000; counter++)
		; /* Do nothing, just loop */

	end = time(NULL);
	printf("The loop used %f seconds.\n", difftime(end, start));

	/*
		>> Working with diff Timezones
	*/
	time_t raw_time;
    struct tm *ptr_ts;

    time ( &raw_time );
    ptr_ts = gmtime ( &raw_time );

    printf ("Time Los Angeles: %2d:%02d\n",
         ptr_ts->tm_hour+PST, ptr_ts->tm_min);
    printf ("Time Amsterdam: %2d:%02d\n",
         ptr_ts->tm_hour+CET, ptr_ts->tm_min);

    /*
		>> Number of clock ticks
    */
    printf ("Start the Wait!\n");

	wait (5);	/* Wait for 5 seconds */

	printf ("End Wait!\n");

    return 0;
}

/*
	>> wait fuc

	CLOCKS_PER_SEC:
	https://stackoverflow.com/q/36888937/5688267
	http://man7.org/linux/man-pages/man3/clock.3.html
*/
void wait ( int sec )
{
	clock_t end_wait;
	end_wait = clock () + sec * CLOCKS_PER_SEC; /* */

	while (clock() < end_wait) {}
}