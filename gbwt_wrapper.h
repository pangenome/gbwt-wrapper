
#include<stdio.h>
#include"/usr/local/include/gbwt/utils.h"
#include"/usr/local/include/gbwt/dynamic_gbwt.h"
#include"/usr/local/include/gbwt/gbwt.h"

#include"/usr/local/include/gbwt/algorithms.h"
// typedef void * CDynamicGBWT;

typedef sdsl::int_vector<0> text_type;
typedef std::uint64_t size_type;

extern "C" void* newDynamicGBWT(void);

extern "C" void* DynamicGBWT_to_GBWT(void* dynGBWT);



extern "C" void deleteGBWT(void* GBWT);
extern "C" void  deleteDynamicGBWT(void* dynGBWT);

//methods
extern "C" void insertGBWTSequence(void*, text_type& text);

