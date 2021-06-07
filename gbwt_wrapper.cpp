// #include"/usr/local/include/gbwt/utils.h"
#include"/usr/local/include/gbwt/dynamic_gbwt.h"
#include"gbwt_wrapper.h"
#include"/usr/local/include/gbwt/gbwt.h"

void* newDynamicGBWT(void) {

        gbwt::DynamicGBWT *gbwt =  new gbwt::DynamicGBWT;
        return (void *)gbwt  ;
}

void  deleteDynamicGBWT(void * dynGBWT) {


          gbwt::DynamicGBWT* gbwt = (gbwt::DynamicGBWT *) dynGBWT;
        delete  gbwt;

}


void insertGBWTSequence (void *  dynGBWT, text_type& text) {


        gbwt::DynamicGBWT* bgwt = (gbwt::DynamicGBWT *) dynGBWT;
        bgwt->insert(text);
}


