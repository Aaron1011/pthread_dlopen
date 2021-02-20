#include <dlfcn.h>
#include <stdio.h>

int main(int argc, char** argv) {
    void *lib = dlopen("./libmy_library.so", RTLD_NOW);
	if (!lib) {
        printf("Dl error: %s\n", dlerror());
        return 1;
	}
    printf("Loaded: %p\n", lib);
    return 0;
}
