#include"gbwt_wrapper.h"

int main(void){
        void* skata = DGBWT_new() ;
        void* text = (void*) "Hellow world" ;
        DGBWT_insert (skata,  text);
        // insertGBWTSequence(skata, t);
        DGBWT_delete(skata);
        printf("Hello world");
        return 0;
}
