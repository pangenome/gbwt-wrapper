#include "/usr/local/include/sdsl/int_vector.hpp"
#include"/usr/local/include/gbwt/dynamic_gbwt.h"
#include"/usr/local/include/gbwt/gbwt.h"
#include"/usr/local/include/gbwt/algorithms.h"
// #include"/usr/local/include/gbwtgraph/gbwtgraph.h"

#include"/usr/local/include/gbwtgraph/gfa.h"

typedef sdsl::int_vector<0> text_type;
typedef uint64_t size_type;
typedef uint32_t short_type;
typedef uint8_t  byte_type;

typedef size_type node_type;  // Node identifier.
typedef size_type comp_type;  // Record identifier, compacted node identifier.
typedef size_type rank_type;  // Rank of incoming / outgoing edge.

typedef void* CSearchState ;

typedef void* CBidirectionalSearchState ;

typedef std::pair<node_type, size_type>   range_type;

#ifdef GBWT_SAVE_MEMORY
typedef std::pair<short_type, short_type> edge_type;
typedef std::pair<short_type, short_type> run_type;
typedef std::pair<short_type, short_type> sample_type;  // (i, DA[i]) within a record
#else
typedef std::pair<node_type, size_type>   edge_type;
typedef std::pair<rank_type, size_type>   run_type;
typedef std::pair<size_type, size_type>   sample_type;  // (i, DA[i]) within a record
#endif


extern "C" void* DGBWT_new(void);
extern "C" void* DGBWT_to_GBWT(void* dynGBWT);
extern "C" void GBWT_delete(void* GBWT);
extern "C" void DGBWT_delete(void* dynGBWT);
extern "C" void* DGBWT_to_GBWT(void* dynGBWT);

text_type stringToText (void* text);
void* insertGBWTSequence(void* dynGBWT, text_type& text);

extern "C" void* DGBWT_insert(void* dynGBWT, void* text);
extern "C" node_type   GBWT_first_node(void* GBWT);
extern "C" void  GBWT_find (void* GBWT, CSearchState out,  node_type node);
extern "C" void GBWT_bi_find (void* GBWT,  CBidirectionalSearchState out,node_type node);
extern "C" void  GBWT_SEARCHSTATE_extend   (void* GBWT,  CSearchState  out , CSearchState state, node_type node);
extern "C" void  GBWT_BI_SEARCHSTATE_extend_forward (void* GBWT, CBidirectionalSearchState out,  CBidirectionalSearchState state, node_type node);
extern "C" void  GBWT_BI_SEARCHSTATE_extend_backward (void* GBWT,  CBidirectionalSearchState out, CBidirectionalSearchState state, node_type node);

extern "C"  size_type GBWT_locate (void* GBWT,  node_type node, size_type i)   ;



struct CPair {
        uint64_t first;
        uint64_t second;
};

struct runStats{
        uint64_t concreteRuns;
        uint64_t logicalRuns;
};

struct refPair{
   void* first;
   void* second;
};


struct gbwtSequenceSourcePair{
   void* gbwt_ref;
   void* sequence_source_ref;
};






extern "C" runStats GBWT_runs   (void* GBWT);
extern "C" uint64_t GBWT_size(void* GBWT);
extern "C" uint64_t GBWT_sequences(void* GBWT);
extern "C" uint64_t GBWT_sigma(void* GBWT);
extern "C" uint64_t GBWT_samples(void* GBWT);
extern "C" uint64_t GBWT_effective(void* GBWT);
// extern "C" size_type  GBWT_effective (void* GBWT) ;
extern "C" bool GBWT_empty (void* GBWT);
extern "C" bool GBWT_bidirectional(void* GBWT);



//Funcitons operating on search states
extern "C" node_type  SEARCHSTATE_node(CSearchState);
extern "C" CPair  SEARCHSTATE_range(CSearchState);
extern "C" void  BI_SEARCHSTATE_forward (CBidirectionalSearchState, CBidirectionalSearchState);
extern "C" void   BI_SEARCHSTATE_backward(CBidirectionalSearchState, CBidirectionalSearchState);
extern "C" size_type SEARCHSTATE_size(CSearchState);
extern "C" size_type BI_SEARCHSTATE_size(CBidirectionalSearchState state);
extern "C" bool SEARCHSTATE_empty(CSearchState state);
extern "C" void  SEARCHSTATE_flip (void*);
extern "C" bool GBWT_SEARCHSTATE_contains(void * GBWT,  CSearchState state);




extern "C" bool GBWT_contains (void * GBWT, node_type node);
extern "C" bool GBWT_contains_edge(void * GBWT,  CPair position);
extern "C" bool GBWT_edge(void * GBWT,  node_type from, node_type to);
extern "C" comp_type GBWT_to_comp(void * GBWT,  node_type node);
extern "C" node_type GBWT_to_node(void * GBWT,  comp_type comp);
extern "C" size_type GBWT_node_size(void * GBWT,  node_type node);


extern "C" CPair GBWT_LF_next_node_from_offset (void * GBWT, node_type from, size_type i);
extern "C" CPair GBWT_LF_next_node_from_edge(void * GBWT, CPair position);
extern "C" size_type GBWT_LF_next_offset_from_node(void * GBWT, node_type from, size_type i, node_type to);
extern "C" size_type GBWT_LF_next_offset_from_position (void * GBWT, CPair position, node_type to);
extern "C" CPair GBWT_LF_range_of_successors_from_node(void * GBWT, node_type from, CPair  range, node_type to);
extern "C" CPair GBWT_LF_range_of_successors_from_search_state(void * GBWT, CSearchState state, node_type to);

//NODES


extern "C" size_type NODE_id (void*,node_type) ;
extern "C" bool NODE_is_reverse (void*,node_type) ;
extern "C" node_type NODE_encode  (void*,size_type,bool)   ;
extern "C" node_type NODE_reverse (void*,node_type) ;

//PATHS
extern "C" size_type PATH_id(void* path_, size_type path) ;
extern "C" bool PATH_is_reverse(void* path_,size_type path) ;
extern "C" size_type PATH_encode(void* path_,size_type path_id, bool reversed);
extern "C" size_type PATH_reverse(void* path_,size_type path) ;

extern "C" gbwtSequenceSourcePair  GBWTGRAPH_gfa_to_gbwt(char* gfa_filename  );

extern "C" int SEARCHSTATE_sizeof (void);

extern "C" int BI_SEARCHSTATE_sizeof (void);

extern "C" void* SEARCHSTATE_new (void);

extern "C" void   SEARCHSTATE_delete (void*);

extern "C" void*  BI_SEARCHSTATE_new(void);

extern "C" void  BI_SEARCHSTATE_delete (void*);

// extern "C" bool GBWT_is_index_bidirectional(void* GBWT);

