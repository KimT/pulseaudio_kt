
/* autogenerated from adrian-aec-orc.orc */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif
#ifndef DISABLE_ORC
#include <orc/orc.h>
#endif

#ifndef _ORC_INTEGER_TYPEDEFS_
#define _ORC_INTEGER_TYPEDEFS_
#if defined(__STDC_VERSION__) && __STDC_VERSION__ >= 199901L
#include <stdint.h>
typedef int8_t orc_int8;
typedef int16_t orc_int16;
typedef int32_t orc_int32;
typedef int64_t orc_int64;
typedef uint8_t orc_uint8;
typedef uint16_t orc_uint16;
typedef uint32_t orc_uint32;
typedef uint64_t orc_uint64;
#elif defined(_MSC_VER)
typedef signed __int8 orc_int8;
typedef signed __int16 orc_int16;
typedef signed __int32 orc_int32;
typedef signed __int64 orc_int64;
typedef unsigned __int8 orc_uint8;
typedef unsigned __int16 orc_uint16;
typedef unsigned __int32 orc_uint32;
typedef unsigned __int64 orc_uint64;
#else
#include <limits.h>
typedef signed char orc_int8;
typedef short orc_int16;
typedef int orc_int32;
typedef unsigned char orc_uint8;
typedef unsigned short orc_uint16;
typedef unsigned int orc_uint32;
#if INT_MAX == LONG_MAX
typedef long long orc_int64;
typedef unsigned long long orc_uint64;
#else
typedef long orc_int64;
typedef unsigned long orc_uint64;
#endif
#endif
typedef union { orc_int16 i; orc_int8 x2[2]; } orc_union16;
typedef union { orc_int32 i; float f; orc_int16 x2[2]; orc_int8 x4[4]; } orc_union32;
typedef union { orc_int64 i; double f; orc_int32 x2[2]; orc_int16 x4[4]; } orc_union64;
#endif

void update_tap_weights (float * d1, const float * s1, float p1, int n);


/* begin Orc C target preamble */
#define ORC_CLAMP(x,a,b) ((x)<(a) ? (a) : ((x)>(b) ? (b) : (x)))
#define ORC_ABS(a) ((a)<0 ? -(a) : (a))
#define ORC_MIN(a,b) ((a)<(b) ? (a) : (b))
#define ORC_MAX(a,b) ((a)>(b) ? (a) : (b))
#define ORC_SB_MAX 127
#define ORC_SB_MIN (-1-ORC_SB_MAX)
#define ORC_UB_MAX 255
#define ORC_UB_MIN 0
#define ORC_SW_MAX 32767
#define ORC_SW_MIN (-1-ORC_SW_MAX)
#define ORC_UW_MAX 65535
#define ORC_UW_MIN 0
#define ORC_SL_MAX 2147483647
#define ORC_SL_MIN (-1-ORC_SL_MAX)
#define ORC_UL_MAX 4294967295U
#define ORC_UL_MIN 0
#define ORC_CLAMP_SB(x) ORC_CLAMP(x,ORC_SB_MIN,ORC_SB_MAX)
#define ORC_CLAMP_UB(x) ORC_CLAMP(x,ORC_UB_MIN,ORC_UB_MAX)
#define ORC_CLAMP_SW(x) ORC_CLAMP(x,ORC_SW_MIN,ORC_SW_MAX)
#define ORC_CLAMP_UW(x) ORC_CLAMP(x,ORC_UW_MIN,ORC_UW_MAX)
#define ORC_CLAMP_SL(x) ORC_CLAMP(x,ORC_SL_MIN,ORC_SL_MAX)
#define ORC_CLAMP_UL(x) ORC_CLAMP(x,ORC_UL_MIN,ORC_UL_MAX)
#define ORC_SWAP_W(x) ((((x)&0xff)<<8) | (((x)&0xff00)>>8))
#define ORC_SWAP_L(x) ((((x)&0xff)<<24) | (((x)&0xff00)<<8) | (((x)&0xff0000)>>8) | (((x)&0xff000000)>>24))
#define ORC_SWAP_Q(x) ((((x)&0xffULL)<<56) | (((x)&0xff00ULL)<<40) | (((x)&0xff0000ULL)<<24) | (((x)&0xff000000ULL)<<8) | (((x)&0xff00000000ULL)>>8) | (((x)&0xff0000000000ULL)>>24) | (((x)&0xff000000000000ULL)>>40) | (((x)&0xff00000000000000ULL)>>56))
#define ORC_PTR_OFFSET(ptr,offset) ((void *)(((unsigned char *)(ptr)) + (offset)))
#define ORC_DENORMAL(x) ((x) & ((((x)&0x7f800000) == 0) ? 0xff800000 : 0xffffffff))
#define ORC_ISNAN(x) ((((x)&0x7f800000) == 0x7f800000) && (((x)&0x007fffff) != 0))
#define ORC_DENORMAL_DOUBLE(x) ((x) & ((((x)&0x7ff0000000000000ULL) == 0) ? 0xfff0000000000000ULL : 0xffffffffffffffffULL))
#define ORC_ISNAN_DOUBLE(x) ((((x)&0x7ff0000000000000ULL) == 0x7ff0000000000000ULL) && (((x)&0x000fffffffffffffULL) != 0))
#if defined(__STDC_VERSION__) && __STDC_VERSION__ >= 199901L
#define ORC_RESTRICT restrict
#elif defined(__GNUC__) && __GNUC__ >= 4
#define ORC_RESTRICT __restrict__
#else
#define ORC_RESTRICT
#endif
/* end Orc C target preamble */



/* update_tap_weights */
#ifdef DISABLE_ORC
void
update_tap_weights (float * d1, const float * s1, float p1, int n){
  int i;
  orc_union32 * ORC_RESTRICT ptr0;
  const orc_union32 * ORC_RESTRICT ptr4;
  orc_union32 var33;
  orc_union32 var34;
  orc_union32 var35;
  orc_union32 var36;
  orc_union32 var37;

  ptr0 = (orc_union32 *)d1;
  ptr4 = (orc_union32 *)s1;

    /* 0: loadpl */
    var33.i = p1;

  for (i = 0; i < n; i++) {
    /* 1: loadl */
    var34 = ptr4[i];
    /* 2: mulf */
    {
       orc_union32 _src1;
       orc_union32 _src2;
       orc_union32 _dest1;
       _src1.i = ORC_DENORMAL(var33.i);
       _src2.i = ORC_DENORMAL(var34.i);
       _dest1.f = _src1.f * _src2.f;
       var37.i = ORC_DENORMAL(_dest1.i);
    }
    /* 3: loadl */
    var35 = ptr0[i];
    /* 4: addf */
    {
       orc_union32 _src1;
       orc_union32 _src2;
       orc_union32 _dest1;
       _src1.i = ORC_DENORMAL(var35.i);
       _src2.i = ORC_DENORMAL(var37.i);
       _dest1.f = _src1.f + _src2.f;
       var36.i = ORC_DENORMAL(_dest1.i);
    }
    /* 5: storel */
    ptr0[i] = var36;
  }

}

#else
static void
_backup_update_tap_weights (OrcExecutor * ORC_RESTRICT ex)
{
  int i;
  int n = ex->n;
  orc_union32 * ORC_RESTRICT ptr0;
  const orc_union32 * ORC_RESTRICT ptr4;
  orc_union32 var33;
  orc_union32 var34;
  orc_union32 var35;
  orc_union32 var36;
  orc_union32 var37;

  ptr0 = (orc_union32 *)ex->arrays[0];
  ptr4 = (orc_union32 *)ex->arrays[4];

    /* 0: loadpl */
    var33.i = ex->params[24];

  for (i = 0; i < n; i++) {
    /* 1: loadl */
    var34 = ptr4[i];
    /* 2: mulf */
    {
       orc_union32 _src1;
       orc_union32 _src2;
       orc_union32 _dest1;
       _src1.i = ORC_DENORMAL(var33.i);
       _src2.i = ORC_DENORMAL(var34.i);
       _dest1.f = _src1.f * _src2.f;
       var37.i = ORC_DENORMAL(_dest1.i);
    }
    /* 3: loadl */
    var35 = ptr0[i];
    /* 4: addf */
    {
       orc_union32 _src1;
       orc_union32 _src2;
       orc_union32 _dest1;
       _src1.i = ORC_DENORMAL(var35.i);
       _src2.i = ORC_DENORMAL(var37.i);
       _dest1.f = _src1.f + _src2.f;
       var36.i = ORC_DENORMAL(_dest1.i);
    }
    /* 5: storel */
    ptr0[i] = var36;
  }

}

void
update_tap_weights (float * d1, const float * s1, float p1, int n)
{
  OrcExecutor _ex, *ex = &_ex;
  static int p_inited = 0;
  static OrcProgram *p = 0;
  void (*func) (OrcExecutor *);

  if (!p_inited) {
    orc_once_mutex_lock ();
    if (!p_inited) {
      OrcCompileResult result;

      p = orc_program_new ();
      orc_program_set_name (p, "update_tap_weights");
      orc_program_set_backup_function (p, _backup_update_tap_weights);
      orc_program_add_destination (p, 4, "d1");
      orc_program_add_source (p, 4, "s1");
      orc_program_add_constant (p, 0, 0x00000000, "c1");
      orc_program_add_constant (p, 0, 0x00000000, "c2");
      orc_program_add_constant (p, 0, 0x00000000, "c3");
      orc_program_add_constant (p, 0, 0x00000000, "c4");
      orc_program_add_constant (p, 0, 0x00000000, "c5");
      orc_program_add_constant (p, 0, 0x00000000, "c6");
      orc_program_add_constant (p, 0, 0x00000000, "c7");
      orc_program_add_constant (p, 0, 0x00000000, "c8");
      orc_program_add_parameter_float (p, 4, "p1");
      orc_program_add_temporary (p, 4, "t1");

      orc_program_append_2 (p, "mulf", 0, ORC_VAR_T1, ORC_VAR_P1, ORC_VAR_S1, ORC_VAR_D1);
      orc_program_append_2 (p, "addf", 0, ORC_VAR_D1, ORC_VAR_D1, ORC_VAR_T1, ORC_VAR_D1);

      result = orc_program_compile (p);
    }
    p_inited = TRUE;
    orc_once_mutex_unlock ();
  }
  ex->program = p;

  ex->n = n;
  ex->arrays[ORC_VAR_D1] = d1;
  ex->arrays[ORC_VAR_S1] = (void *)s1;
  {
    orc_union32 tmp;
    tmp.f = p1;
    ex->params[ORC_VAR_P1] = tmp.i;
  }

  func = p->code_exec;
  func (ex);
}
#endif
