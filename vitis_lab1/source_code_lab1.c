#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "Xilinx\Vitis\matrixdimlab1.h"

void matrix_mul(uint8_t A[m][n], uint8_t B[n][p], uint32_t C[m][p]) {

#pragma HLS ARRAY_PARTITION variable=A type=cyclic factor=64 dim=2
#pragma HLS ARRAY_PARTITION variable=B type=cyclic factor=64 dim=1

	int i;
	int j;
	int k;
	uint32_t sum;
	for (i = 0; i < m; i++) {
	#pragma HLS LOOP_TRIPCOUNT min=m max=m
		for (j = 0; j < p; j++) {
		#pragma HLS LOOP_TRIPCOUNT min=p max=p
		#pragma HLS PIPELINE II=1
        	sum = 0;
            for (k = 0; k < n; k++) {
			#pragma HLS LOOP_TRIPCOUNT min=n max=n
            	//#pragma HLS UNROLL factor=64
                sum += (uint32_t)A[i][k] * (uint32_t)B[k][j];
            }
            C[i][j] = sum;
        }
    }
}

