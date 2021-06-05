#include"/usr/local/include/gbwt/utils.h"
#include"/usr/local/include/gbwt/dynamic_gbwt.h"


// typedef void * CDynamicGBWT;


typedef sdsl::int_vector<0> text_type;

extern "C" void * newDynamicGBWT(void);
extern "C" void  deleteDynamicGBWT(void* dynGBWT);

extern "C" void insertGBWTSequence(void*, text_type& text);


