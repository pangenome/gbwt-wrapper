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


void  node_to_handle(node_type node,  handle_t output)
{
        output = GBWTGraph::node_to_handle(node) ;
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

void graph_clear(char* id)
{
        std::string str(id);
        dictionary[str].clear();
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


void graph_size (char* id)
{
        std::string str(id);
        dictionary[str].size();
}


void graph_add (char* id)
{
        std::vector <handle_t> element  ;
        std::string str(id);
        if (dictionary.find(str) != dictionary.end())
        {
              dictionary[str].swap(element) ;
        }
        else
        {
              dictionary[str]=element;
        }
}


node_type handle_to_node(handle_t handle)
{
   return  GBWTGraph::handle_to_node(handle);
}



