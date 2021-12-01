#include <stdio.h>
#include <sys/time.h>
#include <time.h>
#include <unistd.h>

int main()
{
	long int lt = time(NULL);;
	struct tm* ptm;
    struct timespec ts;
	struct timeval tmvl;
    clock_t start = clock();
	printf("by using time(): \t\t%s", ctime(&lt));
    clock_t end = clock();
    printf("lead time time: %ld\n", (end - start)/_SC_CLK_TCK);
    start = clock();
	gettimeofday(&tmvl, NULL);
	ptm = localtime(&tmvl.tv_sec);
	char str[50];
	strftime(str, sizeof(str), "%a %b %d %X %Y", ptm);
	printf("by using gettimeofday(): \t%s\n", str);
    end = clock();
    printf("lead time time: %ld\n", (end - start)/_SC_CLK_TCK);
    start = clock();
	clock_gettime(CLOCK_REALTIME, &ts);
	printf("by using clock_gettime(): \t%s", ctime(&ts.tv_sec));
    end = clock();
    printf("lead time time: %ld\n", (end - start)/_SC_CLK_TCK);
	return 0;
}