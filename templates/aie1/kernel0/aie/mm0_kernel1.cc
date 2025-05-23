#include <adf.h>
#include <stdio.h>
#include "para_L{{layer}}.h"

void mm0_kernel1_L{{layer}}(input_window_float* __restrict matA, 
        input_window_float* __restrict matB,
        input_stream_accfloat* __restrict acc_in,
		output_stream_accfloat* __restrict matC){

	v16float buf_matB = undef_v16float();
	v16float buf_matA = undef_v16float();

	buf_matB = upd_v(buf_matB,0,window_read_v4(matB));
	window_incr(matB,L{{layer}}_w1);
	buf_matB = upd_v(buf_matB,1,window_read_v4(matB));
	window_decr(matB,L{{layer}}_jump_B0);

	buf_matA=upd_w(buf_matA,0,window_read_v8(matA));
	window_incr(matA,L{{layer}}_h1);
	
	for (unsigned int i=0;i<L{{layer}}_boundary_i;i++) 
	chess_prepare_for_pipelining
	chess_loop_range(L{{layer}}_boundary_i,)
	{	
		
		for (unsigned int j=0;j<L{{layer}}_boundary_j;j++)
		chess_prepare_for_pipelining
		chess_loop_range(L{{layer}}_boundary_j,){
			v8float  acc0=readincr_v8(acc_in);
			v8float  acc1=readincr_v8(acc_in);
			int jump=L{{layer}}_h1;
			if (j==L{{layer}}_judge_j){
				if(i==L{{layer}}_judge_i){
					jump=8;
				}
				else{
					jump=L{{layer}}_jump_A0;
				}
			}
			else{
				jump=L{{layer}}_h1;
			}
			for (unsigned int k=0;k<L{{layer}}_boundary_k;k++)
			chess_prepare_for_pipelining
			chess_loop_range(L{{layer}}_boundary_k,)
			{
				acc0 = fpmac(acc0,buf_matA,0,0x76543210,ext_w(buf_matB,0),0,0x0); 
				buf_matA = upd_w(buf_matA,1,window_read_v8(matA));
				window_incr(matA,L{{layer}}_h1);
				buf_matB = upd_v(buf_matB,2,window_read_v4(matB));
				window_incr(matB,L{{layer}}_w1);	
				acc1 = fpmac(acc1,buf_matA,0,0x76543210,ext_w(buf_matB,0),4,0x0); 
				buf_matB = upd_v(buf_matB,3,window_read_v4(matB));
				window_decr(matB,L{{layer}}_jump_B0); 
		
				acc0 = fpmac(acc0,buf_matA,8,0x76543210,ext_w(buf_matB,0),1,0x0); 
				buf_matA = upd_w(buf_matA,0,window_read_v8(matA));
				window_incr(matA,L{{layer}}_h1);
				acc1 = fpmac(acc1,buf_matA,8,0x76543210,ext_w(buf_matB,0),5,0x0);
			
				acc0 = fpmac(acc0,buf_matA,0,0x76543210,ext_w(buf_matB,0),2,0x0);
				buf_matA = upd_w(buf_matA,1,window_read_v8(matA));
				window_incr(matA,L{{layer}}_h1);
				acc1 = fpmac(acc1,buf_matA,0,0x76543210,ext_w(buf_matB,0),6,0x0);
		
				acc0 = fpmac(acc0,buf_matA,8,0x76543210,ext_w(buf_matB,0),3,0x0);
				buf_matA = upd_w(buf_matA,0,window_read_v8(matA));
				window_incr(matA,L{{layer}}_h1);
				acc1 = fpmac(acc1,buf_matA,8,0x76543210,ext_w(buf_matB,0),7,0x0);
		
		
				////////////////////////////////////////////////////////////////////////
				acc0 = fpmac(acc0,buf_matA,0,0x76543210,ext_w(buf_matB,1),0,0x0);
				buf_matA = upd_w(buf_matA,1,window_read_v8(matA));
				window_incr(matA,L{{layer}}_h1);	
				acc1 = fpmac(acc1,buf_matA,0,0x76543210,ext_w(buf_matB,1),4,0x0);
				
		
				acc0 = fpmac(acc0,buf_matA,8,0x76543210,ext_w(buf_matB,1),1,0x0);
				buf_matA = upd_w(buf_matA,0,window_read_v8(matA));
				window_incr(matA,L{{layer}}_h1);
				acc1 = fpmac(acc1,buf_matA,8,0x76543210,ext_w(buf_matB,1),5,0x0);
			
				acc0 = fpmac(acc0,buf_matA,0,0x76543210,ext_w(buf_matB,1),2,0x0);
				buf_matA = upd_w(buf_matA,1,window_read_v8(matA));
				window_incr(matA,L{{layer}}_h1);
				acc1 = fpmac(acc1,buf_matA,0,0x76543210,ext_w(buf_matB,1),6,0x0);
		
				acc0 = fpmac(acc0,buf_matA,8,0x76543210,ext_w(buf_matB,1),3,0x0);
				buf_matA = upd_w(buf_matA,0,window_read_v8(matA));
				window_incr(matA,L{{layer}}_h1);
				buf_matB = upd_v(buf_matB,0,window_read_v4(matB));
				window_incr(matB,L{{layer}}_w1);
				acc1 = fpmac(acc1,buf_matA,8,0x76543210,ext_w(buf_matB,1),7,0x0);
				buf_matB = upd_v(buf_matB,1,window_read_v4(matB));
				window_decr(matB,L{{layer}}_jump_B0);
			}
			acc0 = fpmac(acc0,buf_matA,0,0x76543210,ext_w(buf_matB,0),0,0x0); 
			buf_matA = upd_w(buf_matA,1,window_read_v8(matA));
			window_incr(matA,L{{layer}}_h1);
			buf_matB = upd_v(buf_matB,2,window_read_v4(matB));
			window_incr(matB,L{{layer}}_w1);	
			acc1 = fpmac(acc1,buf_matA,0,0x76543210,ext_w(buf_matB,0),4,0x0); 
			buf_matB = upd_v(buf_matB,3,window_read_v4(matB));
			window_incr(matB,4); 
	
			acc0 = fpmac(acc0,buf_matA,8,0x76543210,ext_w(buf_matB,0),1,0x0); 
			buf_matA = upd_w(buf_matA,0,window_read_v8(matA));
			window_incr(matA,L{{layer}}_h1);
			acc1 = fpmac(acc1,buf_matA,8,0x76543210,ext_w(buf_matB,0),5,0x0);
		
			acc0 = fpmac(acc0,buf_matA,0,0x76543210,ext_w(buf_matB,0),2,0x0);
			buf_matA = upd_w(buf_matA,1,window_read_v8(matA));
			window_incr(matA,L{{layer}}_h1);
			acc1 = fpmac(acc1,buf_matA,0,0x76543210,ext_w(buf_matB,0),6,0x0);
	
			acc0 = fpmac(acc0,buf_matA,8,0x76543210,ext_w(buf_matB,0),3,0x0);
			buf_matA = upd_w(buf_matA,0,window_read_v8(matA));
			window_incr(matA,L{{layer}}_h1);
			acc1 = fpmac(acc1,buf_matA,8,0x76543210,ext_w(buf_matB,0),7,0x0);
	
	
			////////////////////////////////////////////////////////////////////////
			acc0 = fpmac(acc0,buf_matA,0,0x76543210,ext_w(buf_matB,1),0,0x0);
			buf_matA = upd_w(buf_matA,1,window_read_v8(matA));
			window_incr(matA,L{{layer}}_h1);	
			acc1 = fpmac(acc1,buf_matA,0,0x76543210,ext_w(buf_matB,1),4,0x0);
			
	
			acc0 = fpmac(acc0,buf_matA,8,0x76543210,ext_w(buf_matB,1),1,0x0);
			buf_matA = upd_w(buf_matA,0,window_read_v8(matA));
			window_incr(matA,L{{layer}}_h1);
			acc1 = fpmac(acc1,buf_matA,8,0x76543210,ext_w(buf_matB,1),5,0x0);
		
			acc0 = fpmac(acc0,buf_matA,0,0x76543210,ext_w(buf_matB,1),2,0x0);
			buf_matA = upd_w(buf_matA,1,window_read_v8(matA));
			window_incr(matA,jump);
			acc1 = fpmac(acc1,buf_matA,0,0x76543210,ext_w(buf_matB,1),6,0x0);
	
			acc0 = fpmac(acc0,buf_matA,8,0x76543210,ext_w(buf_matB,1),3,0x0);
			writeincr_v8(matC,acc0);
			buf_matA = upd_w(buf_matA,0,window_read_v8(matA));
			window_incr(matA,L{{layer}}_h1);
			buf_matB = upd_v(buf_matB,0,window_read_v4(matB));
			window_incr(matB,L{{layer}}_w1);
			acc1 = fpmac(acc1,buf_matA,8,0x76543210,ext_w(buf_matB,1),7,0x0);
			writeincr_v8(matC,acc1);
			buf_matB = upd_v(buf_matB,1,window_read_v4(matB));
			window_decr(matB,L{{layer}}_jump_B0);	
		}
	}
}

