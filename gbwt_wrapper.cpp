#include"gbwt_wrapper.h"


void* DGBWT_new(void) {

        gbwt::DynamicGBWT *gbwt =  new gbwt::DynamicGBWT;
        return (void *)gbwt  ;
}

void  DGBWT_delete(void * dynGBWT) {


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


void  DGBWT_insert (void* dynGBWT, void* text) {
        text_type s =  stringToText(text);
        insertGBWTSequence(dynGBWT, s);
}


// void DGBWT_insert(void*, *void text);


void* DGBWT_to_GBWT(void* dynGBWT) {
        gbwt::DynamicGBWT* tmp = (gbwt::DynamicGBWT *)dynGBWT;
        gbwt::GBWT item =   gbwt::GBWT(*tmp) ;
        gbwt::GBWT * pitem = &item;
        return (void *) pitem;
}


// void*   unDynamizeGBWT (void* dynGBWT) {
//         printf("skata") ;
//         gbwt::DynamicGBWT* tmp = (gbwt::DynamicGBWT *)tmp;
//         gbwt::GBWT item =   gbwt::GBWT(*tmp) ;
//         printf("pipa") ;
//         gbwt::GBWT * pitem = &item;
//         printf("colo") ;
//         return (void *) pitem;
// }




void  deleteGBWT(void * GBWT) {


        gbwt::GBWT* gbwt = (gbwt::GBWT *) GBWT;
        delete  gbwt;

}


//methods




bool has_empty_index (void * GBWT) {

        gbwt::GBWT* gbwt = (gbwt::GBWT *) GBWT;
        return gbwt->empty();
}




size_type GBWT_number_of_paths(void* GBWT)
        {
        gbwt::GBWT* gbwt = (gbwt::GBWT *) GBWT;
        return gbwt->sequences();
}


size_type GBWT_alphabet_size(void* GBWT)

        {
        gbwt::GBWT* gbwt = (gbwt::GBWT *) GBWT;
        return gbwt->sigma();
}


size_type GBWT_effective_alpahbet_size(void* GBWT)

        {
        gbwt::GBWT* gbwt = (gbwt::GBWT *) GBWT;
        return gbwt->effective();
}

size_type GBWT_number_of_samples(void* GBWT)

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



node_type  GBWT_get_search_state_node(CSearchState cstate){
        gbwt::SearchState* state = (gbwt::SearchState *) cstate;
        return state->node;
}


CPair GBWT_get_search_state_range(CSearchState cstate) {

        CPair tmp;
        gbwt::SearchState* state = (gbwt::SearchState *) cstate;
        range_type range = state->range;
        tmp.first = range.first;
        tmp.first = range.second;
        return tmp;
}


CSearchState GBWT_get_forward_state(CBidirectionalSearchState cstate)   {

        gbwt::BidirectionalState* state = (gbwt::BidirectionalState *) cstate;
         void*  tmp = &state->forward;
        return tmp;
}
CSearchState GBWT_get_backward_state(CBidirectionalSearchState cstate){

        gbwt::BidirectionalState* state = (gbwt::BidirectionalState *) cstate;
         void*  tmp = &state->backward;
        return tmp;
}

size_type GBWT_get_search_state_size(CSearchState cstate) {

        gbwt::SearchState* state = (gbwt::SearchState *) cstate;
        return  state->size();

}

// size_type GBWT_total_path_length(CBidirectionalSearchState cstate){
//
//         gbwt::SearchState* state = (gbwt::SearchState*) cstate;
//         return  state->size();
//
// }

size_type GBWT_total_path_length (void * GBWT) {

        gbwt::GBWT* gbwt = (gbwt::GBWT *) GBWT;
        return gbwt->size();

}

bool GBWT_is_search_state_empty(void* cstate)      {
        gbwt::SearchState* state = (gbwt::SearchState *) cstate;
        return  state->empty();
        }


bool is_bidirectional_search_state_empty(void* cstate)      {
        gbwt::BidirectionalState* state = (gbwt::BidirectionalState *) cstate;
        return  state->empty();
        }

void GBWT_flip_state(void* cstate) {
 gbwt::BidirectionalState* state = (gbwt::BidirectionalState  *) cstate;
 state->flip(); }


CSearchState  GBWT_find (void* GBWT, node_type node) {
         gbwt::GBWT* gbwt = (gbwt::GBWT *)GBWT;
         gbwt::SearchState new_state = gbwt->find(node)  ;
         gbwt::SearchState*  tmp = &new_state ;
         return (CSearchState  *) tmp  ;
 }


CSearchState  GBWT_extend (void* GBWT,  CSearchState state, node_type node){
         gbwt::GBWT* gbwt = (gbwt::GBWT *)GBWT;
         gbwt::SearchState*  state1 = (gbwt::SearchState*) state ;
         gbwt::SearchState new_state = gbwt->extend(  *state1 , node );
         gbwt::SearchState*  tmp = &new_state ;
         return (CSearchState) tmp;
}







CBidirectionalSearchState biGBWT_find (void* GBWT, node_type node){
         gbwt::GBWT* gbwt = (gbwt::GBWT *)GBWT;
         gbwt::BidirectionalState   new_state = gbwt->bdFind(node)  ;
         gbwt::BidirectionalState*  tmp = &new_state ;
         return (CBidirectionalSearchState   *) tmp  ;
 }

void*  bdExtendForwardGBWT (void* GBWT, CBidirectionalSearchState state, node_type node){

         gbwt::GBWT* gbwt = (gbwt::GBWT *)GBWT;
         gbwt::BidirectionalState*  state1 = (gbwt::BidirectionalState*) state ;
         gbwt::BidirectionalState   new_state = gbwt->bdExtendForward ( *state1,  node)  ;
         gbwt::BidirectionalState*  tmp = &new_state ;
         return (CBidirectionalSearchState   *) tmp  ;


}
void*  bdExtendBackwardGBWT (void* GBWT, CBidirectionalSearchState state, node_type node){

                gbwt::GBWT* gbwt = (gbwt::GBWT *)GBWT;
                gbwt::BidirectionalState*  state1 = (gbwt::BidirectionalState*) state ;
                gbwt::BidirectionalState   new_state = gbwt->bdExtendBackward( *state1,  node)  ;
                gbwt::BidirectionalState*  tmp = &new_state ;
                return (CBidirectionalSearchState   *) tmp  ;


        }


node_type GBWT_first_node(void* GBWT){
         gbwt::GBWT* gbwt = (gbwt::GBWT *)GBWT;
         return gbwt->firstNode();
}

size_type  GBWT_locate  (void* GBWT, node_type node, size_type i){

                gbwt::GBWT* gbwt = (gbwt::GBWT *)GBWT;
                return gbwt->locate (node, i);

        }


bool GBWT_get_bidirectional_state_size(CBidirectionalSearchState state){
        gbwt::BidirectionalState* state1 = (gbwt::BidirectionalState*) state ;
        return  state1->empty();

}

bool GBWT_contains_node (void * GBWT,  node_type node)
{
        gbwt::GBWT* gbwt = (gbwt::GBWT *) GBWT;
        return gbwt->contains(node);


}


bool GBWT_contains_edge(void * GBWT,  edge_type position)
{

        gbwt::GBWT* gbwt = (gbwt::GBWT *) GBWT;
        return gbwt->contains(position);


}


// CSearchState  GBWT_extend (void* GBWT,  CSearchState state, node_type node){

bool GBWT_contains_search_state(void * GBWT,  CSearchState state)
{

         gbwt::GBWT* gbwt = (gbwt::GBWT *)GBWT;
         gbwt::SearchState*  state1 = (gbwt::SearchState*) state ;
         return gbwt->contains(*state1);

}


bool GBWT_has_edge(void * GBWT,  node_type from, node_type to)
{

         gbwt::GBWT* gbwt = (gbwt::GBWT *)GBWT;
         return gbwt->hasEdge(from,to);
}


comp_type GBWT_to_comp(void * GBWT,  node_type node){


         gbwt::GBWT* gbwt = (gbwt::GBWT *)GBWT;
         return gbwt->toComp(node);
}


 node_type GBWT_to_node(void * GBWT,  comp_type comp)
 {


         gbwt::GBWT* gbwt = (gbwt::GBWT *)GBWT;
         return gbwt->toNode(comp);
}
 size_type GBWT_node_size(void * GBWT,  node_type node)
         {


         gbwt::GBWT* gbwt = (gbwt::GBWT *)GBWT;
         return gbwt->nodeSize(node);
}

// size_type GBWT_total_path_length (void * GBWT) {
//
//         gbwt::GBWT* gbwt = (gbwt::GBWT *) GBWT;
//         return gbwt->size();
//
// }
//

// extern "C" bool GBWT_contains_edge(edge_type position);
// extern "C" bool GBWT_contains_search_state(SearchState state);
// extern "C" bool GBWT_has_edge(node_type from, node_type to);
// extern "C" comp_type GBWT_to_comp(node_type node);
// extern "C" node_type GBWT_to_node(comp_type comp);
// extern "C" size_type GBWT_node_size(node_type node);
//
//
