#include"/usr/local/include/gbwt/utils.h"
#include"/usr/local/include/gbwt/dynamic_gbwt.h"
#include"/usr/local/include/gbwt/gbwt.h"

#include"/usr/local/include/gbwt/algorithms.h"
// typedef void * CDynamicGBWT;

typedef sdsl::int_vector<0> text_type;
typedef std::uint64_t size_type;
typedef std::uint32_t short_type;
typedef std::uint8_t  byte_type;

typedef size_type node_type;  // Node identifier.
typedef size_type comp_type;  // Record identifier, compacted node identifier.
typedef size_type rank_type;  // Rank of incoming / outgoing edge.

#ifdef GBWT_SAVE_MEMORY
typedef std::pair<short_type, short_type> edge_type;
typedef std::pair<short_type, short_type> run_type;
typedef std::pair<short_type, short_type> sample_type;  // (i, DA[i]) within a record
#else
typedef std::pair<node_type, size_type>   edge_type;
typedef std::pair<rank_type, size_type>   run_type;
typedef std::pair<size_type, size_type>   sample_type;  // (i, DA[i]) within a record
#endif
// struct SearchState
// {
//   node_type  node;
//   range_type range;
//
//   size_type size() const;
//   bool empty() const;
// };
//
// struct BidirectionalState
// {
//   SearchState forward, backward;
//
//   size_type size() const;
//   bool empty() const;
//
//   void flip();
// };


extern "C" void* newDynamicGBWT(void);

extern "C" void* DynamicGBWT_to_GBWT(void* dynGBWT);



extern "C" void deleteGBWT(void* GBWT);
extern "C" void  deleteDynamicGBWT(void* dynGBWT);

//methods
extern "C" void insertGBWTSequence(void*, text_type& text);
// GBWT(const DynamicGBWT& source)



//GBWT methods

extern "C" size_type total_path_length(void* GBWT);

extern "C" size_type number_of_paths(void* GBWT);
extern "C" size_type alphabet_size(void* GBWT);

extern "C" size_type number_of_samples(void* GBWT);

extern "C" size_type effective_alpahbet_size(void* GBWT);
extern "C" bool has_empty_index (void* GBWT);

extern "C" bool is_index_bidirectional(void* GBWT);
extern "C" std::pair<size_type, size_type>   number_of_gwt_runs   (void* GBWT);



// extern "C" bool contains(node_type node)    ;
// extern "C" bool contains(edge_type position) ;
// extern "C" bool contains(SearchState state)  ;
// extern "C" bool hasEdge(node_type from, node_type to)   ;
// extern "C" std::vector<edge_type> edges(node_type from) ;
// extern "C" node_type firstNode()    ;
// extern "C" comp_type toComp(node_type node)   k
// extern "C" node_type toNode(comp_type comp)
// extern "C" size_type nodeSize(node_type node)
// extern "C" bool empty(node_type node)
