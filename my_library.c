#include <pthread.h>
#include <stdio.h>

static pthread_key_t key;

void my_dtor() {
    printf("Called destructor\n");
}

void my_fn() {
    printf("Creating pthread key!\n");
    pthread_key_create(&key, my_dtor);
}
