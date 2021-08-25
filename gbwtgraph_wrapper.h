#include"/usr/local/include/handlegraph/types.hpp"
#include"/usr/local/include/gbwtgraph/gbwtgraph.h"
#include"/usr/local/include/gbwt/gbwt.h"
#include"gbwt_wrapper.h"


typedef long long int nid_t;

typedef gbwtgraph::handle_t handle_t;

typedef  gbwtgraph::GBWTGraph GBWTGraph;

extern "C"  int  size_of_handle_t () ;

extern "C" void get_state(handle_t  handle, CSearchState output);

extern "C" long long int GBWTGRAPH_min_node_id(void*);

extern "C" nid_t GBWTGRAPH_max_node_id(void* graph) ;

extern "C" handle_t node_to_handle (node_type node);

extern "C" node_type handle_to_node( handle_t handle );

extern "C" bool GBWTGRAPH_follow_paths (void* GBWT, CSearchState state, void* handler );// const std::function<bool(const gbwt::SearchState&)>& iteratee);

extern "C" void*  collect_handle_edges (void* graph,  handle_t& handle,bool go_left ) ;

extern "C" void*  collect_handles (void* graph,  handle_t& handle,bool parallel) ;

extern "C" int graph_size (void* v) ;

extern "C" void graph_clear(void*  v)                            ;

extern "C" void graph_consume(void* v, void* output) ;

extern "C" bool graph_pop_last (void*, handle_t*);

extern "C" bool graph_pop_front (void*, handle_t*);

extern "C" void GBWTGRAPH_find (void* graph, void* path,int path_size, void* output_state);

extern "C"  CSearchState GBWTGraph_bd_find (void* path);

extern "C" void*  gfa_to_gbwtgraph(char* file) ;

extern "C" bool graph_last_node (void*, node_type* node);

extern "C" bool graph_first_node (void*, node_type* node);

extern "C" void*  handles_to_nodes (void*);

std::vector<handle_t>*   handle_t_array_to_vector(void* array, int length  ) ;





extern "C" char*  print_nodes (void* graph,  handle_t& handle,bool parallel) ;

extern "C" void GBWTGRAPH_find_path_from_nodes (void* graph, node_type* path, int path_size, void* output_state) ;
// std::string
// GBWTGraph::get_sequence(const handle_t& handle) const
// {
//   size_t offset = this->node_offset(handle);
//   return this->sequences.str(offset);
// }

// extern "C" CSearchState GBWTGRAPH_find(char* id );
//
// extern "C" CSearchState  GBWTGRAPH_bd_find(char* id);

// /   virtual bool for_each_handle_impl(const std::function<bool(const handle_t&)>& iteratee, bool parallel = false) const;
