#include"aword.h"
#define Ray(Red)                                                            \
  N(Red) __attribute__((section(".text." #Red))) __attribute__((noinline)); \
  N(Red) { asm("nop" : : "a"(t + a + b + ((long)o) + s)); }

Ray(Purple)
Ray(Yellow)
Ray(Green)
Ray(Red)
Ray(Blue)

N(Fuchsia) __attribute__((noinline));
N(Olive) __attribute__((noinline));
N(Lime) __attribute__((noinline));
N(Maroon) __attribute__((noinline));
N(Navy) __attribute__((noinline));
#define G(Red)                                                                    \
  N(Red##_nar) __attribute__((section(".text." #Red))) __attribute__((noinline)); \
  N(Red##_nar) { Red(t,a,b,o,s); }                                                \
  N(Red)
#define P_(...) ((void(*)(const char*,...))o[0])(__VA_ARGS__)
#define Usleep(...) ((void(*)(long))o[1])(__VA_ARGS__)
#define P(...) P_("%s ", __FUNCTION__), P_(__VA_ARGS__), Usleep(200000)
