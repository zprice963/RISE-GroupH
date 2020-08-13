/* Created by Language version: 7.7.0 */
/* VECTORIZED */
#define NRN_VECTORIZED 1
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "scoplib_ansi.h"
#undef PI
#define nil 0
#include "md1redef.h"
#include "section.h"
#include "nrniv_mf.h"
#include "md2redef.h"
 
#if METHOD3
extern int _method3;
#endif

#if !NRNGPU
#undef exp
#define exp hoc_Exp
extern double hoc_Exp(double);
#endif
 
#define nrn_init _nrn_init__kA
#define _nrn_initial _nrn_initial__kA
#define nrn_cur _nrn_cur__kA
#define _nrn_current _nrn_current__kA
#define nrn_jacob _nrn_jacob__kA
#define nrn_state _nrn_state__kA
#define _net_receive _net_receive__kA 
#define states states__kA 
 
#define _threadargscomma_ _p, _ppvar, _thread, _nt,
#define _threadargsprotocomma_ double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt,
#define _threadargs_ _p, _ppvar, _thread, _nt
#define _threadargsproto_ double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt
 	/*SUPPRESS 761*/
	/*SUPPRESS 762*/
	/*SUPPRESS 763*/
	/*SUPPRESS 765*/
	 extern double *getarg();
 /* Thread safe. No static _p or _ppvar. */
 
#define t _nt->_t
#define dt _nt->_dt
#define gkAbar _p[0]
#define vhalfAct _p[1]
#define vhalfInact _p[2]
#define slopeAct _p[3]
#define slopeInact _p[4]
#define vhalfTact _p[5]
#define slopeTact _p[6]
#define ik _p[7]
#define ikA _p[8]
#define minf _p[9]
#define hinf _p[10]
#define tau_m _p[11]
#define tau_h _p[12]
#define m _p[13]
#define h _p[14]
#define ek _p[15]
#define Dm _p[16]
#define Dh _p[17]
#define v _p[18]
#define _g _p[19]
#define _ion_ek	*_ppvar[0]._pval
#define _ion_ik	*_ppvar[1]._pval
#define _ion_dikdv	*_ppvar[2]._pval
 
#if MAC
#if !defined(v)
#define v _mlhv
#endif
#if !defined(h)
#define h _mlhh
#endif
#endif
 
#if defined(__cplusplus)
extern "C" {
#endif
 static int hoc_nrnpointerindex =  -1;
 static Datum* _extcall_thread;
 static Prop* _extcall_prop;
 /* external NEURON variables */
 /* declaration of user functions */
 static int _mechtype;
extern void _nrn_cacheloop_reg(int, int);
extern void hoc_register_prop_size(int, int, int);
extern void hoc_register_limits(int, HocParmLimits*);
extern void hoc_register_units(int, HocParmUnits*);
extern void nrn_promote(Prop*, int, int);
extern Memb_func* memb_func;
 
#define NMODL_TEXT 1
#if NMODL_TEXT
static const char* nmodl_file_text;
static const char* nmodl_filename;
extern void hoc_reg_nmodl_text(int, const char*);
extern void hoc_reg_nmodl_filename(int, const char*);
#endif

 extern void _nrn_setdata_reg(int, void(*)(Prop*));
 static void _setdata(Prop* _prop) {
 _extcall_prop = _prop;
 }
 static void _hoc_setdata() {
 Prop *_prop, *hoc_getdata_range(int);
 _prop = hoc_getdata_range(_mechtype);
   _setdata(_prop);
 hoc_retpushx(1.);
}
 /* connect user functions to hoc names */
 static VoidFunc hoc_intfunc[] = {
 "setdata_kA", _hoc_setdata,
 0, 0
};
 /* declare global and static user variables */
#define slopeTinact slopeTinact_kA
 double slopeTinact = -8.6;
#define vhalfTinact vhalfTinact_kA
 double vhalfTinact = -24.6;
 /* some parameters have upper and lower limits */
 static HocParmLimits _hoc_parm_limits[] = {
 0,0,0
};
 static HocParmUnits _hoc_parm_units[] = {
 "vhalfTinact_kA", "mV",
 "gkAbar_kA", "S/cm2",
 "vhalfAct_kA", "mV",
 "vhalfInact_kA", "mV",
 "vhalfTact_kA", "mV",
 "ik_kA", "mA/cm2",
 "ikA_kA", "mA/cm2",
 0,0
};
 static double delta_t = 0.01;
 static double h0 = 0;
 static double m0 = 0;
 /* connect global user variables to hoc */
 static DoubScal hoc_scdoub[] = {
 "vhalfTinact_kA", &vhalfTinact_kA,
 "slopeTinact_kA", &slopeTinact_kA,
 0,0
};
 static DoubVec hoc_vdoub[] = {
 0,0,0
};
 static double _sav_indep;
 static void nrn_alloc(Prop*);
static void  nrn_init(_NrnThread*, _Memb_list*, int);
static void nrn_state(_NrnThread*, _Memb_list*, int);
 static void nrn_cur(_NrnThread*, _Memb_list*, int);
static void  nrn_jacob(_NrnThread*, _Memb_list*, int);
 
static int _ode_count(int);
static void _ode_map(int, double**, double**, double*, Datum*, double*, int);
static void _ode_spec(_NrnThread*, _Memb_list*, int);
static void _ode_matsol(_NrnThread*, _Memb_list*, int);
 
#define _cvode_ieq _ppvar[3]._i
 static void _ode_matsol_instance1(_threadargsproto_);
 /* connect range variables in _p that hoc is supposed to know about */
 static const char *_mechanism[] = {
 "7.7.0",
"kA",
 "gkAbar_kA",
 "vhalfAct_kA",
 "vhalfInact_kA",
 "slopeAct_kA",
 "slopeInact_kA",
 "vhalfTact_kA",
 "slopeTact_kA",
 0,
 "ik_kA",
 "ikA_kA",
 "minf_kA",
 "hinf_kA",
 "tau_m_kA",
 "tau_h_kA",
 0,
 "m_kA",
 "h_kA",
 0,
 0};
 static Symbol* _k_sym;
 
extern Prop* need_memb(Symbol*);

static void nrn_alloc(Prop* _prop) {
	Prop *prop_ion;
	double *_p; Datum *_ppvar;
 	_p = nrn_prop_data_alloc(_mechtype, 20, _prop);
 	/*initialize range parameters*/
 	gkAbar = 0.006;
 	vhalfAct = -57.5;
 	vhalfInact = -93;
 	slopeAct = 7.7;
 	slopeInact = -6.1;
 	vhalfTact = -68.8;
 	slopeTact = -5;
 	_prop->param = _p;
 	_prop->param_size = 20;
 	_ppvar = nrn_prop_datum_alloc(_mechtype, 4, _prop);
 	_prop->dparam = _ppvar;
 	/*connect ionic variables to this model*/
 prop_ion = need_memb(_k_sym);
 nrn_promote(prop_ion, 0, 1);
 	_ppvar[0]._pval = &prop_ion->param[0]; /* ek */
 	_ppvar[1]._pval = &prop_ion->param[3]; /* ik */
 	_ppvar[2]._pval = &prop_ion->param[4]; /* _ion_dikdv */
 
}
 static void _initlists();
  /* some states have an absolute tolerance */
 static Symbol** _atollist;
 static HocStateTolerance _hoc_state_tol[] = {
 0,0
};
 static void _update_ion_pointer(Datum*);
 extern Symbol* hoc_lookup(const char*);
extern void _nrn_thread_reg(int, int, void(*)(Datum*));
extern void _nrn_thread_table_reg(int, void(*)(double*, Datum*, Datum*, _NrnThread*, int));
extern void hoc_register_tolerance(int, HocStateTolerance*, Symbol***);
extern void _cvode_abstol( Symbol**, double*, int);

 void _A_reg() {
	int _vectorized = 1;
  _initlists();
 	ion_reg("k", -10000.);
 	_k_sym = hoc_lookup("k_ion");
 	register_mech(_mechanism, nrn_alloc,nrn_cur, nrn_jacob, nrn_state, nrn_init, hoc_nrnpointerindex, 1);
 _mechtype = nrn_get_mechtype(_mechanism[1]);
     _nrn_setdata_reg(_mechtype, _setdata);
     _nrn_thread_reg(_mechtype, 2, _update_ion_pointer);
 #if NMODL_TEXT
  hoc_reg_nmodl_text(_mechtype, nmodl_file_text);
  hoc_reg_nmodl_filename(_mechtype, nmodl_filename);
#endif
  hoc_register_prop_size(_mechtype, 20, 4);
  hoc_register_dparam_semantics(_mechtype, 0, "k_ion");
  hoc_register_dparam_semantics(_mechtype, 1, "k_ion");
  hoc_register_dparam_semantics(_mechtype, 2, "k_ion");
  hoc_register_dparam_semantics(_mechtype, 3, "cvodeieq");
 	hoc_register_cvode(_mechtype, _ode_count, _ode_map, _ode_spec, _ode_matsol);
 	hoc_register_tolerance(_mechtype, _hoc_state_tol, &_atollist);
 	hoc_register_var(hoc_scdoub, hoc_vdoub, hoc_intfunc);
 	ivoc_help("help ?1 kA C:/Users/zprice11/Desktop/doug2017_with_skca-master/A.mod\n");
 hoc_register_limits(_mechtype, _hoc_parm_limits);
 hoc_register_units(_mechtype, _hoc_parm_units);
 }
static int _reset;
static char *modelname = "A-type transient potassium current (A-current)";

static int error;
static int _ninits = 0;
static int _match_recurse=1;
static void _modl_cleanup(){ _match_recurse=1;}
 
static int _ode_spec1(_threadargsproto_);
/*static int _ode_matsol1(_threadargsproto_);*/
 static int _slist1[2], _dlist1[2];
 static int states(_threadargsproto_);
 
/*CVODE*/
 static int _ode_spec1 (double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt) {int _reset = 0; {
   double _lminf , _lhinf , _ltau_m , _ltau_h ;
 _lminf = 1.0 / ( 1.0 + exp ( - ( v - vhalfAct ) / slopeAct ) ) ;
   _lhinf = 1.0 / ( 1.0 + exp ( - ( v - vhalfInact ) / slopeInact ) ) ;
   _ltau_m = 0.95 + 4.45 / ( 1.0 + exp ( - ( v - vhalfTact ) / slopeTact ) ) ;
   _ltau_h = 128.0 + 77.0 / ( 1.0 + exp ( - ( v - vhalfTinact ) / slopeTinact ) ) ;
   Dm = ( _lminf - m ) / _ltau_m ;
   Dh = ( _lhinf - h ) / _ltau_h ;
   }
 return _reset;
}
 static int _ode_matsol1 (double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt) {
 double _lminf , _lhinf , _ltau_m , _ltau_h ;
 _lminf = 1.0 / ( 1.0 + exp ( - ( v - vhalfAct ) / slopeAct ) ) ;
 _lhinf = 1.0 / ( 1.0 + exp ( - ( v - vhalfInact ) / slopeInact ) ) ;
 _ltau_m = 0.95 + 4.45 / ( 1.0 + exp ( - ( v - vhalfTact ) / slopeTact ) ) ;
 _ltau_h = 128.0 + 77.0 / ( 1.0 + exp ( - ( v - vhalfTinact ) / slopeTinact ) ) ;
 Dm = Dm  / (1. - dt*( ( ( ( - 1.0 ) ) ) / _ltau_m )) ;
 Dh = Dh  / (1. - dt*( ( ( ( - 1.0 ) ) ) / _ltau_h )) ;
  return 0;
}
 /*END CVODE*/
 static int states (double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt) { {
   double _lminf , _lhinf , _ltau_m , _ltau_h ;
 _lminf = 1.0 / ( 1.0 + exp ( - ( v - vhalfAct ) / slopeAct ) ) ;
   _lhinf = 1.0 / ( 1.0 + exp ( - ( v - vhalfInact ) / slopeInact ) ) ;
   _ltau_m = 0.95 + 4.45 / ( 1.0 + exp ( - ( v - vhalfTact ) / slopeTact ) ) ;
   _ltau_h = 128.0 + 77.0 / ( 1.0 + exp ( - ( v - vhalfTinact ) / slopeTinact ) ) ;
    m = m + (1. - exp(dt*(( ( ( - 1.0 ) ) ) / _ltau_m)))*(- ( ( ( _lminf ) ) / _ltau_m ) / ( ( ( ( - 1.0 ) ) ) / _ltau_m ) - m) ;
    h = h + (1. - exp(dt*(( ( ( - 1.0 ) ) ) / _ltau_h)))*(- ( ( ( _lhinf ) ) / _ltau_h ) / ( ( ( ( - 1.0 ) ) ) / _ltau_h ) - h) ;
   }
  return 0;
}
 
static int _ode_count(int _type){ return 2;}
 
static void _ode_spec(_NrnThread* _nt, _Memb_list* _ml, int _type) {
   double* _p; Datum* _ppvar; Datum* _thread;
   Node* _nd; double _v; int _iml, _cntml;
  _cntml = _ml->_nodecount;
  _thread = _ml->_thread;
  for (_iml = 0; _iml < _cntml; ++_iml) {
    _p = _ml->_data[_iml]; _ppvar = _ml->_pdata[_iml];
    _nd = _ml->_nodelist[_iml];
    v = NODEV(_nd);
  ek = _ion_ek;
     _ode_spec1 (_p, _ppvar, _thread, _nt);
  }}
 
static void _ode_map(int _ieq, double** _pv, double** _pvdot, double* _pp, Datum* _ppd, double* _atol, int _type) { 
	double* _p; Datum* _ppvar;
 	int _i; _p = _pp; _ppvar = _ppd;
	_cvode_ieq = _ieq;
	for (_i=0; _i < 2; ++_i) {
		_pv[_i] = _pp + _slist1[_i];  _pvdot[_i] = _pp + _dlist1[_i];
		_cvode_abstol(_atollist, _atol, _i);
	}
 }
 
static void _ode_matsol_instance1(_threadargsproto_) {
 _ode_matsol1 (_p, _ppvar, _thread, _nt);
 }
 
static void _ode_matsol(_NrnThread* _nt, _Memb_list* _ml, int _type) {
   double* _p; Datum* _ppvar; Datum* _thread;
   Node* _nd; double _v; int _iml, _cntml;
  _cntml = _ml->_nodecount;
  _thread = _ml->_thread;
  for (_iml = 0; _iml < _cntml; ++_iml) {
    _p = _ml->_data[_iml]; _ppvar = _ml->_pdata[_iml];
    _nd = _ml->_nodelist[_iml];
    v = NODEV(_nd);
  ek = _ion_ek;
 _ode_matsol_instance1(_threadargs_);
 }}
 extern void nrn_update_ion_pointer(Symbol*, Datum*, int, int);
 static void _update_ion_pointer(Datum* _ppvar) {
   nrn_update_ion_pointer(_k_sym, _ppvar, 0, 0);
   nrn_update_ion_pointer(_k_sym, _ppvar, 1, 3);
   nrn_update_ion_pointer(_k_sym, _ppvar, 2, 4);
 }

static void initmodel(double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt) {
  int _i; double _save;{
  h = h0;
  m = m0;
 {
   m = minf ;
   h = hinf ;
   }
 
}
}

static void nrn_init(_NrnThread* _nt, _Memb_list* _ml, int _type){
double* _p; Datum* _ppvar; Datum* _thread;
Node *_nd; double _v; int* _ni; int _iml, _cntml;
#if CACHEVEC
    _ni = _ml->_nodeindices;
#endif
_cntml = _ml->_nodecount;
_thread = _ml->_thread;
for (_iml = 0; _iml < _cntml; ++_iml) {
 _p = _ml->_data[_iml]; _ppvar = _ml->_pdata[_iml];
#if CACHEVEC
  if (use_cachevec) {
    _v = VEC_V(_ni[_iml]);
  }else
#endif
  {
    _nd = _ml->_nodelist[_iml];
    _v = NODEV(_nd);
  }
 v = _v;
  ek = _ion_ek;
 initmodel(_p, _ppvar, _thread, _nt);
 }
}

static double _nrn_current(double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt, double _v){double _current=0.;v=_v;{ {
   ikA = gkAbar * m * h * ( v - ek ) ;
   ik = ikA ;
   }
 _current += ik;

} return _current;
}

static void nrn_cur(_NrnThread* _nt, _Memb_list* _ml, int _type) {
double* _p; Datum* _ppvar; Datum* _thread;
Node *_nd; int* _ni; double _rhs, _v; int _iml, _cntml;
#if CACHEVEC
    _ni = _ml->_nodeindices;
#endif
_cntml = _ml->_nodecount;
_thread = _ml->_thread;
for (_iml = 0; _iml < _cntml; ++_iml) {
 _p = _ml->_data[_iml]; _ppvar = _ml->_pdata[_iml];
#if CACHEVEC
  if (use_cachevec) {
    _v = VEC_V(_ni[_iml]);
  }else
#endif
  {
    _nd = _ml->_nodelist[_iml];
    _v = NODEV(_nd);
  }
  ek = _ion_ek;
 _g = _nrn_current(_p, _ppvar, _thread, _nt, _v + .001);
 	{ double _dik;
  _dik = ik;
 _rhs = _nrn_current(_p, _ppvar, _thread, _nt, _v);
  _ion_dikdv += (_dik - ik)/.001 ;
 	}
 _g = (_g - _rhs)/.001;
  _ion_ik += ik ;
#if CACHEVEC
  if (use_cachevec) {
	VEC_RHS(_ni[_iml]) -= _rhs;
  }else
#endif
  {
	NODERHS(_nd) -= _rhs;
  }
 
}
 
}

static void nrn_jacob(_NrnThread* _nt, _Memb_list* _ml, int _type) {
double* _p; Datum* _ppvar; Datum* _thread;
Node *_nd; int* _ni; int _iml, _cntml;
#if CACHEVEC
    _ni = _ml->_nodeindices;
#endif
_cntml = _ml->_nodecount;
_thread = _ml->_thread;
for (_iml = 0; _iml < _cntml; ++_iml) {
 _p = _ml->_data[_iml];
#if CACHEVEC
  if (use_cachevec) {
	VEC_D(_ni[_iml]) += _g;
  }else
#endif
  {
     _nd = _ml->_nodelist[_iml];
	NODED(_nd) += _g;
  }
 
}
 
}

static void nrn_state(_NrnThread* _nt, _Memb_list* _ml, int _type) {
double* _p; Datum* _ppvar; Datum* _thread;
Node *_nd; double _v = 0.0; int* _ni; int _iml, _cntml;
#if CACHEVEC
    _ni = _ml->_nodeindices;
#endif
_cntml = _ml->_nodecount;
_thread = _ml->_thread;
for (_iml = 0; _iml < _cntml; ++_iml) {
 _p = _ml->_data[_iml]; _ppvar = _ml->_pdata[_iml];
 _nd = _ml->_nodelist[_iml];
#if CACHEVEC
  if (use_cachevec) {
    _v = VEC_V(_ni[_iml]);
  }else
#endif
  {
    _nd = _ml->_nodelist[_iml];
    _v = NODEV(_nd);
  }
 v=_v;
{
  ek = _ion_ek;
 {   states(_p, _ppvar, _thread, _nt);
  } }}

}

static void terminal(){}

static void _initlists(){
 double _x; double* _p = &_x;
 int _i; static int _first = 1;
  if (!_first) return;
 _slist1[0] = &(m) - _p;  _dlist1[0] = &(Dm) - _p;
 _slist1[1] = &(h) - _p;  _dlist1[1] = &(Dh) - _p;
_first = 0;
}

#if defined(__cplusplus)
} /* extern "C" */
#endif

#if NMODL_TEXT
static const char* nmodl_filename = "A.mod";
static const char* nmodl_file_text = 
  "TITLE  A-type transient potassium current (A-current)\n"
  "\n"
  "COMMENT\n"
  "written for NEURON by Antonios Dougalis, 23 Feb 2015, London, UK\n"
  "based on voltage clamp data from Dougalis et al., 2017 J Comput Neurosci \n"
  "ENDCOMMENT\n"
  "\n"
  "UNITS {\n"
  "        (S) = (siemens)\n"
  "        (mA) = (milliamp)\n"
  "        (mV) = (millivolt)\n"
  "}\n"
  " \n"
  "NEURON {\n"
  "        SUFFIX kA\n"
  "        USEION k READ ek WRITE ik \n"
  "        RANGE gkAbar,ek,ik, ikA\n"
  "        RANGE minf,hinf\n"
  "		RANGE tau_m, tau_h\n"
  "		RANGE vhalfAct,slopeAct,vhalfInact,slopeInact\n"
  "		RANGE vhalfTact,slopeTact,vhalfTInact,slopeTInact\n"
  "}\n"
  " \n"
  "PARAMETER {\n"
  "        v   (mV)\n"
  "        dt  (ms)\n"
  "		gkAbar  = 0.006 (S/cm2)\n"
  "        ek = -73 (mV) \n"
  "		vhalfAct = -57.5 (mV)\n"
  "		vhalfInact = -93.0 (mV)\n"
  "		slopeAct = 7.7\n"
  "		slopeInact = -6.1\n"
  "		vhalfTact = -68.8 (mV)\n"
  "		vhalfTinact = -24.6 (mV)\n"
  "		slopeTact = -5.0\n"
  "		slopeTinact = -8.6\n"
  "}\n"
  " \n"
  "STATE {\n"
  "        m h\n"
  "}\n"
  " \n"
  "ASSIGNED {\n"
  "        ik (mA/cm2)\n"
  "		ikA (mA/cm2)\n"
  "        minf\n"
  "		hinf\n"
  "	    tau_m \n"
  "		tau_h\n"
  "		\n"
  "}\n"
  " \n"
  "BREAKPOINT {\n"
  "        SOLVE states METHOD cnexp\n"
  "        ikA = gkAbar*m*h*(v - ek)\n"
  "ik=ikA		\n"
  "}\n"
  " \n"
  "UNITSOFF\n"
  "\n"
  "INITIAL {\n"
  "        m = minf\n"
  "		h = hinf\n"
  "}\n"
  "\n"
  "DERIVATIVE states { \n"
  "        LOCAL minf,hinf,tau_m, tau_h\n"
  "        minf = 1/(1 + exp(-(v - vhalfAct)/slopeAct))\n"
  "		hinf = 1/(1 + exp(-(v - vhalfInact)/slopeInact))\n"
  "        tau_m = 0.95 + 4.45/(1 + exp(-(v - vhalfTact)/slopeTact))\n"
  "        tau_h = 128 + 77/(1 + exp(-(v - vhalfTinact)/slopeTinact))\n"
  "		m' = (minf-m)/tau_m\n"
  "        h' = (hinf-h)/tau_h\n"
  "}\n"
  " \n"
  "UNITSON\n"
  "\n"
  ;
#endif
