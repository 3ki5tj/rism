#ifndef UV_H__
#define UV_H__



/* structure that controls the solvent/solute interaction */
typedef struct {
  int *prmask;
  int ns, nsv; /* numbers of sites and solvent sites */
  int stage;
  int npr; /* number of active pairs */
} uv_t;



static uv_t *uv_open(model_t *m)
{
  uv_t *uv;
  int i, j, ns = m->ns;

  xnew(uv, 1);
  uv->ns = ns;
  uv->nsv = getnsv(m);
  xnew(uv->prmask, ns * ns);
  for ( i = 0; i < ns; i++ )
    for ( j = 0; j < ns; j++ )
      uv->prmask[i*ns + j] = (i < uv->nsv && j < uv->nsv);
  uv->npr = uv->nsv * (uv->nsv + 1) / 2;
  uv->stage = 0;
  return uv;
}



/* switch between stages
 * solvent-solvent --> solvent-solute --> solute-solute
 * return 1 if the iteration should stop */
static int uv_switch(uv_t *uv)
{
  int i, j, ns = uv->ns, nsv = uv->nsv;

  /* switch between stages */
  if ( uv->stage == 0 ) { /* turn on solute-solvent interaction */
    if ( nsv == ns ) return 1;
    for ( i = 0; i < ns; i++ )
      for ( j = 0; j < ns; j++ )
        uv->prmask[i*ns + j] = ((i < nsv && j >= nsv)
                         || (j < nsv && i >= nsv));
    uv->npr = (ns - nsv) * nsv;
    fprintf(stderr, "turning on solute-solvent interaction\n");
    uv->stage = 1;
  } else if ( uv->stage == 1 ) { /* turn on solute-solute interaction */
    for ( i = 0; i < ns; i++ )
      for ( j = 0; j < ns; j++ )
        uv->prmask[i*ns + j] = (i >= nsv && j >= nsv);
    //fprintf(stderr, "turning on solute-solute interaction\n");
    uv->npr = (ns - nsv) * (ns - nsv + 1) / 2;
    uv->stage = 2;
    return 1;
  } else {
    return 1;
  }
  return 0;
}



static void uv_close(uv_t *uv)
{
  free(uv->prmask);
  free(uv);
}



#endif /* UV_H__ */
