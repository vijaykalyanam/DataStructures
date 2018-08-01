/* This three parameters should not be global.
 * It would be better if we define them as local global parameters in file.
 */
/*
#define TOP 8
extern int top;
extern int astack[TOP];
*/
int isEmpty(void);
int isFull(void);
int peek(void);
int push(int data);
int pop(void);
void list();
