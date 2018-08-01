stack:
	gcc -Wincompatible-pointer-types -I. -o stack stack_array.c
stack_linked:
	#This will supress all the warnings, which is not good in all cases.
	#gcc -Wincompatible-pointer-types -I. -o stack_linked common_linked.c stack_linked.c
	gcc -I. -o stack_linked common_linked.c stack_linked.c

clean:
	rm -rf ./*.o
	rm -rf stack
	rm -rf stack_linked
