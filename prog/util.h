#ifndef UTIL_H__
#define UTIL_H__



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>
#include <float.h>
#include <math.h>



/* Numerical constants
 * default units:
 * length: angstrom
 * energy: kJ
 * */



#define PI          3.14159265358979323846
#define INFTY       1e30

#define CAL_TO_J    4.184               /* from calories to joules */
#define J_TO_CAL    (1./CAL_TO_J)       /* from joules to calories */
#define CAL_TO_KJ   (CAL_TO_J*1e-3)     /* from calories to kilo joules */
#define J_TO_KCAL   (J_TO_CAL*1e-3)     /* from joules to kilo calories */
#define KCAL_TO_J   (CAL_TO_J*1e3)      /* from kilo calories to joules */
#define KJ_TO_CAL   (J_TO_CAL*1e3)      /* from kilo joules to calories */
#define NA          6.02214129e23       /* Avogadro constant in mol^{-1} */
#define EC          1.602176565e-19     /* elementary charge in A*s */
#define EPS0_SI     8.854187817620e-12  /* vacuum permittivity in A^2*s^4/kg/m^3 */

#define KB_SI       1.3806488e-23       /* Boltzmann constant in m^2*kg/s^2/K = J/K */
#define KB_KJ       (KB_SI*0.001)       /* Boltzmann constant in kJ/K, 1.3806488e-26 */
#define KB_J        (KB_SI)             /* Boltzmann constant in J/K, 1.3806488e-23 */
#define KB_ERG      (KB_SI*1e7)         /* Boltzmann constant in erg/K, 1.3806488e-16 */
#define KB_KCAL     (KB_KJ*J_TO_CAL)    /* Boltzmann constant in kcal/K, 3.29982982791587e-27 */
#define KB_CAL      (KB_J*J_TO_CAL)     /* Boltzmann constant in cal/K, 3.29982982791587e-24 */
#define KB          (KB_KJ)             /* Boltzmann constant in the default unit */

#define KBNA_SI     (KB_SI*NA)          /* Boltzmann constant in J/mol/K, 8.31446214547 */
#define KBNA_KJ     (KB_KJ*NA)          /* Boltzmann constant in kJ/mol/K, 0.00831446214547 */
#define KBNA_J      (KBNA_SI)           /* Boltzmann constant in J/mol/K, 8.31446214547 */
#define KBNA_ERG    (KBNA_SI*1e7)       /* Boltzmann constant in erg/mol/K, 8.31446214547e7 */
#define KBNA_KCAL   (KBNA_KJ*J_TO_CAL)  /* Boltzmann constant in kcal/mol/K, 0.00198720414667 */
#define KBNA_CAL    (KBNA_J*J_TO_CAL)   /* Boltzmann constant in cal/mol/K, 1.98720414667 */
#define KBNA        (KBNA_KJ)           /* Boltzmann constant in the default unit */
#define KBNAC       (KBNA_KCAL)

#define KC_SI       (1/(4*PI*EPS0_SI))  /* 1 / (4 PI EPS0) in kg*m^3/A^2/s^4 = J*m/A^2/s^2, 8.9875517873686e9 */

#define KE2_SI      (KC_SI*EC*EC)       /* e^2 / (4 PI EPS0) in m*J, 2.3070773523707e-28 */
#define KE2_AKJ     (KE2_SI*1e7)        /* e^2 / (4 PI EPS0) in angstrom*kJ, 2.3070773523707e-21 */
#define KE2_AJ      (KE2_SI*1e10)       /* e^2 / (4 PI EPS0) in angstrom*J, 2.3070773523707e-18 */
#define KE2_AERG    (KE2_SI*1e17)       /* e^2 / (4 PI EPS0) in angstrom*erg, 2.3070773523707e-11 */
#define KE2_AKCAL   (KE2_AKJ*J_TO_CAL)  /* e^2 / (4 PI EPS0) in angstrom*kcal, 5.514047209298996e-22 */
#define KE2_ACAL    (KE2_AJ*J_TO_CAL)   /* e^2 / (4 PI EPS0) in angstrom*cal, 5.514047209298996e-19 */
#define KE2         (KE2_AKJ)

#define KE2NA_SI    (KE2_SI*NA)         /* e^2 / (4 PI EPS0) * NA in m*J/mol, 1.389354578e-7 */
#define KE2NA_AKJ   (KE2_AKJ*NA)        /* e^2 / (4 PI EPS0) * NA in angstrom*kJ/mol, 1389.354578 */
#define KE2NA_AJ    (KE2_AJ*NA)         /* e^2 / (4 PI EPS0) * NA in angstrom*J/mol, 1.389354578e6 */
#define KE2NA_AERG  (KE2_AERG*NA)       /* e^2 / (4 PI EPS0) * NA in angstrom*J/mol, 1.389354578e13 */
#define KE2NA_AKCAL (KE2_AKCAL*NA)      /* e^2 / (4 PI EPS0) * NA in angstrom*kcal/mol, 322.0637137 */
#define KE2NA_ACAL  (KE2_ACAL*NA)       /* e^2 / (4 PI EPS0) * NA in angstrom*cal/mol, 3.220637137e5 */
#define KE2NA       (KE2NA_AKJ)         /* e^2 / (4 PI EPS0) * NA in the default unit */
#define KE2NAC      (KE2NA_AKCAL)

#define KE2PK_SI    (KE2_SI/KB_SI)      /* e^2/(4 Pi EPS0)/kB in m*K, 1.671009566e-5 */
#define KE2PK_A     (KE2PK_SI*1e10)     /* e^2/(4 Pi EPS0)/kB in angstrom*K, 167100.9566 */
#define KE2PK       (KE2PK_A)           /* e^2/(4 Pi EPS0)/kB in the default unit */

#define ERG_TO_J          (1e-7)              /* 1e-7 */
#define ERG_TO_CAL        (1e-7*J_TO_CAL)     /* 2.390057361376673e-8 */
#define ERG_TO_KJ         (1e-10)             /* 1e-10 */
#define ERG_TO_KCAL       (1e-10*J_TO_CAL)    /* 2.390057361376673e-11 */
#define ERG_TO_JPMOL      (NA*1e-7)           /* 6.02214129e16 */
#define ERG_TO_CALPMOL    (NA*1e-7*J_TO_CAL)  /* 1.43932631214914e16 */
#define ERG_TO_KJPMOL     (NA*1e-10)          /* 6.02214129e13 */
#define ERG_TO_KCALPMOL   (NA*1e-10*J_TO_CAL) /* 1.43932631214914e13 */

#define J_TO_ERG          (1/ERG_TO_J)        /* 1e7 */
#define CAL_TO_ERG        (1/ERG_TO_CAL)      /* 4.184e7 */
#define KJ_TO_ERG         (1/ERG_TO_KJ)       /* 1e10 */
#define KCAL_TO_ERG       (1/ERG_TO_KCAL)     /* 4.184e10 */
#define JPMOL_TO_ERG      (1/ERG_TO_JPMOL)    /* 1.66053892103219e-17 */
#define CALPMOL_TO_ERG    (1/ERG_TO_CALPMOL)  /* 6.947694845598683e-17 */
#define KJPMOL_TO_ERG     (1/ERG_TO_KJPMOL)   /* 1.66053892103219e-14 */
#define KCALPMOL_TO_ERG   (1/ERG_TO_KCALPMOL) /* 6.947694845598683e-14 */



/* Memory allocation routines */


#ifndef xnew
#define xnew(x, n) { \
  if ((x = calloc(n, sizeof(*(x)))) == NULL) { \
    fprintf(stderr, "no memory for %s x %d\n", #x, (int) (n)); \
    exit(1); } }
#endif

/* copy array */
#define cparr(x, y, n) { int i_; \
  for ( i_ = 0; i_ < n; i_++ ) x[i_] = y[i_]; }

/* allocate a two-dimensional array */
#define newarr2d(x, m, n) { int j_; \
  x = malloc(sizeof(x[0]) * m); \
  for ( j_ = 0; j_ < m; j_++ ) newarr( x[j_], n ); }

/* free a two-dimensional array */
#define delarr2d(x, m) { int j_; \
  for ( j_ = 0; j_ < m; j_++ ) delarr( x[j_] ); \
  free(x); x = NULL; }

/* copy array */
#define cparr2d(x, y, m, n) { int j_; \
  for ( j_ = 0; j_ < m; j_++ ) cparr(x[j_], y[j_], n); }





/* FFTW routines */



double *fft_arr;
double *fft_ri, *fft_ki;
double fft_dr, fft_dk;
int fft_npt;



#ifndef NOFFTW



#include <fftw3.h>
fftw_plan fftwplan;



#define newarr(x, n) { int i_; \
  (x) = (double *) fftw_malloc(sizeof((x)[0]) * n); \
  for ( i_ = 0; i_ < n; i_++ ) (x)[i_] = 0; }

#define delarr(x) fftw_free(x)



#else /* NOFFTW is defined, use the home-made version */



#define newarr(x, n) x = calloc(n, sizeof(x[0]))
#define delarr(x) free(x)



/* Description:
 *   replace the complex array a[] by their discrete fast Fourier transform
 *
 * Parameter:
 *   o a[] is both the input and the output
 *   o a[i*2] and a[i*2+1] are the real and complex parts, respectively
 *   o n must be a power of 2
 *   o if sign is 1, do fast Fourier transform,
 *     if sign is 0 or -1, do the inverse transform
 *
 * Return:
 *   on success, returns 0;
 *   if n isn't an integer power of 2, returns 1
 */
static int fft(double a[], int n, int sign)
{
  double s, c, bs, bsh, bcb, bth = PI, tmpre, tmpim, tmp;
  int gaddr, gspan = 1; /* gaddr is the starting index of each group */
  int coupid, coups;  /* coups is how many couples in each group */
  int i, j, m;

  /* check if n is an integer power of 2 */
  for (m = n; (m & 1) == 0; m >>= 1) ;
  if (m > 1) {
    fprintf(stderr, "n %d is not a power of 2\n", n);
    exit(1);
  }

  if (sign > 0) bth = -bth;

  j = 0;
  /* bit reversal */
  for (i = 1; i < n - 1; i++) {
    m = n >> 1;
    while (j >= m) {
      j -= m;
      m >>= 1;
    }
    j += m;
    if (j > i) {
      tmp = a[i*2]; a[i*2] = a[j*2]; a[j*2] = tmp;
      tmp = a[i*2+1]; a[i*2+1] = a[j*2+1]; a[j*2+1] = tmp;
    }
  }

  /* Danielson and Lanczos */
  bsh = 0;
  while (n > gspan) {
    bs = bsh;
    bsh = sin(bth / 2);
    bcb = 2*bsh*bsh;
    c = 1;
    s = 0;
    coups = gspan;
    gspan *= 2;
    /* for each couple
     * NOTE: the value of bth (its sine and also its cosine) is only
     * relevant to the couple id, that means, two couples with a same
     * couple id will share a same theta */
    for (coupid = 0; coupid < coups; coupid++) {
      /* for each group */
      for (gaddr = 0; gaddr < n; gaddr += gspan) {
        i = gaddr + coupid; j = i + coups;
        /* calculate this couple by following formula
         * ai = ai + aj * (c + s i);
         * aj = ai - aj * (c + s i);
         */
        tmpre = a[j*2]*c - a[j*2+1]*s;
        tmpim = a[j*2]*s + a[j*2+1]*c;
        a[j*2] = a[i*2] - tmpre;
        a[i*2] += tmpre;
        a[j*2+1] = a[i*2+1] - tmpim;
        a[i*2+1] += tmpim;
      }
      /* deal next couple, increase  cosine and sine by
       * cos(a+b) = cos(a)*cos(b) - sin(a)*sin(b);
       * sin(a+b) = sin(a)*cos(b) + cos(a)*sin(b);
       * but when b is very small(when n is a very large number),
       * cos(b) will be very close to 1 and inaccurate,
       * so we replace these formulae by introduce bcb = 1-cos(b) = 2*sin(b/2)*sin(b/2),
       * -- a relatively small number,
       * cos(a+b) = cos(a) + (cos(a)*(-bcb) - sin(a)*sin(b));
       * sin(a+b) = sin(a) + (sin(a)*(-bcb) + cos(a)*sin(b));
       */
      c += -(tmp = c)*bcb - s*bs;
      s += -s*bcb + tmp*bs;
    } /* end for each couple */
    bth /= 2;
  }
  return 0;
}



double *sint_arr;

/* sine transform, return \int 2 * sin(k x) a(x) dx */
__inline static int sint11(double a[], int n)
{
  int err, i;
  double c, s, th, c1, s1, tmp;

  th = PI/(2*n);
  c1 = cos(th);
  s1 = sin(th);
  th /= 2;
  c = cos(th);
  s = sin(th);
  for (i = 0; i < n; i++) {
    /* c = cos(PI*(i+.5)/(2*n)); s = sin(PI*(i+.5)/(2*n)); */
    sint_arr[i*2] = a[i] * c;
    sint_arr[(2*n-1-i)*2] = -sint_arr[i*2];
    sint_arr[i*2+1] = a[i] * s;
    sint_arr[(2*n-1-i)*2+1] = sint_arr[i*2+1];
    tmp = c * c1 - s * s1;
    s = s * c1 + c * s1;
    c = tmp;
  }
  err = fft(sint_arr, 2 * n, 0);
  c = 1;
  s = 0;
  for (i = 0; i < n; i++) {
    /* c = cos(PI*i/(2*n)); s = sin(PI*i/(2*n)); */
    /* re' = re * c - im * s; im' = re * s + im * c; */
    a[i] = sint_arr[i*2] * s + sint_arr[i*2+1] * c;
    tmp = c * c1 - s * s1;
    s = s * c1 + c * s1;
    c = tmp;
  }
  return err;
}



#endif



/* initialize FFT */
static void initfft(double rmax, int npt)
{
  int i;

  fft_npt = npt;
  fft_dr = rmax / npt;
  fft_dk = (2*PI) / (2*npt*fft_dr);
  newarr(fft_arr, npt);
  newarr(fft_ri, npt);
  newarr(fft_ki, npt);
  for ( i = 0; i < npt; i++ ) {
    fft_ri[i] = (i + .5) * fft_dr;
    fft_ki[i] = (i + .5) * fft_dk;
  }
#ifndef NOFFTW
  fftwplan = fftw_plan_r2r_1d(npt, fft_arr, fft_arr,
      FFTW_RODFT11, FFTW_ESTIMATE);
  if ( fftwplan == NULL ) exit(1);
#else
  newarr(sint_arr, 4*npt);
#endif
}



/* clean up FFT */
static void donefft(void)
{
  delarr(fft_arr);
  free(fft_ri);
  free(fft_ki);
#ifndef NOFFTW
  fftw_destroy_plan(fftwplan);
  fftw_cleanup();
#else
  delarr(sint_arr);
#endif
}



/* c(r) --> c(k)
 * c(k) = 2 Pi/k Int 2 r c(r) sin(kr) dr */
#define sphr_r2k(cr, ck, ns, prmask) \
  sphrt(cr, ck, fft_ri, fft_ki, fft_dr*(2*PI), ns, prmask)

/* t(k) --> t(r)
 * t(r) = 2 Pi/r/(2 Pi)^3 Int 2 k t(k) sin(kr) dk */
#define sphr_k2r(tk, tr, ns, prmask) \
  sphrt(tk, tr, fft_ki, fft_ri, fft_dk/(4*PI*PI), ns, prmask)

/* f(k) = fac/k Int 2 r f(r) sin(kr) dr */
static void sphrt(double **fr, double **fk,
    const double *ri, const double *ki, double fac,
    int ns, const int *prmask)
{
  int i, j, ij, l;

  for ( i = 0; i < ns; i++ ) {
    for ( j = i; j < ns; j++ ) {
      ij = i * ns + j;
      if ( prmask && !prmask[ij] ) continue;
      for ( l = 0; l < fft_npt; l++ )
        fft_arr[l] = fr[ij][l] * ri[l];
#ifdef NOFFTW
      sint11(fft_arr, fft_npt);
#else
      fftw_execute(fftwplan);
#endif
      for ( l = 0; l < fft_npt; l++ ) {
        fk[ij][l] = fft_arr[l] * fac / ki[l];
        if ( j > i ) fk[j*ns + i][l] = fk[ij][l];
      }
    }
  }
}









/* Linear algebra routines */



/* multiply two matrices c = a * b */
static double *matmul(double *c, const double *a, const double *b, int n)
{
  int i, j, k;
  double x;

  for ( i = 0; i < n; i++ )
    for ( j = 0; j < n; j++ ) {
      x = 0;
      for ( k = 0; k < n; k++ )
        x += a[i*n + k] * b[k*n + j];
      c[i*n + j] = x;
    }
  return c;
}



/* compute the inverse matrix b = a^(-1), by Gaussian elimination */
static int invmat(double *a, double *b, int n)
{
  int i, j, k, ip;
  double x;

  /* initialize b as the identity matrix */
  for ( i = 0; i < n; i++ )
    for ( j = 0; j < n; j++ )
      b[i*n + j] = (i == j);

  /* Gaussian elimination */
  for ( i = 0; i < n; i++ ) {
    /* choose the pivot as the largest element of column i */
    x = fabs( a[(ip = i)*n + i] );
    for ( k = ip + 1; k < n; k++ )
      if ( fabs( a[k*n + i] ) > x )
        x = fabs( a[(ip = k)*n + i] );

    /* swap the pivot (ip'th) row with the present row i */
    for ( k = i; k < n; k++ )
      x = a[i*n + k], a[i*n + k] = a[ip*n + k], a[ip*n + k] = x;
    for ( k = 0; k < n; k++ )
      x = b[i*n + k], b[i*n + k] = b[ip*n + k], b[ip*n + k] = x;

    /* normalize this row */
    x = a[i*n + i];
    if ( fabs(x) < DBL_MIN ) {
      fprintf(stderr, "Error: singular matrix of %dx%d\n", n, n);
      return -1;
    }
    for ( k = i; k < n; k++ ) a[i*n + k] /= x;
    for ( k = 0; k < n; k++ ) b[i*n + k] /= x;

    /* use the pivot row to zero the rest rows */
    for ( j = i + 1; j < n; j++ ) {
      x = a[j*n + i];
      for ( k = i; k < n; k++ )
        a[j*n + k] -= x * a[i*n + k];
      for ( k = 0; k < n; k++ )
        b[j*n + k] -= x * b[i*n + k];
    }
  }

  /* now that the matrix is upper triangular
   * make it diagonal */
  for ( i = n - 1; i >= 0; i-- ) {
    /* note a[i*n + i] should be 1 now */
    for ( j = 0; j < i; j++ ) {
      x = a[j*n + i];
      for ( k = 0; k < n; k++ )
        b[j*n + k] -= b[i*n + k] * x;
    }
  }
  return 0;
}



/* solve A x = b by L U decomposition
 * the matrix `a' will be destroyed
 * the vector `b' will be replaced by `x' on return */
static int lusolve(double *a, double *b, int n, double tiny)
{
  int i, j, k, ip = 0;
  double x, max;

  for (i = 0; i < n; i++) {  /* normalize each equation */
    for (max = 0.0, j = 0; j < n; j++)
      if ((x = fabs(a[i*n + j])) > max)
        max = x;
    if (max < DBL_MIN) return -1;
    for (x = 1./max, j = 0; j < n; j++)
      a[i*n + j] *= x;
    b[i] *= x;
  }

  /* step 1: A = L U, column by column */
  for (j = 0; j < n; j++) {
    /* matrix U */
    for (i = 0; i < j; i++) {
      for (x = a[i*n + j], k = 0; k < i; k++)
        x -= a[i*n + k] * a[k*n + j];
      a[i*n + j] = x;
    }

    /* matrix L, diagonal of L are 1 */
    max = 0.0;
    ip = j;
    for (i = j; i < n; i++) {
      for (x = a[i*n + j], k = 0; k < j; k++)
        x -= a[i*n + k] * a[k*n + j];
      a[i*n + j] = x;
      if (fabs(x) > max) {
        max = fabs(x);
        ip = i;
      }
    }

    if (j != ip) { /* swap the pivot row with the jth row */
      for (k = 0; k < n; k++)
        x = a[ip*n + k], a[ip*n + k] = a[j*n + k], a[j*n + k] = x;
      x = b[ip], b[ip] = b[j], b[j] = x;
    }
    if (fabs(a[j*n + j]) < tiny)
      a[j*n + j] = tiny;
    /* divide by the pivot element, for the L matrix */
    if (j != n - 1)
      for (x = 1./a[j*n + j], i = j + 1; i < n; i++)
        a[i*n + j] *= x;
  }

  /* step 2: solve the equation L U x = b */
  for (i = 0; i < n; i++) { /* L y = b */
    x = b[i];
    for (j = 0; j < i; j++) x -= a[i*n + j] * b[j];
    b[i] = x;
  }
  for (i = n - 1; i >= 0; i--) { /* U x = y. */
    x = b[i];
    for (j = i + 1; j < n; j++) x -= a[i*n + j] * b[j];
    b[i] = x / a[i*n + i];
  }
  return 0;
}





/* String routines */



/* remove leading and trailing spaces */
__inline static char *strstrip(char *s)
{
  char *p, *q;

  /* remove trailing spaces */
  for ( p = s + strlen(s) - 1; isspace(*p); p-- )
    *p = '\0';

  /* remove leading spaces */
  for ( p = s; *p && isspace(*p); p++ )  ;
  if ( p != s )
    for ( q = s; (*q++ = *p++) != '\0'; ) ;
  return s;
}



#define strcmpfuzzy(s, t) strncmpfuzzy(s, t, INT_MAX)

/* comparison, ignoring cases, spaces and punctuations */
__inline static int strncmpfuzzy(const char *s, const char *t, int n)
{
  int is, it, i;
  const char cset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789()[]{}";

  for ( i = 0; i < n; s++, t++, i++ ) {
    while ( *s != '\0' && strchr(cset, *s) == NULL ) s++;
    while ( *t != '\0' && strchr(cset, *t) == NULL ) t++;
    is = tolower(*s);
    it = tolower(*t);
    if ( is != it ) return is - it;
    if ( *s == '\0' ) return 0;
  }
  return 0;
}



/* check if `s' starts with `t', using fuzzy comparison */
__inline static int strstartswith(const char *s, const char *t)
{
  return strncmpfuzzy(s, t, strlen(t)) == 0;
}



/* check if a string is a nonnegative integer */
__inline static int striscnum(const char *s)
{
  for ( ; *s; s++ ) if ( !isdigit(*s) ) return 0;
  return 1;
}



#endif /* UTIL_H__ */

