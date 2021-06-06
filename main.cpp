#include"gbwt_wrapper.h"
#include"/usr/local/include/gbwt/gbwt.h"

int main(void){
        void* skata = newDynamicGBWT() ;
        deleteDynamicGBWT(skata);
        printf("Hello world");
        return 0;
}
