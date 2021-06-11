#include"gbwt_wrapper.h"


void* newDynamicGBWT(void) {

        gbwt::DynamicGBWT *gbwt =  new gbwt::DynamicGBWT;
        return (void *)gbwt  ;
}

void  deleteDynamicGBWT(void * dynGBWT) {


          gbwt::DynamicGBWT* gbwt = (gbwt::DynamicGBWT *) dynGBWT;
        delete  gbwt;

}


text_type stringToText (void* text)
{
        int i;
        int string_end = 0;
        int string_index =0;
        text_type  str_vector ;
        int* tmp =   (int*) text  ;
        str_vector.width(8);
        while(string_end == 0) {
                if (tmp[string_index] == NULL) {
                        string_end=1;
                }
                else {
                        string_index++;
                }
        }

        str_vector.resize(string_index + 1) ;

        for (i=0; i<=string_index; i++)
        {
        str_vector[i] = tmp [i];
        }
        return str_vector;
}


void insertGBWTSequence (void *  dynGBWT, text_type& text) {
        gbwt::DynamicGBWT* bgwt = (gbwt::DynamicGBWT *) dynGBWT;
        bgwt->insert(text);
}


void  insertSequence (void* dynGBWT, void* text) {
        text_type s =  stringToText(text);
        insertGBWTSequence(dynGBWT, s);
}


// void insertSequence(void*, *void text);


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

runStats numberOfGWTRuns (void* GBWT)
        {
        gbwt::GBWT* gbwt = (gbwt::GBWT *) GBWT;
        std::pair<size_type, size_type>  runs = gbwt->runs();
        runStats rs ;
        rs.concreteRuns = runs.first   ;
        rs.logicalRuns = runs.second ;
        return rs;
}



node_type  get_search_state_node(CSearchState cstate){
        gbwt::SearchState* state = (gbwt::SearchState *) cstate;
        return state->node;
}


CPair get_search_state_range(CSearchState cstate) {

        CPair tmp;
        gbwt::SearchState* state = (gbwt::SearchState *) cstate;
        range_type range = state->range;
        tmp.first = range.first;
        tmp.first = range.second;
        return tmp;
}


CSearchState get_forward_state(CBidirectionalSearchState cstate)   {

        gbwt::BidirectionalState* state = (gbwt::BidirectionalState *) cstate;
         void*  tmp = &state->forward;
        return tmp;
}
CSearchState get_backward_state(CBidirectionalSearchState cstate){

        gbwt::BidirectionalState* state = (gbwt::BidirectionalState *) cstate;
         void*  tmp = &state->backward;
        return tmp;
}

size_type get_search_state_size(CSearchState* cstate) {

        gbwt::SearchState* state = (gbwt::SearchState *) cstate;
        return  state->size();

}

size_type get_bidirectional_state_size(CBidirectionalSearchState* cstate){

        gbwt::SearchState* state = (gbwt::SearchState*) cstate;
        return  state->size();

}
bool is_search_state_empty(void* cstate)      {

        gbwt::SearchState* state = (gbwt::SearchState *) cstate;
        return  state->empty();
        }



bool is_bidirectional_search_state_empty(void* cstate)      {
        gbwt::BidirectionalState* state = (gbwt::BidirectionalState *) cstate;
        return  state->empty();
        }

void flip_state(void* cstate) {
 gbwt::BidirectionalState* state = (gbwt::BidirectionalState  *) cstate;
 state->flip(); }





