#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

/* fonction qui calcule le nombre de clicks */
void *inc_x(void *x_void_ptr)
{
/* incrementer x by 1 */
int *x_ptr = (int *)x_void_ptr;
++*x_ptr;
printf("Nb de clicks : %d\n", *x_ptr);
/* Sleep pendant 3 secondes then decrement by 1 */
Sleep(3000);
--*x_ptr;
printf("Nb de clicks : %d\n", *x_ptr);
/* the function must return something - NULL will do */
return NULL;
}

int main()
{
int x = 0;
/* show the initial values of x and y */
printf("Nb de clicks : %d\n", x);
while(1)
{
    getchar();
    if(x>=2) {
        printf("Arrêt d'urgence !!!!\n");
        /* Retourner / enlever le si vous
        souhaitez que le programme continue à tourner */
        return 2;
    }
    /* this variable is our reference to the second thread */
    pthread_t inc_x_thread;
    /* create a second thread which executes inc_x(&x) */
    if(pthread_create(&inc_x_thread, NULL, inc_x, &x)) {
    fprintf(stderr, "Error creating thread\n");
    return 1;
    }
}
return 0;
}
