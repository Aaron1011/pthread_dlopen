#include <pthread.h>
#include <stdio.h>

static pthread_key_t key;

void my_dtor() {
    printf("Called destructor\n");
}

void *my_thread_fn(void *arg) {
    printf("Thread starting\n");
    pthread_setspecific(key, (void *) 1);
    printf("Thread exitingg\n");
    return NULL;
}

void my_fn() {
    printf("Creating pthread key!\n");
    pthread_key_create(&key, my_dtor);
    pthread_setspecific(key, (void *) 1);
    printf("Returning from my_fn\n");

    /*pthread_t tid;
    pthread_create(&tid, NULL, &my_thread_fn, NULL);
    pthread_join(tid, NULL);
    printf("Back in my_fn\n");*/
}
