#include <stdio.h>
#include <stdlib.h>


#ifndef STB_LEAKCHECK_IMPLEMENTATION
#define STB_LEAKCHECK_IMPLEMENTATION // don't implement more than once

// if we've already included leakcheck before, undefine the macros
#ifdef malloc
#undef malloc
#undef free
#undef realloc
#endif

#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
typedef struct malloc_info stb_leakcheck_malloc_info;

struct malloc_info
{
   const char *file;
   int line;
   size_t size;
   stb_leakcheck_malloc_info *next,*prev;
};

static stb_leakcheck_malloc_info *mi_head;

void *stb_leakcheck_malloc(size_t sz, const char *file, int line)
{
   stb_leakcheck_malloc_info *mi = (stb_leakcheck_malloc_info *) malloc(sz + sizeof(*mi));
   if (mi == NULL) return mi;
   mi->file = file;
   mi->line = line;
   mi->next = mi_head;
   if (mi_head)
      mi->next->prev = mi;
   mi->prev = NULL;
   mi->size = (int) sz;
   mi_head = mi;
   return mi+1;
}

void stb_leakcheck_free(void *ptr)
{
   if (ptr != NULL) {
      stb_leakcheck_malloc_info *mi = (stb_leakcheck_malloc_info *) ptr - 1;
      mi->size = ~mi->size;
      #ifndef STB_LEAKCHECK_SHOWALL
      if (mi->prev == NULL) {
         assert(mi_head == mi);
         mi_head = mi->next;
      } else
         mi->prev->next = mi->next;
      if (mi->next)
         mi->next->prev = mi->prev;
      #endif
      free(mi);
   }
}

void *stb_leakcheck_realloc(void *ptr, size_t sz, const char *file, int line)
{
   if (ptr == NULL) {
      return stb_leakcheck_malloc(sz, file, line);
   } else if (sz == 0) {
      stb_leakcheck_free(ptr);
      return NULL;
   } else {
      stb_leakcheck_malloc_info *mi = (stb_leakcheck_malloc_info *) ptr - 1;
      if (sz <= mi->size)
         return ptr;
      else {
         #ifdef STB_LEAKCHECK_REALLOC_PRESERVE_MALLOC_FILELINE
         void *q = stb_leakcheck_malloc(sz, mi->file, mi->line);
         #else
         void *q = stb_leakcheck_malloc(sz, file, line);
         #endif
         if (q) {
            memcpy(q, ptr, mi->size);
            stb_leakcheck_free(ptr);
         }
         return q;
      }
   }
}

static void stblkck_internal_print(const char *reason, const char *file,  int line, size_t size, void *ptr)
{
#if (defined(_MSC_VER) && _MSC_VER < 1900) /* 1900=VS 2015 */ || defined(__MINGW32__)
   // Compilers that use the old MS C runtime library don't have %zd
   // and the older ones don't even have %lld either... however, the old compilers
   // without "long long" don't support 64-bit targets either, so here's the
   // compromise:
   #if defined(_MSC_VER) && _MSC_VER < 1400 // before VS 2005
      printf("%-6s: %s (%4d): %8d bytes at %p\n", reason, file, line, (int)size, ptr);
   #else
      printf("%-6s: %s (%4d): %8lld bytes at %p\n", reason, file, line, (long long)size, ptr);
   #endif
#else
   // Assume we have %zd on other targets.
   printf("%-6s: %s (%4d): %zd bytes at %p\n", reason, file, line, size, ptr);
#endif
}

void stb_leakcheck_dumpmem(void)
{
   stb_leakcheck_malloc_info *mi = mi_head;
   while (mi) {
      if ((ptrdiff_t) mi->size >= 0)
      {
         stblkck_internal_print("LEAKED", mi->file, mi->line, mi->size, mi+1);
         printf("LEAKED: %s (%4d): %8d bytes at %p\n", mi->file, mi->line, (int) mi->size, mi+1);
      }
      mi = mi->next;
   }
   #ifdef STB_LEAKCHECK_SHOWALL
   mi = mi_head;
   while (mi) {
      if ((ptrdiff_t) mi->size < 0)
         stblkck_internal_print("FREED", mi->file, mi->line, ~mi->size, mi+1);
         printf("FREED : %s (%4d): %8d bytes at %p\n", mi->file, mi->line, (int) ~mi->size, mi+1);
      mi = mi->next;
   }
   #endif
}
#endif // STB_LEAKCHECK_IMPLEMENTATION

#ifndef INCLUDE_STB_LEAKCHECK_H
#define INCLUDE_STB_LEAKCHECK_H

#define malloc(sz)    stb_leakcheck_malloc(sz, __FILE__, __LINE__)
#define free(p)       stb_leakcheck_free(p)
#define realloc(p,sz) stb_leakcheck_realloc(p,sz, __FILE__, __LINE__)

extern void * stb_leakcheck_malloc(size_t sz, const char *file, int line);
extern void * stb_leakcheck_realloc(void *ptr, size_t sz, const char *file, int line);
extern void   stb_leakcheck_free(void *ptr);
extern void   stb_leakcheck_dumpmem(void);

#endif // INCLUDE_STB_LEAKCHECK_H

