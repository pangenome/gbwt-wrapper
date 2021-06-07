
 gcc -c -fPIC gbwt_wrapper.cpp

gcc -o libgbwtwrapper.so -Wl,--whole-archive libsdsl.a libgbwt.a -Wl,--no-whole-archive -shared gbwt_wrapper.o
g++ -L. -l:libgbwtwrapper.so  main.cpp  -pthread -fopenmp

 gcc -o libgbwtwrapper.so -Wl,--whole-archive libsdsl.a libgbwt.a -Wl,--no-whole-archive -shared gbwt_wrapper.o -Wl,--version-script=export.txt -Wl,--no-undefined
