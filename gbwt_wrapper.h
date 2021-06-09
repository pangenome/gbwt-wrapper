#include "/usr/local/include/sdsl/int_vector.hpp"
#include"/usr/local/include/gbwt/dynamic_gbwt.h"
#include"/usr/local/include/gbwt/gbwt.h"


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

extern "C" void* newDynamicGBWT(void);
extern "C" void* DynamicGBWT_to_GBWT(void* dynGBWT);
extern "C" void deleteGBWT(void* GBWT);
extern "C" void deleteDynamicGBWT(void* dynGBWT);

text_type stringToText (void* text);

extern "C" void insertGBWTSequence(void* dynGBWT, text_type& text);
extern "C" void insertSequence(void* dynGBWT, void* text);

// GBWT(const DynamicGBWT& source)
// GBWT methods

extern "C" size_type total_path_length(void* GBWT);
extern "C" size_type number_of_paths(void* GBWT);
extern "C" size_type alphabet_size(void* GBWT);
extern "C" size_type number_of_samples(void* GBWT);
extern "C" size_type effective_alpahbet_size(void* GBWT);

extern "C" bool has_empty_index (void* GBWT);
extern "C" bool is_index_bidirectional(void* GBWT);
extern "C" std::pair<size_type, size_type>   number_of_gwt_runs   (void* GBWT);


