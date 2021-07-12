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




void  GBWT_delete (void * GBWT) {


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
        tmp.second = range.second;
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



CPair* GBWT_edges(void * GBWT,  node_type from ){

         gbwt::GBWT* gbwt = (gbwt::GBWT *)GBWT;
         std::vector<edge_type> tmp_A = gbwt->edges(from);
         CPair* tmp_B =  (CPair*) malloc(sizeof(CPair) * tmp_A.size());

         for (size_t i=0;i != tmp_A.size(); i++) // access by reference to avoid copying
          {

                  tmp_B[i].first=  tmp_A.at(i).first;

                  tmp_B[i].second=  tmp_A.at(i).second;
          }

          return tmp_B;

}

CPair GBWT_LF_next_node_from_offset (void * GBWT, node_type from, size_type i)
{

         gbwt::GBWT* gbwt = (gbwt::GBWT *)GBWT;
         edge_type tmp = gbwt->LF(from,i );
         CPair tmp_0;

        tmp_0.first = tmp.first;

        tmp_0.second = tmp.second;
        return tmp_0;

}





bool GBWT_contains_edge(void * GBWT,  CPair position)
{

        std::pair <uint64_t, uint64_t> tmp;
        tmp = std::make_pair(position.first, position.second);
        gbwt::GBWT* gbwt = (gbwt::GBWT *) GBWT;
        return gbwt->contains(tmp);
}



CPair GBWT_LF_next_node_from_edge (void * GBWT, CPair position)
{
        std::pair <uint64_t, uint64_t> tmp;
        tmp = std::make_pair(position.first, position.second);
        gbwt::GBWT* gbwt = (gbwt::GBWT *) GBWT;
        edge_type tmp_0 = gbwt->LF(tmp);
        CPair tmp_1;
        tmp_1.first = tmp_0.first;
        tmp_1.second = tmp_0.second;
        return tmp_1;
}


size_type GBWT_LF_next_offset_from_node(void * GBWT, node_type from, size_type i, node_type to)
{

        gbwt::GBWT* gbwt = (gbwt::GBWT *) GBWT;
        size_type tmp_0 = gbwt->LF(from, i, to);
        return tmp_0;
}

size_type GBWT_LF_next_offset_from_position (void * GBWT, CPair position, node_type to)

{
        std::pair <uint64_t, uint64_t> tmp;
        tmp = std::make_pair(position.first, position.second);
        gbwt::GBWT* gbwt = (gbwt::GBWT *) GBWT;
        size_type tmp_0 = gbwt->LF(tmp,to);
        return tmp_0;


}



// typedef std::pair<node_type, size_type>   range_type;
// (void * GBWT, node_type from, range_type range, node_type to)
CPair GBWT_LF_range_of_successors_from_node(void * GBWT, node_type from, CPair range, node_type to)
{

        std::pair <uint64_t, uint64_t> tmp;
        tmp = std::make_pair(range.first, range.second);
        gbwt::GBWT* gbwt = (gbwt::GBWT *) GBWT;
        range_type tmp_0 = gbwt->LF(from,tmp,to);
        CPair tmp_1;

        tmp_1.first = range.first;
        tmp_1.second = range.second;
        return tmp_1;
}


