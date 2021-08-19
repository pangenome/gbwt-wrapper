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

extern "C" nid_t GBWTGRAPH_max_node_id(void* graph) ;

extern "C" void node_to_handle (node_type node, handle_t output );

extern "C" node_type handle_to_node( handle_t handle );

extern "C" bool GBWTGRAPH_follow_paths (void* GBWT, CSearchState state, void* handler );// const std::function<bool(const gbwt::SearchState&)>& iteratee);

extern "C" void  collect_edges(void* graph,  handle_t& handle,bool go_left, char* id ) ;

extern "C" void  collect_nodes(void* graph,  handle_t& handle,bool parallel, char* id ) ;

extern "C" void graph_size (char* id)                            ;

extern "C" void graph_clear(char* id)                            ;

extern "C" bool graph_mine (char* id, int i, handle_t handle)     ;

extern "C" bool graph_pop(char* id, handle_t output);

// extern "C" CSearchState GBWTGRAPH_find(char* id );
//
// extern "C" CSearchState  GBWTGRAPH_bd_find(char* id);

// /   virtual bool for_each_handle_impl(const std::function<bool(const handle_t&)>& iteratee, bool parallel = false) const;
