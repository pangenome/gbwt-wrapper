#include"gbwtgraph_wrapper.h"



std::unordered_map<std::string,  std::vector <handle_t>>  dictionary ;



class GRAPH : public gbwtgraph::GBWTGraph{
        public:

                bool follow_edges  (const handle_t& handle, bool go_left, const std::function<bool(const handle_t&)>& iteratee)
                {
                        return  this->follow_edges_impl (handle, go_left, iteratee)  ;
                }

                bool for_each_handle (const std::function<bool(const handle_t&)>& iteratee, bool parallel = false)
                {
                        return this->for_each_handle_impl(iteratee,  parallel) ;

                }



};



void GBWTGRAPH_node_to_handle(void* graph, node_type node,  handle_t output)
{
        gbwtgraph::GBWTGraph* tmp_graph =  ( gbwtgraph::GBWTGraph*) graph  ;
        output = tmp_graph->node_to_handle(node) ;
        // return

}


nid_t GBWTGRAPH_min_node_id(void* graph){
        GRAPH*  tmp_graph = (GRAPH*)graph ;
        return tmp_graph->min_node_id();
}


void get_state(void* graph, handle_t handle, CSearchState output)
{
        GRAPH*  tmp_graph = (GRAPH*)graph ;
        gbwt::SearchState* state_tmp  = (gbwt::SearchState *) output;
        *state_tmp = tmp_graph->get_state(handle);
}

nid_t GBWTGRAPH_max_node_id(void* graph) {

        GRAPH*  tmp_graph = (GRAPH*)graph ;
        return tmp_graph->max_node_id() ;

}


void collect_edges (void* graph,  handle_t& handle,bool go_left, char* id ){
        std::string str(id);
        GRAPH*  tmp_graph = (GRAPH*)graph ;
        std::vector<handle_t>  edges;
        std::function<bool(const handle_t&)> iteratee =
                [&edges](handle_t handle) {
                        edges.push_back(handle) ;
                        return true;
                };
        bool is_end = tmp_graph->follow_edges(handle, go_left, iteratee);
        dictionary[str] = edges;
}


// virtual bool for_each_handle_impl(const std::function<bool(const handle_t&)>& iteratee, bool parallel = false) const;

void collect_nodes (void* graph,  handle_t& handle,bool parallel, char* id )  {

        std::string str(id);
        GRAPH*  tmp_graph = (GRAPH*)graph ;
        std::vector<handle_t>  nodes;
        std::function<bool(const handle_t&)> iteratee =
                [&nodes](handle_t handle) {
                        nodes.push_back(handle) ;
                        return true;
                };

        bool is_end = tmp_graph->for_each_handle (  iteratee,  parallel);
        dictionary[str] = nodes;
}

bool graph_pop(char* id, handle_t output)
{

        std::string str(id);
        handle_t element = dictionary[str].back() ;
        output = element ;
        dictionary[str].pop_back();
        return !dictionary[str].empty();

}

bool graph_mine (char* id, int i, handle_t handle)   {
        std::string str(id);
        handle = dictionary[str][i];
        return !dictionary[str].empty();
}

void graph_clear(char* id)
{
        std::string str(id);
        dictionary[str].clear();
}

void graph_size (char* id)
{
        std::string str(id);
        dictionary[str].size();
}

// vector::clear() removes all elements.


// handle_t next_handle(void  )


//
// void* collect_edges2 (void* graph,  handle_t& handle,bool go_left ){
//
//         GRAPH*  tmp_graph = (GRAPH*)graph ;
//         std::vector<handle_t>  edges;
//         std::function<bool(const handle_t&)> iteratee =
//                 [&edges](handle_t handle) {
//                         edges.push_back(handle) ;
//                         return true;
//                 };
//
//          bool is_end = tmp_graph->follow_edges(handle, go_left, iteratee);
//          char* pipa = "fasd";
//          // return     [](int i){ return i; };
//          return lambda(float,(float x),{ return x/factor; });
// }
//
// vector::push_back() pushes elements from the back.
// vector::insert() inserts new elements to a specified location.
// vector::pop_back() removes elements from the back.
// vector::erase() removes a range of elements from a specified location.
// vector::clear() removes all elements.
