#include"gbwt_wrapper.h"
#include <math.h>
#include <cinttypes>
#include <stdio.h>



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
                if (!tmp[string_index]) {
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

void* insertGBWTSequence (void *  dynGBWT, text_type& text) {
        gbwt::DynamicGBWT* bgwt = (gbwt::DynamicGBWT *) dynGBWT;
        bgwt->insert(text);
        return dynGBWT;
}

void*  DGBWT_insert (void* dynGBWT, void* text) {
        text_type s =  stringToText(text);
        insertGBWTSequence(dynGBWT, s);
         return dynGBWT;
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




bool GBWT_empty (void * GBWT) {
        gbwt::GBWT* gbwt = (gbwt::GBWT *) GBWT;
        return gbwt->empty();
}

size_type GBWT_sequences(void* GBWT)
        {
        gbwt::GBWT* gbwt = (gbwt::GBWT *) GBWT;
        return gbwt->sequences();
}

size_type GBWT_sigma(void* GBWT)

        {
        gbwt::GBWT* gbwt = (gbwt::GBWT *) GBWT;
        return gbwt->sigma();
}

size_type GBWT_effective(void* GBWT)

        {
        gbwt::GBWT* gbwt = (gbwt::GBWT *) GBWT;
        return gbwt->effective();
}

size_type GBWT_samples(void* GBWT)

        {
        gbwt::GBWT* gbwt = (gbwt::GBWT *) GBWT;
        return gbwt->samples();
}

bool GBWT_bidirectional(void* GBWT)

        {
        gbwt::GBWT* gbwt = (gbwt::GBWT *) GBWT;
        return gbwt->bidirectional();
}

runStats GBWT_runs  (void* GBWT)
        {
        gbwt::GBWT* gbwt = (gbwt::GBWT *) GBWT;
        std::pair<size_type, size_type>  runs = gbwt->runs();
        runStats rs ;
        rs.concreteRuns = runs.first   ;
        rs.logicalRuns = runs.second ;
        return rs;
}

node_type  SEARCHSTATE_node(CSearchState cstate){
        gbwt::SearchState* state = (gbwt::SearchState *) cstate;
        uint64_t tmp = state->node  ;
        return tmp;
}

CPair SEARCHSTATE_range(CSearchState cstate) {
        CPair tmp;
        gbwt::SearchState* state = (gbwt::SearchState *) cstate;
        range_type range = state->range;
        tmp.first = range.first;
        tmp.second = range.second;
        return tmp;
}

int SEARCHSTATE_sizeof () {
        return sizeof(gbwt::SearchState) ;
}

int  SEARCHSTATE_sizeof_bi_search_state () {
        return sizeof(gbwt::BidirectionalState) ;
}

void  BI_SEARCHSTATE_forward (CBidirectionalSearchState  out, CBidirectionalSearchState cstate)   {
        gbwt::BidirectionalState* state = (gbwt::BidirectionalState *) cstate;
        gbwt::SearchState* tmp = (gbwt::SearchState*) out;
        *tmp = state->forward;
}

void BI_SEARCHSTATE_backward (CBidirectionalSearchState  out,  CBidirectionalSearchState cstate){

        gbwt::BidirectionalState* state = (gbwt::BidirectionalState *) cstate;
        gbwt::SearchState* tmp = (gbwt::SearchState*) out;
        *tmp = state->backward;
}


size_type SEARCHSTATE_size(CSearchState cstate) {
        gbwt::SearchState* state = (gbwt::SearchState *) cstate;
        return  state->size();

}

size_type GBWT_size (void * GBWT) {

        gbwt::GBWT* gbwt = (gbwt::GBWT *) GBWT;
        return gbwt->size();

}

bool SEARCHSTATE_empty(void* cstate)      {
        gbwt::SearchState* state = (gbwt::SearchState *) cstate;
        bool tmp  = state->empty();
        return  tmp;
}


bool BI_SEARCHSTATE_empty(void* cstate)      {
        gbwt::BidirectionalState* state = (gbwt::BidirectionalState *) cstate;
        return  state->empty();
        }

void  SEARCHSTATE_flip(void* cstate) {
 gbwt::BidirectionalState* state = (gbwt::BidirectionalState  *) cstate;
 state->flip();
}

 void  GBWT_find (void* GBWT, void* out, node_type node) {
         gbwt::GBWT* gbwt = (gbwt::GBWT*) GBWT;
         gbwt::SearchState* tmp = (gbwt::SearchState*)  out;
         *tmp =    gbwt->find(node) ;
 }



void  GBWT_SEARCHSTATE_extend
( void* GBWT, CSearchState out,   CSearchState state, node_type node){
         gbwt::GBWT* gbwt = (gbwt::GBWT *)GBWT;
         gbwt::SearchState*  state1 = (gbwt::SearchState*) state ;
         gbwt::SearchState* tmp = (gbwt::SearchState*)  out;
         *tmp = gbwt->extend( *state1 , node );
}



void GBWT_bi_find (void* GBWT,  CBidirectionalSearchState out,node_type node){
         gbwt::GBWT* gbwt = (gbwt::GBWT *)GBWT;
         gbwt::BidirectionalState* tmp = (gbwt::BidirectionalState  *) out;
         *tmp = gbwt->bdFind(node)   ;
 }

void  GBWT_BI_SEARCHSTATE_extend_forward (void* GBWT, CBidirectionalSearchState out,  CBidirectionalSearchState state, node_type node){

        gbwt::GBWT* gbwt = (gbwt::GBWT *)GBWT;
        gbwt::BidirectionalState*   tmp = ( gbwt::BidirectionalState* ) out;
        gbwt::BidirectionalState*  state1 = (gbwt::BidirectionalState*) state ;
        *tmp = gbwt->bdExtendForward ( *state1,  node)  ;
}

void  GBWT_BI_SEARCHSTATE_extend_backward (void* GBWT,  CBidirectionalSearchState out, CBidirectionalSearchState state, node_type node){
        gbwt::GBWT* gbwt = (gbwt::GBWT *)GBWT;
        gbwt::BidirectionalState*   tmp = ( gbwt::BidirectionalState* ) out;
        gbwt::BidirectionalState*  state1 = (gbwt::BidirectionalState*) state ;
        *tmp = gbwt->bdExtendBackward ( *state1,  node)  ;
        }

node_type GBWT_first_node(void* GBWT){
         gbwt::GBWT* gbwt = (gbwt::GBWT *)GBWT;
         return gbwt->firstNode();
}

size_type  GBWT_locate  (void* GBWT, node_type node, size_type i){

                gbwt::GBWT* gbwt = (gbwt::GBWT *)GBWT;
                return gbwt->locate (node, i);
        }

size_type   BI_SEARCHSTATE_size(CBidirectionalSearchState state){
        gbwt::BidirectionalState* state1 = (gbwt::BidirectionalState*) state ;
        return  state1->size();
}

bool GBWT_contains (void * GBWT,  node_type node) {
        gbwt::GBWT* gbwt = (gbwt::GBWT *) GBWT;
        return gbwt->contains(node);
}

bool GBWT_SEARCHSTATE_contains(void * GBWT,  CSearchState state) {
         gbwt::GBWT* gbwt = (gbwt::GBWT *)GBWT;
         gbwt::SearchState*  state1 = (gbwt::SearchState*) state ;
         return gbwt->contains(*state1); }

bool GBWT_edge(void * GBWT,  node_type from, node_type to)
{
         gbwt::GBWT* gbwt = (gbwt::GBWT *)GBWT;
         return gbwt->hasEdge(from,to);
}

comp_type GBWT_to_comp(void * GBWT,  node_type node){
         gbwt::GBWT* gbwt = (gbwt::GBWT *)GBWT;
         return gbwt->toComp(node);
}

node_type GBWT_to_node(void * GBWT,  comp_type comp) {
         gbwt::GBWT* gbwt = (gbwt::GBWT *)GBWT;
         return gbwt->toNode(comp);
}

size_type GBWT_node_size(void * GBWT,  node_type node) {
         gbwt::GBWT* gbwt = (gbwt::GBWT *)GBWT;
         return gbwt->nodeSize(node);
}



CPair* GBWT_edges(void * GBWT,  node_type from ){
         gbwt::GBWT* gbwt = (gbwt::GBWT *)GBWT;
         std::vector<edge_type> tmp_A = gbwt->edges(from);
         CPair* tmp_B =  (CPair*) malloc(sizeof(CPair) * tmp_A.size());

         for (size_t i=0;i != tmp_A.size(); i++)
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



gbwtSequenceSourcePair GBWTGRAPH_gfa_to_gbwt(char* gfa_filename){
        std::string cppString = gfa_filename;
        std::pair<std::unique_ptr<gbwt::GBWT>, std::unique_ptr<gbwtgraph::SequenceSource>>  tmp = gbwtgraph::gfa_to_gbwt(cppString);
        void* tmp_1 = (void*) tmp.first.release();
        void* tmp_2 =  (void*)  tmp.second.release();
        gbwtSequenceSourcePair  result;
        result.gbwt_ref = tmp_1;
        result.sequence_source_ref = tmp_2;
        return result;
}



void* SEARCHSTATE_new ()
{

        gbwt::SearchState * tmp =  (gbwt::SearchState * ) malloc(sizeof(gbwt::SearchState) );
        return  (void *) tmp;
}

void SEARCHSTATE_delete (void* state)
{
        gbwt::SearchState * tmp =  (gbwt::SearchState * ) state ;
        free(tmp)  ;
}


void* BI_SEARCHSTATE_new  ()
{

        gbwt::BidirectionalState * tmp =  (gbwt::BidirectionalState  *) malloc(sizeof(gbwt::BidirectionalState));
        return  (void *) tmp;
}

void BI_SEARCHSTATE_delete  (void* state)
{
        gbwt::BidirectionalState * tmp =  (gbwt::BidirectionalState * ) state ;
        free(tmp)  ;
}



// void (*g)() = &bar::f;


//nodes
size_type NODE_id (void* the_node,node_type the_node_type){
        gbwt::Node*  tmp_node =  (gbwt::Node*) the_node ;
        return tmp_node->id(the_node_type) ;
}

bool NODE_is_reverse (void* the_node,node_type the_node_type){

        gbwt::Node*  tmp_node =  (gbwt::Node*) the_node ;
        return tmp_node->is_reverse(the_node_type);
}
node_type NODE_encode  (void* the_node,size_type the_node_id,bool is_reversed ){
        gbwt::Node*  tmp_node =  (gbwt::Node*) the_node ;
        return tmp_node-> encode(the_node_id, is_reversed);

}
node_type NODE_reverse (void* the_node,node_type the_node_type){

        gbwt::Node*  tmp_node =  (gbwt::Node*) the_node ;
        return    tmp_node->reverse(the_node_type) ;
}



size_type PATH_id(void* path_, size_type path)     {

        gbwt::Path*  tmp_path=  (gbwt::Path*) path_;
           return tmp_path->id(path);
}
bool PATH_is_reverse(void* path_,size_type path)
{
        gbwt::Path*  tmp_path=  (gbwt::Path*) path_;

           return tmp_path->is_reverse(path);
}
size_type PATH_encode(void* path_,size_type path_id, bool reversed)

{
        gbwt::Path*  tmp_path=  (gbwt::Path*) path_;

           return tmp_path->encode(path_id, reversed);
}
size_type PATH_reverse(void* path_,size_type path)
{
        gbwt::Path*  tmp_path=  (gbwt::Path*) path_;
           return tmp_path->reverse(path);
}


void GBWT_start(void* GBWT, size_type sequence, void* return_value )  {

        gbwt::GBWT* gbwt = (gbwt::GBWT *) GBWT;
        std::pair<size_type, size_type>  start = gbwt->start(sequence);
        CPair* tmp = (CPair*) return_value;
        tmp->first =  start.first   ;
        tmp->second =  start.second ;
}

size_type GBWT_tryLocate(void* GBWT, node_type node, size_type i){
        gbwt::GBWT* gbwt = (gbwt::GBWT *) GBWT;
        return   gbwt->tryLocate(node, i);

}



//
// Sequences
// These queries convert between positions and path identifiers. Errors are expressed with invalid_edge() and invalid_sequence().
//
// edge_type start(size_type sequence) const: The position for the start of path sequence.
// size_type tryLocate(node_type node, size_type i) const: The sampled path identifier at node node, record offset i or invalid_sequence() if there is no sample.
// size_type tryLocate(edge_type position) const: As above.
//  Pages 18
// Find a Page…
// Home
// Cached GBWT
// Construction Benchmarks
// Construction Interface
// Data Model
// Data Types
// Fast Locate
// File Formats
// GBWT Merging
// Global Settings
// Haplotype Generation
// Identifiers
// Metadata
// Other Ideas
// Query Interface
// Clone this wiki locally
// https://github.com/jltsiren/gbwt.wiki.git
//
//
