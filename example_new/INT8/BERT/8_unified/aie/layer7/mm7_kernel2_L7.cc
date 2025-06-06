#include <adf.h>
#include <stdio.h>
#include "para_L7.h"
void mm7_kernel2_L7(input_window_int8* __restrict matA, 
        input_window_int8*  __restrict matB,
        input_stream_acc48* __restrict acc_in,
        output_window_int8* __restrict matC){

    v64int8 chess_storage(xa) buf_matA0=undef_v64int8();
    v64int8 chess_storage(xb) buf_matA1=undef_v64int8();
            
    v32int8 chess_storage(wc0) buf_matB0=undef_v32int8(); 
    v32int8 chess_storage(wc1) buf_matB1=undef_v32int8(); 
    

    buf_matA0=upd_w(buf_matA0,0,window_read_v32(matA));
    window_incr(matA,L7_jumpA0);

    buf_matB0=window_read_v32(matB);
    window_incr(matB,L7_jumpB0);

    buf_matA0=upd_w(buf_matA0,1,window_read_v32(matA));
    window_incr(matA,L7_jumpA0);

    for (int i=0;i<L7_boundary_i;i++)
    chess_prepare_for_pipelining
    chess_loop_range(L7_boundary_i,)
    {
        for (int j=0;j<L7_boundary_j;j++)
        chess_prepare_for_pipelining
        chess_loop_range(L7_boundary_j,)
        {

            int jumpA=L7_jumpA1;
            int jumpB=L7_jumpB2;
            if(j==L7_judge_j){
                jumpA=L7_jumpA0;
                jumpB=L7_jumpB0;
            }

            v16acc48  acc0=concat(readincr_v8(acc_in),readincr_v8(acc_in));
            v16acc48  acc1=concat(readincr_v8(acc_in),readincr_v8(acc_in));      

            //K iteration 0
            acc0=mac16(acc0,buf_matA0,0,0x11101110,16,0x3120,buf_matB0,0,0x88880000,2,0x3210);
            buf_matA1=upd_w(buf_matA1,0,window_read_v32(matA));
            window_incr(matA,L7_jumpA0);
            buf_matB1=window_read_v32(matB);
            window_incr(matB,L7_jumpB1);

            acc1=mac16(acc1,buf_matA0,0,0x11101110,16,0x3120,buf_matB1,0,0x88880000,2,0x3210);
            buf_matA1=upd_w(buf_matA1,1,window_read_v32(matA));
            window_incr(matA,L7_jumpA0);

            acc0=mac16(acc0,buf_matA1,0,0x11101110,16,0x3120,buf_matB0,0,0xCCCC4444,2,0x3210);
            buf_matA0=upd_w(buf_matA0,0,window_read_v32(matA));
            window_incr(matA,L7_jumpA0);

            acc1=mac16(acc1,buf_matA1,0,0x11101110,16,0x3120,buf_matB1,0,0xCCCC4444,2,0x3210);
            buf_matA0=upd_w(buf_matA0,1,window_read_v32(matA));
            window_incr(matA,L7_jumpA0);
            buf_matB0=window_read_v32(matB); 
            window_incr(matB,L7_jumpB0);

            //K iteration 1
            acc0=mac16(acc0,buf_matA0,0,0x11101110,16,0x3120,buf_matB0,0,0x88880000,2,0x3210);
            buf_matA1=upd_w(buf_matA1,0,window_read_v32(matA));
            window_incr(matA,L7_jumpA0);
            buf_matB1=window_read_v32(matB);
            window_incr(matB,L7_jumpB1);

            acc1=mac16(acc1,buf_matA0,0,0x11101110,16,0x3120,buf_matB1,0,0x88880000,2,0x3210);
            buf_matA1=upd_w(buf_matA1,1,window_read_v32(matA));
            window_incr(matA,L7_jumpA0);

            acc0=mac16(acc0,buf_matA1,0,0x11101110,16,0x3120,buf_matB0,0,0xCCCC4444,2,0x3210);
            buf_matA0=upd_w(buf_matA0,0,window_read_v32(matA));
            window_incr(matA,L7_jumpA0);

            acc1=mac16(acc1,buf_matA1,0,0x11101110,16,0x3120,buf_matB1,0,0xCCCC4444,2,0x3210);
            buf_matA0=upd_w(buf_matA0,1,window_read_v32(matA));
            window_incr(matA,L7_jumpA0);
            buf_matB0=window_read_v32(matB); 
            window_incr(matB,L7_jumpB0);

            //K iteration 2
            acc0=mac16(acc0,buf_matA0,0,0x11101110,16,0x3120,buf_matB0,0,0x88880000,2,0x3210);
            buf_matA1=upd_w(buf_matA1,0,window_read_v32(matA));
            window_incr(matA,L7_jumpA0);
            buf_matB1=window_read_v32(matB);
            window_incr(matB,L7_jumpB1);

            acc1=mac16(acc1,buf_matA0,0,0x11101110,16,0x3120,buf_matB1,0,0x88880000,2,0x3210);
            buf_matA1=upd_w(buf_matA1,1,window_read_v32(matA));
            window_incr(matA,L7_jumpA0);

            acc0=mac16(acc0,buf_matA1,0,0x11101110,16,0x3120,buf_matB0,0,0xCCCC4444,2,0x3210);
            buf_matA0=upd_w(buf_matA0,0,window_read_v32(matA));
            window_incr(matA,L7_jumpA0);

            acc1=mac16(acc1,buf_matA1,0,0x11101110,16,0x3120,buf_matB1,0,0xCCCC4444,2,0x3210);
            buf_matA0=upd_w(buf_matA0,1,window_read_v32(matA));
            window_incr(matA,L7_jumpA0);
            buf_matB0=window_read_v32(matB); 
            window_incr(matB,L7_jumpB0);

            //K iteration 3
            acc0=mac16(acc0,buf_matA0,0,0x11101110,16,0x3120,buf_matB0,0,0x88880000,2,0x3210);
            buf_matA1=upd_w(buf_matA1,0,window_read_v32(matA));
            window_incr(matA,L7_jumpA0);
            buf_matB1=window_read_v32(matB);
            window_incr(matB,jumpB);

            acc1=mac16(acc1,buf_matA0,0,0x11101110,16,0x3120,buf_matB1,0,0x88880000,2,0x3210);
            buf_matA1=upd_w(buf_matA1,1,window_read_v32(matA));
            window_incr(matA,jumpA);//jump

            acc0=mac16(acc0,buf_matA1,0,0x11101110,16,0x3120,buf_matB0,0,0xCCCC4444,2,0x3210);
            buf_matA0=upd_w(buf_matA0,0,window_read_v32(matA));
            window_incr(matA,L7_jumpA0);
            window_write(matC,bsrs(acc0,0));
	        window_incr(matC,16);

            acc1=mac16(acc1,buf_matA1,0,0x11101110,16,0x3120,buf_matB1,0,0xCCCC4444,2,0x3210);
            buf_matA0=upd_w(buf_matA0,1,window_read_v32(matA));
            window_incr(matA,L7_jumpA0);
            buf_matB0=window_read_v32(matB); 
            window_incr(matB,L7_jumpB0);
            window_write(matC,bsrs(acc1,0));
	        window_incr(matC,16);
            
        }
    }

}