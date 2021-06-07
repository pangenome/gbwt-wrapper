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




void* DynamicGBWT_to_GBWT(void* dynGBWT) {

        gbwt::DynamicGBWT* tmp = (gbwt::DynamicGBWT *)tmp;
        gbwt::GBWT item =   gbwt::GBWT(*tmp) ;
        gbwt::GBWT * pitem = &item;
        return (void *) pitem;
}


void  deleteGBWT(void * GBWT) {


        gbwt::GBWT* gbwt = (gbwt::GBWT *) GBWT;
        delete  gbwt;

}


//methods

size_type total_path_length (void * GBWT) {

        gbwt::GBWT* gbwt = (gbwt::GBWT *) GBWT;
        return gbwt->size();

}



bool has_empty_index (void * GBWT) {

        gbwt::GBWT* gbwt = (gbwt::GBWT *) GBWT;
        return gbwt->empty();
}




size_type number_of_paths(void* GBWT)
        {
        gbwt::GBWT* gbwt = (gbwt::GBWT *) GBWT;
        return gbwt->sequences();
}


size_type alphabet_size(void* GBWT)

        {
        gbwt::GBWT* gbwt = (gbwt::GBWT *) GBWT;
        return gbwt->sigma();
}


size_type effective_alpahbet_size(void* GBWT)

        {
        gbwt::GBWT* gbwt = (gbwt::GBWT *) GBWT;
        return gbwt->effective();
}

size_type number_of_samples(void* GBWT)

        {
        gbwt::GBWT* gbwt = (gbwt::GBWT *) GBWT;
        return gbwt->samples();
}



bool is_index_bidirectional(void* GBWT)

        {
        gbwt::GBWT* gbwt = (gbwt::GBWT *) GBWT;
        return gbwt->bidirectional();
}

std::pair<size_type, size_type>   number_of_gwt_runs   (void* GBWT)

        {
        gbwt::GBWT* gbwt = (gbwt::GBWT *) GBWT;
        return gbwt->runs();
}


