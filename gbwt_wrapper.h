#include "/usr/local/include/sdsl/int_vector.hpp"
#include"/usr/local/include/gbwt/dynamic_gbwt.h"
#include"/usr/local/include/gbwt/gbwt.h"
#include"/usr/local/include/gbwt/algorithms.h"

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
typedef std::pair<node_type, size_type>   edge_type;
typedef std::pair<rank_type, size_type>   run_type;
typedef std::pair<size_type, size_type>   sample_type;  // (i, DA[i]) within a record

extern "C" void* newDynamicGBWT(void);
extern "C" void* DynamicGBWT_to_GBWT(void* dynGBWT);
extern "C" void deleteGBWT(void* GBWT);
extern "C" void deleteDynamicGBWT(void* dynGBWT);

extern "C" void* DynamicGBWT_to_GBWT(void* dynGBWT);


text_type stringToText (void* text);

extern "C" void insertGBWTSequence(void* dynGBWT, text_type& text);
extern "C" void insertSequence(void* dynGBWT, void* text);

// GBWT(const DynamicGBWT& source)
// GBWT methods



extern "C" CSearchState  findGBWT (void* GBWT, node_type node);
extern "C"  CSearchState prefixGBWT (void* GBWT, node_type node) ;

extern "C" CBidirectionalSearchState bifindGBWT (void* GBWT, node_type node);
// extern "C" CBidirectionalSearchState insertSequence(void* dynGBWT, void* text);

// extern "C" size_type locate(node_type node, size_type i)
// extern "C" size_type locate(edge_type position)



extern "C" void*  bdExtendForwardGBWT (void* GBWT, CBidirectionalSearchState state, node_type node);

extern "C" void*  bdExtendBackwardGBWT (void* GBWT, CBidirectionalSearchState state, node_type node) ;


extern "C" uint64_t total_path_length(void* GBWT);
extern "C" uint64_t number_of_paths(void* GBWT);
extern "C" uint64_t alphabet_size(void* GBWT);
extern "C" uint64_t number_of_samples(void* GBWT);
extern "C" uint64_t effective_alpahbet_size(void* GBWT);

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


// extern "C" std::pair<size_type, size_type>   number_of_gwt_runs   (void* GBWT);

extern "C" runStats numberOfGWTRuns   (void* GBWT);


extern "C" bool has_empty_index (void* GBWT);
extern "C" bool is_index_bidirectional(void* GBWT);
// extern "C" std::pair<size_type, size_type>   number_of_gwt_runs   (void* GBWT);



extern "C" node_type  get_search_state_node(CSearchState);
extern "C" CPair get_search_state_range(CSearchState);
extern "C" CSearchState get_forward_state(CBidirectionalSearchState);
extern "C" CSearchState get_backward_state(CBidirectionalSearchState);

extern "C" size_type  get_search_state_size(CSearchState*);
extern "C" size_type get_bidirectional_state_size(CBidirectionalSearchState*);
extern "C" bool is_state_empty(void*);
extern "C" void flip_state(void*);

