#include"/usr/local/include/handlegraph/types.hpp"
#include"/usr/local/include/gbwtgraph/gbwtgraph.h"
#include"/usr/local/include/gbwt/gbwt.h"
#include"gbwt_wrapper.h"




typedef long long int nid_t;


typedef gbwtgraph::handle_t handle_t;
typedef  gbwtgraph::GBWTGraph GBWTGraph;

extern "C"  int  size_of_handle_t (handle_t handle) ;

extern "C" void get_state(handle_t  handle, CSearchState output);

extern "C" long long int GBWTGRAPH_min_node_id(void*);

extern "C" void  GBWTGRAPH_node_to_handle(void* gbwtgraph, node_type node, handle_t output  );

extern "C" nid_t GBWTGRAPH_max_node_id(void* graph) ;

extern "C" void  GBWTGRAPH_find(void* graph, handle_t handle, CSearchState output);

extern "C" void  GBWTGRAPH_bd_find(void* graph, handle_t handle, CSearchState output);


extern "C" void GBWTGRAPH_node_to_handle(void* gbwtgraph, node_type node, handle_t output );

extern "C" bool GBWTGRAPH_follow_paths (void* GBWT, CSearchState state, void* handler );// const std::function<bool(const gbwt::SearchState&)>& iteratee);

extern "C" void* collect_edges(void* GBWT,  const handle_t& handle ) ;

extern "C" void graph_size (char* id)                            ;

extern "C" void graph_clear(char* id)                            ;

extern "C" bool graph_mine (char* id, int i, handle_t handle)     ;

extern "C" bool graph_pop(char* id, handle_t output);




// /   virtual bool for_each_handle_impl(const std::function<bool(const handle_t&)>& iteratee, bool parallel = false) const;
