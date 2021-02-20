#include <dlfcn.h>
#include <stdio.h>
#include <pthread.h>

void *other_thread_fn(void *arg) {
    printf("Thread starting in main.c\n");

    void *lib = dlopen("./libmy_library.so", RTLD_NOW);
	if (!lib) {
        printf("Dl error: %s\n", dlerror());
        return NULL;
	}
    printf("Loaded: %p\n", lib);

    void (*my_fn)() = dlsym(lib, "my_fn");
    if (!my_fn) {
        printf("Dlsym error: %s\n", dlerror());
        return NULL;
    }
    printf("Calling my_fn\n");
    my_fn();

    // Comment out this line to stop the crash
    dlclose(lib);
    return NULL;
}

int main(int argc, char** argv) {
    pthread_t tid;
    pthread_create(&tid, NULL, &other_thread_fn, NULL);
    pthread_join(tid, NULL);
    printf("Back in main()\n");

    return 0;
}
