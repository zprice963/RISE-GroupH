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
 
#define nrn_init _nrn_init__caHVA
#define _nrn_initial _nrn_initial__caHVA
#define nrn_cur _nrn_cur__caHVA
#define _nrn_current _nrn_current__caHVA
#define nrn_jacob _nrn_jacob__caHVA
#define nrn_state _nrn_state__caHVA
#define _net_receive _net_receive__caHVA 
#define states states__caHVA 
 
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
#define gcaHVAbar _p[0]
#define vhalfAct _p[1]
#define vhalfInact _p[2]
#define slopeAct _p[3]
#define slopeInact _p[4]
#define vhalfTact _p[5]
#define vhalfTinact _p[6]
#define slopeTact _p[7]
#define slopeTinact _p[8]
#define ica _p[9]
#define icaHVA _p[10]
#define dHVAinf _p[11]
#define fHVAinf _p[12]
#define dHVA _p[13]
#define fHVA _p[14]
#define eca _p[15]
#define DdHVA _p[16]
#define DfHVA _p[17]
#define v _p[18]
#define _g _p[19]
#define _ion_eca	*_ppvar[0]._pval
#define _ion_ica	*_ppvar[1]._pval
#define _ion_dicadv	*_ppvar[2]._pval
 
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
 static void _hoc_boltz(void);
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
 "setdata_caHVA", _hoc_setdata,
 "boltz_caHVA", _hoc_boltz,
 0, 0
};
#define boltz boltz_caHVA
 extern double boltz( _threadargsprotocomma_ double , double , double );
 /* declare global and static user variables */
 /* some parameters have upper and lower limits */
 static HocParmLimits _hoc_parm_limits[] = {
 0,0,0
};
 static HocParmUnits _hoc_parm_units[] = {
 "gcaHVAbar_caHVA", "S/cm2",
 "vhalfAct_caHVA", "mV",
 "vhalfInact_caHVA", "mV",
 "vhalfTact_caHVA", "mV",
 "vhalfTinact_caHVA", "mV",
 "ica_caHVA", "mA/cm2",
 "icaHVA_caHVA", "mA/cm2",
 0,0
};
 static double delta_t = 0.01;
 static double dHVA0 = 0;
 static double fHVA0 = 0;
 /* connect global user variables to hoc */
 static DoubScal hoc_scdoub[] = {
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
"caHVA",
 "gcaHVAbar_caHVA",
 "vhalfAct_caHVA",
 "vhalfInact_caHVA",
 "slopeAct_caHVA",
 "slopeInact_caHVA",
 "vhalfTact_caHVA",
 "vhalfTinact_caHVA",
 "slopeTact_caHVA",
 "slopeTinact_caHVA",
 0,
 "ica_caHVA",
 "icaHVA_caHVA",
 "dHVAinf_caHVA",
 "fHVAinf_caHVA",
 0,
 "dHVA_caHVA",
 "fHVA_caHVA",
 0,
 0};
 static Symbol* _ca_sym;
 
extern Prop* need_memb(Symbol*);

static void nrn_alloc(Prop* _prop) {
	Prop *prop_ion;
	double *_p; Datum *_ppvar;
 	_p = nrn_prop_data_alloc(_mechtype, 20, _prop);
 	/*initialize range parameters*/
 	gcaHVAbar = 4e-005;
 	vhalfAct = -22;
 	vhalfInact = -40;
 	slopeAct = 5;
 	slopeInact = -7;
 	vhalfTact = -40;
 	vhalfTinact = -39;
 	slopeTact = -3;
 	slopeTinact = -2.6;
 	_prop->param = _p;
 	_prop->param_size = 20;
 	_ppvar = nrn_prop_datum_alloc(_mechtype, 4, _prop);
 	_prop->dparam = _ppvar;
 	/*connect ionic variables to this model*/
 prop_ion = need_memb(_ca_sym);
 nrn_promote(prop_ion, 0, 1);
 	_ppvar[0]._pval = &prop_ion->param[0]; /* eca */
 	_ppvar[1]._pval = &prop_ion->param[3]; /* ica */
 	_ppvar[2]._pval = &prop_ion->param[4]; /* _ion_dicadv */
 
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

 void _CaHVA_reg() {
	int _vectorized = 1;
  _initlists();
 	ion_reg("ca", -10000.);
 	_ca_sym = hoc_lookup("ca_ion");
 	register_mech(_mechanism, nrn_alloc,nrn_cur, nrn_jacob, nrn_state, nrn_init, hoc_nrnpointerindex, 1);
 _mechtype = nrn_get_mechtype(_mechanism[1]);
     _nrn_setdata_reg(_mechtype, _setdata);
     _nrn_thread_reg(_mechtype, 2, _update_ion_pointer);
 #if NMODL_TEXT
  hoc_reg_nmodl_text(_mechtype, nmodl_file_text);
  hoc_reg_nmodl_filename(_mechtype, nmodl_filename);
#endif
  hoc_register_prop_size(_mechtype, 20, 4);
  hoc_register_dparam_semantics(_mechtype, 0, "ca_ion");
  hoc_register_dparam_semantics(_mechtype, 1, "ca_ion");
  hoc_register_dparam_semantics(_mechtype, 2, "ca_ion");
  hoc_register_dparam_semantics(_mechtype, 3, "cvodeieq");
 	hoc_register_cvode(_mechtype, _ode_count, _ode_map, _ode_spec, _ode_matsol);
 	hoc_register_tolerance(_mechtype, _hoc_state_tol, &_atollist);
 	hoc_register_var(hoc_scdoub, hoc_vdoub, hoc_intfunc);
 	ivoc_help("help ?1 caHVA C:/Users/zprice11/Desktop/doug2017_with_skca-master/CaHVA.mod\n");
 hoc_register_limits(_mechtype, _hoc_parm_limits);
 hoc_register_units(_mechtype, _hoc_parm_units);
 }
static int _reset;
static char *modelname = "HVA calcium currents (CaHVA-current) ";

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
   double _ldHVAinf , _ldHVAtau , _lfHVAinf , _lfHVAtau ;
 _ldHVAinf = 1.0 / ( 1.0 + exp ( - ( v - vhalfAct ) / slopeAct ) ) ;
   _lfHVAinf = 1.0 / ( 1.0 + exp ( - ( v - vhalfInact ) / slopeInact ) ) ;
   _ldHVAtau = 1.0 / ( 1.0 + exp ( - ( v - vhalfTact ) / slopeTact ) ) + 0.78 ;
   _lfHVAtau = 77.0 / ( 1.0 + exp ( - ( v - vhalfTinact ) / slopeTinact ) ) + 17.0 ;
   DdHVA = ( _ldHVAinf - dHVA ) / _ldHVAtau ;
   DfHVA = ( _lfHVAinf - fHVA ) / _lfHVAtau ;
   }
 return _reset;
}
 static int _ode_matsol1 (double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt) {
 double _ldHVAinf , _ldHVAtau , _lfHVAinf , _lfHVAtau ;
 _ldHVAinf = 1.0 / ( 1.0 + exp ( - ( v - vhalfAct ) / slopeAct ) ) ;
 _lfHVAinf = 1.0 / ( 1.0 + exp ( - ( v - vhalfInact ) / slopeInact ) ) ;
 _ldHVAtau = 1.0 / ( 1.0 + exp ( - ( v - vhalfTact ) / slopeTact ) ) + 0.78 ;
 _lfHVAtau = 77.0 / ( 1.0 + exp ( - ( v - vhalfTinact ) / slopeTinact ) ) + 17.0 ;
 DdHVA = DdHVA  / (1. - dt*( ( ( ( - 1.0 ) ) ) / _ldHVAtau )) ;
 DfHVA = DfHVA  / (1. - dt*( ( ( ( - 1.0 ) ) ) / _lfHVAtau )) ;
  return 0;
}
 /*END CVODE*/
 static int states (double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt) { {
   double _ldHVAinf , _ldHVAtau , _lfHVAinf , _lfHVAtau ;
 _ldHVAinf = 1.0 / ( 1.0 + exp ( - ( v - vhalfAct ) / slopeAct ) ) ;
   _lfHVAinf = 1.0 / ( 1.0 + exp ( - ( v - vhalfInact ) / slopeInact ) ) ;
   _ldHVAtau = 1.0 / ( 1.0 + exp ( - ( v - vhalfTact ) / slopeTact ) ) + 0.78 ;
   _lfHVAtau = 77.0 / ( 1.0 + exp ( - ( v - vhalfTinact ) / slopeTinact ) ) + 17.0 ;
    dHVA = dHVA + (1. - exp(dt*(( ( ( - 1.0 ) ) ) / _ldHVAtau)))*(- ( ( ( _ldHVAinf ) ) / _ldHVAtau ) / ( ( ( ( - 1.0 ) ) ) / _ldHVAtau ) - dHVA) ;
    fHVA = fHVA + (1. - exp(dt*(( ( ( - 1.0 ) ) ) / _lfHVAtau)))*(- ( ( ( _lfHVAinf ) ) / _lfHVAtau ) / ( ( ( ( - 1.0 ) ) ) / _lfHVAtau ) - fHVA) ;
   }
  return 0;
}
 
double boltz ( _threadargsprotocomma_ double _lx , double _ly , double _lz ) {
   double _lboltz;
 _lboltz = 1.0 / ( 1.0 + exp ( - ( _lx - _ly ) / _lz ) ) ;
   
return _lboltz;
 }
 
static void _hoc_boltz(void) {
  double _r;
   double* _p; Datum* _ppvar; Datum* _thread; _NrnThread* _nt;
   if (_extcall_prop) {_p = _extcall_prop->param; _ppvar = _extcall_prop->dparam;}else{ _p = (double*)0; _ppvar = (Datum*)0; }
  _thread = _extcall_thread;
  _nt = nrn_threads;
 _r =  boltz ( _p, _ppvar, _thread, _nt, *getarg(1) , *getarg(2) , *getarg(3) );
 hoc_retpushx(_r);
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
  eca = _ion_eca;
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
  eca = _ion_eca;
 _ode_matsol_instance1(_threadargs_);
 }}
 extern void nrn_update_ion_pointer(Symbol*, Datum*, int, int);
 static void _update_ion_pointer(Datum* _ppvar) {
   nrn_update_ion_pointer(_ca_sym, _ppvar, 0, 0);
   nrn_update_ion_pointer(_ca_sym, _ppvar, 1, 3);
   nrn_update_ion_pointer(_ca_sym, _ppvar, 2, 4);
 }

static void initmodel(double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt) {
  int _i; double _save;{
  dHVA = dHVA0;
  fHVA = fHVA0;
 {
   dHVA = dHVAinf ;
   fHVA = fHVAinf ;
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
  eca = _ion_eca;
 initmodel(_p, _ppvar, _thread, _nt);
 }
}

static double _nrn_current(double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt, double _v){double _current=0.;v=_v;{ {
   icaHVA = gcaHVAbar * dHVA * fHVA * ( v - eca ) ;
   ica = icaHVA ;
   }
 _current += ica;

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
  eca = _ion_eca;
 _g = _nrn_current(_p, _ppvar, _thread, _nt, _v + .001);
 	{ double _dica;
  _dica = ica;
 _rhs = _nrn_current(_p, _ppvar, _thread, _nt, _v);
  _ion_dicadv += (_dica - ica)/.001 ;
 	}
 _g = (_g - _rhs)/.001;
  _ion_ica += ica ;
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
  eca = _ion_eca;
 {   states(_p, _ppvar, _thread, _nt);
  } }}

}

static void terminal(){}

static void _initlists(){
 double _x; double* _p = &_x;
 int _i; static int _first = 1;
  if (!_first) return;
 _slist1[0] = &(dHVA) - _p;  _dlist1[0] = &(DdHVA) - _p;
 _slist1[1] = &(fHVA) - _p;  _dlist1[1] = &(DfHVA) - _p;
_first = 0;
}

#if defined(__cplusplus)
} /* extern "C" */
#endif

#if NMODL_TEXT
static const char* nmodl_filename = "CaHVA.mod";
static const char* nmodl_file_text = 
  "TITLE HVA calcium currents (CaHVA-current) \n"
  " \n"
  "COMMENT\n"
  "written for NEURON by Antonios Dougalis, 23 Feb 2015, London, UK\n"
  "based on voltage clamp data from Dougalis et al., 2017 J Comput Neurosci \n"
  "ENDCOMMENT\n"
  " \n"
  "UNITS {\n"
  "        (S) = (siemens)\n"
  "        (mA) = (milliamp)\n"
  "        (mV) = (millivolt)\n"
  "}\n"
  " \n"
  "NEURON {\n"
  "        SUFFIX caHVA\n"
  "        USEION ca READ eca WRITE ica\n"
  "        RANGE gcaHVAbar, icaHVA, ica \n"
  "		RANGE dHVAinf,fHVAinf\n"
  "		RANGE dHVAtau, fHVAtau\n"
  "		RANGE vhalfAct,slopeAct,vhalfInact,slopeInact\n"
  "		RANGE vhalfTact,slopeTact,vhalfTinact,slopeTinact\n"
  "}\n"
  " \n"
  "\n"
  "PARAMETER {\n"
  "        v (mV)\n"
  "        dt (ms)\n"
  "        gcaHVAbar =  0.00004 (S/cm2)\n"
  "        eca = 120 (mV)\n"
  "		vhalfAct = -22(mV)\n"
  "		vhalfInact = -40.0 (mV)\n"
  "		slopeAct = 5.0\n"
  "		slopeInact = -7.0\n"
  "		vhalfTact = -40.0(mV)\n"
  "		vhalfTinact = -39 (mV)\n"
  "		slopeTact = -3\n"
  "		slopeTinact = -2.6	\n"
  "}\n"
  " \n"
  "STATE {\n"
  "        dHVA fHVA  \n"
  "}\n"
  " \n"
  "ASSIGNED {\n"
  "        ica (mA/cm2)\n"
  "		icaHVA (mA/cm2)\n"
  "        dHVAinf \n"
  "		fHVAinf \n"
  "}\n"
  " \n"
  "BREAKPOINT {\n"
  "        SOLVE states METHOD cnexp\n"
  "        icaHVA = gcaHVAbar*dHVA*fHVA*(v - eca)\n"
  "		ica = icaHVA\n"
  "}\n"
  " \n"
  "UNITSOFF\n"
  " \n"
  "INITIAL {\n"
  "        dHVA = dHVAinf\n"
  "        fHVA = fHVAinf\n"
  "}\n"
  "\n"
  "DERIVATIVE states {  \n"
  "LOCAL dHVAinf,dHVAtau,fHVAinf,fHVAtau\n"
  "        dHVAinf = 1/(1 + exp(-(v - vhalfAct)/slopeAct))\n"
  "		fHVAinf = 1/(1 + exp(-(v - vhalfInact)/slopeInact))\n"
  "        dHVAtau = 1/(1 + exp(-(v - vhalfTact)/slopeTact)) + 0.78\n"
  "		fHVAtau = 77/(1 + exp(-(v - vhalfTinact)/slopeTinact)) + 17\n"
  "        dHVA' = (dHVAinf-dHVA)/dHVAtau\n"
  "        fHVA' = (fHVAinf-fHVA)/fHVAtau\n"
  "\n"
  "}\n"
  " \n"
  "FUNCTION boltz(x,y,z) {\n"
  "                boltz = 1/(1 + exp(-(x - y)/z))\n"
  "}\n"
  "\n"
  "UNITSON\n"
  "\n"
  ;
#endif
