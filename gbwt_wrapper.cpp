// #include"/usr/local/include/gbwt/dynamic_gbwt.h"
#include"gbwt_wrapper.h"


CDynamicGBWT newDynamicGBWT(void) {
    return reinterpret_cast<void*>(new DynamicGBWT());
}

void  deleteDynamicGBWT(CDynamicGBWT dynGBWT) {
         delete reinterpret_cast<CDynamicGBWT*>(dynGBWT);

}

void insertGBWTSequence (CDynamicGBWT  dynGBWT, const text_type& text, bool has_both_orientations = false, size_type sample_interval = SAMPLE_INTERVAL)
{
    return reinterpret_cast<CDynamicGBWT*>(fred)->insert(text, has_both_orientations, sample_interval );
}

int main(void){
        printf("Hello world");
        return 0;
}
