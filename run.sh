rm -f a.out libmy_library.so

gcc my_library.c -lpthread -shared -fPIC -o libmy_library.so
gcc main.c  -ldl -lpthread
./a.out
