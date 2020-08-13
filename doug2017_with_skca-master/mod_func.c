#include <stdio.h>
#include "hocdec.h"
#define IMPORT extern __declspec(dllimport)
IMPORT int nrnmpi_myid, nrn_nobanner_;

extern void _A_reg();
extern void _CaBK_reg();
extern void _CaHVA_reg();
extern void _CaLVA_reg();
extern void _H_reg();
extern void _M_reg();
extern void _NaP_reg();
extern void _NaT_reg();
extern void _SKCA_reg();
extern void _kDR_reg();
extern void _leak_reg();

void modl_reg(){
	//nrn_mswindll_stdio(stdin, stdout, stderr);
    if (!nrn_nobanner_) if (nrnmpi_myid < 1) {
	fprintf(stderr, "Additional mechanisms from files\n");

fprintf(stderr," A.mod");
fprintf(stderr," CaBK.mod");
fprintf(stderr," CaHVA.mod");
fprintf(stderr," CaLVA.mod");
fprintf(stderr," H.mod");
fprintf(stderr," M.mod");
fprintf(stderr," NaP.mod");
fprintf(stderr," NaT.mod");
fprintf(stderr," SKCA.mod");
fprintf(stderr," kDR.mod");
fprintf(stderr," leak.mod");
fprintf(stderr, "\n");
    }
_A_reg();
_CaBK_reg();
_CaHVA_reg();
_CaLVA_reg();
_H_reg();
_M_reg();
_NaP_reg();
_NaT_reg();
_SKCA_reg();
_kDR_reg();
_leak_reg();
}
