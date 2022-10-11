#ifndef LIBROW_H
#define LIBROW_H

typedef long double ldouble;

ldouble rowNMembers(ldouble a, int n, int num_mem);

ldouble rowEpsilon(ldouble a, int n, ldouble eps, int* cnt);

#endif /* LIBROW_H */
