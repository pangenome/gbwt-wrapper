#include"/usr/local/include/gbwt/utils.h"
#include"/usr/local/include/gbwt/dynamic_gbwt.h"


typedef void* CDynamicGBWT;

extern "C" CDynamicGBWT  newDynamicGBWT(void);
extern "C" void  deleteDynamicGBWT(CDynamicGBWT dynGBWT);


extern "C" void insertGBWTSequence(CDynamicGBWT  dynGBWT, const text_type& text, bool has_both_orientations = false, size_type sample_interval = SAMPLE_INTERVAL) ;



