//
// evict the least recent accessed obj, but store object using slab, if not slab automove, slab calcification can happen
//
// Created by Juncheng Yang on 04/22/20.
//

#ifndef MIMIRCACHE_SLABOBJLRU_H
#define MIMIRCACHE_SLABOBJLRU_H


#ifdef __cplusplus
extern "C"
{
#endif

  
#include "../../include/mimircache/cache.h"
#include "utilsInternal.h"
#include "slabCommon.h"


typedef struct slabObjLRU_params {
  GHashTable *hashtable;
  slab_params_t slab_params;
} slabObjLRU_params_t;


cache_t *slabObjLRU_init(common_cache_params_t ccache_params, void *cache_specific_init_params);

void slabObjLRU_free(cache_t *cache);

cache_check_result_t slabObjLRU_check(cache_t *cache, request_t *req, bool update_cache);

cache_check_result_t slabObjLRU_get(cache_t *cache, request_t *req);

void _slabObjLRU_insert(cache_t *cache, request_t *req);

void _slabObjLRU_update(cache_t *cache, request_t *req);

void _slabObjLRU_evict(cache_t *cache, request_t *req, cache_obj_t* cache_obj);


void slabObjLRU_remove_obj(cache_t *cache, void *req);


#ifdef __cplusplus
}
#endif


#endif //MIMIRCACHE_SLABOBJLRU_H