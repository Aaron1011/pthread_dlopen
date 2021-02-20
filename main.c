#include <dlfcn.h>
#include <stdio.h>

int main(int argc, char** argv) {
    void *lib = dlopen("./libmy_library.so", RTLD_NOW);
	if (!lib) {
        printf("Dl error: %s\n", dlerror());
        return 1;
	}
    printf("Loaded: %p\n", lib);

    void (*my_fn)() = dlsym(lib, "my_fn");
    if (!my_fn) {
        printf("Dlsym error: %s\n", dlerror());
        return 1;
    }
    printf("Calling my_fn\n");
    my_fn();
    return 0;
}
