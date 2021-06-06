
 gcc -c -fPIC gbwt_wrapper.cpp

gcc -o libfiledyn.so -Wl,--whole-archive libsdsl.a libgbwt.a -Wl,--no-whole-archive -shared gbwt_wrapper.o
g++ -L. -l:libfiledyn.so  main.cpp  -pthread -fopenmp
