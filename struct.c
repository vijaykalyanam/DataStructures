#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argp)
{

	struct inner {
		int x;
		int y;
		int *a;
		int *b;
	};

	struct test {
		int x;
		int y;
		struct test *t;
		struct inner *i;
	};

	struct test t = {0};
	struct inner *a = t.i;

	printf("%d\n", t.i->x);
	printf("%d\n", t.i->x);

	return 0;
}
