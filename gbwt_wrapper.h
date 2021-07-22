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
void insertGBWTSequence(void* dynGBWT, text_type& text);

extern "C" void DGBWT_insert(void* dynGBWT, void* text);

// GBWT methods

extern "C" node_type   GBWT_first_node(void* GBWT);


extern "C"  CSearchState  GBWT_find (void* GBWT, node_type node);
extern "C"  CSearchState  GBWT_extend (void* GBWT,  CSearchState state, node_type node);

extern "C"  size_type GBWT_locate (void* GBWT,  node_type node, size_type i)   ;


extern "C" CBidirectionalSearchState biGBWT_find (void* GBWT, node_type node);
extern "C" void*  bdExtendForwardGBWT (void* GBWT, CBidirectionalSearchState state, node_type node);
extern "C" void*  bdExtendBackwardGBWT (void* GBWT, CBidirectionalSearchState state, node_type node) ;

extern "C" uint64_t GBWT_total_path_length(void* GBWT);
extern "C" uint64_t GBWT_number_of_paths(void* GBWT);
extern "C" uint64_t GBWT_alphabet_size(void* GBWT);
extern "C" uint64_t GBWT_number_of_samples(void* GBWT);
extern "C" uint64_t GBWT_effective_alphabet_size(void* GBWT);

extern "C" bool has_empty_index (void* GBWT);
extern "C" bool is_index_bidirectional(void* GBWT);

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

extern "C" runStats numberOfGWTRuns   (void* GBWT);

extern "C" bool has_empty_index (void* GBWT);
extern "C" bool is_index_bidirectional(void* GBWT);


extern "C" node_type  GBWT_get_search_state_node(CSearchState);
extern "C" CPair GBWT_get_search_state_range(CSearchState);
extern "C" CSearchState GBWT_get_forward_state(CBidirectionalSearchState);
extern "C" CSearchState GBWT_get_backward_state(CBidirectionalSearchState);

extern "C" size_type  GBWT_get_search_state_size(CSearchState);

extern "C" bool GBWT_get_bidirectional_state_size(CBidirectionalSearchState state);
extern "C" bool GBWT_is_search_state_empty(void*);
extern "C" void GBWT_flip_state(void*);



// Node statistics

//   std::vector<double> v;
// double* a = &v[0];
//

extern "C" bool GBWT_contains_node (void * GBWT, node_type node);
extern "C" bool GBWT_contains_edge(void * GBWT,  CPair position);
extern "C" bool GBWT_contains_search_state(void * GBWT,  CSearchState state);
extern "C" bool GBWT_has_edge(void * GBWT,  node_type from, node_type to);


// typedef std::pair<node_type, size_type>   edge_type;

// std::vector<edge_type> edges(node_type from) const: Returns the edges from node from.


extern "C" CPair* GBWT_edges(void * GBWT,  node_type from );

// extern "C" CPair (CSearchState);
extern "C" comp_type GBWT_to_comp(void * GBWT,  node_type node);
extern "C" node_type GBWT_to_node(void * GBWT,  comp_type comp);
extern "C" size_type GBWT_node_size(void * GBWT,  node_type node);


extern "C" CPair GBWT_LF_next_node_from_offset (void * GBWT, node_type from, size_type i);
extern "C" CPair GBWT_LF_next_node_from_edge(void * GBWT, CPair position);
extern "C" size_type GBWT_LF_next_offset_from_node(void * GBWT, node_type from, size_type i, node_type to);
extern "C" size_type GBWT_LF_next_offset_from_position (void * GBWT, CPair position, node_type to);
extern "C" CPair GBWT_LF_range_of_successors_from_node(void * GBWT, node_type from, CPair  range, node_type to);
extern "C" CPair GBWT_LF_range_of_successors_from_search_state(void * GBWT, CSearchState state, node_type to);

extern "C" char*  debug(void);
//  const std::string&

//  parameters = GFAParsingParameters()

extern "C" gbwtSequenceSourcePair  GBWTGRAPH_gfa_to_gbwt(char* gfa_filename  );

// std::pair<std::unique_ptr<gbwt::GBWT>, std::unique_ptr<SequenceSource>> gfa_to_gbwt(const std::string& gfa_filename, const GFAParsingParameters& parameters = GFAParsingParameters());


