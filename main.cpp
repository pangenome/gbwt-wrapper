#include"gbwt_wrapper.h"

int main(void){
        void* skata = newDynamicGBWT() ;
        void* text = (void*) "Hellow world" ;
        insertSequence (skata,  text);
        // insertGBWTSequence(skata, t);
        deleteDynamicGBWT(skata);
        printf("Hello world");
        return 0;
}
