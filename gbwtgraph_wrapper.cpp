#include"gbwtgraph_wrapper.h"
#include <iostream>
#include <fstream>

// std::unordered_map<std::string,  std::vector <handle_t>>  dictionary ;

int handle_t_size =  sizeof(handle_t);


int  size_of_handle_t () {
        return  handle_t_size;
}


class GRAPH : public gbwtgraph::GBWTGraph{
        public:

                GRAPH(const gbwt::GBWT& gbwt_index,  const gbwtgraph::SequenceSource& sequence_source):GBWTGraph::GBWTGraph( gbwt_index,  sequence_source)   {}
                bool follow_edges  (const handle_t& handle, bool go_left, const std::function<bool(const handle_t&)>& iteratee)
                {
                        return  this->follow_edges_impl (handle, go_left, iteratee)  ;
                }

                bool for_each_handle (const std::function<bool(const handle_t&)>& iteratee, bool parallel = false)
                {
                        return this->for_each_handle_impl(iteratee,  parallel) ;

                }



};


handle_t node_to_handle(node_type node)
{
       return GBWTGraph::node_to_handle(node) ;
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


void* collect_handle_edges (void* graph,  handle_t& handle,bool go_left ){
        GRAPH*  tmp_graph = (GRAPH*)graph ;
        std::vector<handle_t>* edges =  new (std::vector<handle_t>);
        std::function<bool(const handle_t&)> iteratee =
                [&edges](handle_t handle) {
                        edges->push_back(handle) ;
                        return true;
                };
        bool is_end = tmp_graph->follow_edges(handle, go_left, iteratee);
        return (void*) edges;
}


void* collect_handles (void* graph,  handle_t& handle,bool parallel)  {
        GRAPH*  tmp_graph = (GRAPH*)graph ;
        std::vector<handle_t>*  nodes = new (std::vector<handle_t>) ;
        std::function<bool(const handle_t&)> iteratee =
                [&nodes](handle_t handle) {
                        nodes->push_back(handle) ;
                        return true;
                };


        bool is_end = tmp_graph->for_each_handle (iteratee,  parallel);
        return (void*) nodes;
}



node_type handle_to_node(handle_t handle)
{
   return  GBWTGraph::handle_to_node(handle);
}

bool graph_last_node(void* v, node_type* output)
{
        std::vector<handle_t>* tmp = (std::vector<handle_t> *) v;
        bool is_empty =   tmp->empty();
        if (is_empty)
        {

                delete  tmp;
                return !is_empty;
        }
        else{
                *output = handle_to_node (tmp->back()) ;
                tmp->pop_back();
                return !is_empty;
        }
}

bool graph_first_node (void* v, node_type* output)
{
        std::vector<handle_t>* tmp = (std::vector<handle_t> *) v;
        bool is_empty =   tmp->empty();
        if (is_empty)
        {

                delete  tmp;
                return !is_empty;
        }
        else{
                *output = handle_to_node (tmp->front()) ;
                tmp->erase(tmp->begin());
                return !is_empty;
        }

}

bool graph_pop_last(void* v, handle_t* output)
{
        std::vector<handle_t>* tmp = (std::vector<handle_t> *) v;
        *output = tmp->back() ;
        tmp->pop_back();
        bool is_empty = tmp->empty();
        if (is_empty ) {delete  tmp;}
        return !tmp->empty();
        return !is_empty;
}

bool graph_pop_front(void* v, handle_t* output)
{
        std::vector<handle_t>* tmp = (std::vector<handle_t> *) v;
        *output = tmp->front() ;
        tmp->erase(tmp->begin());
        bool is_empty = tmp->empty();
        if (is_empty ) {delete  tmp;}
        return !is_empty;
}

int graph_size (void* v)
{
        std::vector<handle_t>* tmp = (std::vector<handle_t> *) v;
        return  tmp->size() ;
}


void graph_consume(void* v, void* output)
{
        handle_t* return_value   =   (handle_t *) output;
        std::vector<handle_t>* tmp = (std::vector<handle_t> *) v;
        std::copy(tmp->begin(), tmp->end(), return_value);
}

void graph_consume_chunk(void* v, void* output, int chank_size)
{
        handle_t* return_value   =   (handle_t *) output;
        std::vector<handle_t>* tmp = (std::vector<handle_t> *) v;
        std::copy(tmp->begin(), tmp->begin() + chank_size, return_value);
        tmp->erase( tmp->begin(), tmp->begin() + chank_size ) ;
}

void graph_clear(void* v)
{

        std::vector<handle_t>* tmp = (std::vector<handle_t> *) v;
        delete  tmp;
}

void*   gfa_to_gbwtgraph (char* file){
        std::string cppString = file ;
        std::pair<std::unique_ptr<gbwt::GBWT>, std::unique_ptr<gbwtgraph::SequenceSource>>  tmp = gbwtgraph::gfa_to_gbwt(cppString);
        gbwt::GBWT* tmp_1 =  tmp.first.release();
        gbwtgraph::SequenceSource* tmp_2 =    tmp.second.release();
        GRAPH* the_graph = new GRAPH(*tmp_1, *tmp_2);
        return (void *) the_graph ;

}

std::vector<handle_t>*   handle_t_array_to_vector(void* array, int length  ) {
        handle_t *buffer =  (handle_t*) array  ;
        std::vector<handle_t>* output = new std::vector<handle_t> (buffer, buffer+length)  ;
        return   output ;
}

void GBWTGRAPH_find (void* graph, void* path, int path_size, void* output_state){
        GRAPH*  tmp_graph = (GRAPH*)graph ;
        std::vector<handle_t>* output =  handle_t_array_to_vector(path , path_size);
        gbwt::SearchState*  state = (gbwt::SearchState*)  output_state;
        *state =  tmp_graph->find(*output);
        delete output;
}


std::vector<handle_t>*   node_array_to_handle_t_vector(void* array, int length  ) {
        node_type *buffer =  (node_type*) array  ;
        std::vector<handle_t>* output = new std::vector<handle_t>; //(buffer, buffer+length)  ;
        for (int i = 0; i < length; i++) {
                output->push_back (GBWTGraph::node_to_handle(buffer[i])) ;
        }
        return   output ;
}

void GBWTGRAPH_find_path_from_nodes (void* graph, node_type* path, int path_size, void* output_state){
        GRAPH*  tmp_graph = (GRAPH*)graph ;
        std::vector<handle_t>* output =  node_array_to_handle_t_vector(path , path_size);
        gbwt::SearchState*  state = (gbwt::SearchState*)  output_state;
        *state =  tmp_graph->find(*output);
        delete output;
}




void*   handles_to_nodes (void* vec){
        std::vector<handle_t>* tmp = (std::vector<handle_t> *) vec;
        std::vector<node_type>* nodes_vec = new   std::vector<node_type>;
        for (const auto& handle  : *tmp)
        {
                nodes_vec->push_back ( GBWTGraph::handle_to_node(handle)) ;
        }

        return (void *) nodes_vec;
}





char*   print_nodes(void* graph,  handle_t& handle,bool parallel)  {
        GRAPH*  tmp_graph = (GRAPH*)graph ;
        std::string tmp_str = "";
        std::vector<handle_t>*  nodes = new (std::vector<handle_t>) ;
        std::function<bool(const handle_t&)> iteratee =
                [&tmp_str ](handle_t handle) {
                        tmp_str = tmp_str.append(" ")  + std::to_string(handle_to_node( handle ));
                        return true;
                };
        bool is_end = tmp_graph->for_each_handle (iteratee,  parallel);
        const char* pip = tmp_str.c_str();
        std::ofstream myfile ("node_list.txt");
        if (myfile.is_open())
        {
                myfile << tmp_str ;
                myfile.close();
        }
        else std::cout << "Unable to open file";


        return  (char *) pip  ;
}
