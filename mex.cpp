//This is required
#include "mex.h"

//Gateway function to specify input and output variables
void mexFunction (int num_output, mxArray* output_pars[], 
				  int num_input, const mxArray* input_pars[])
{

  //Check number of inputs. In this case it is 2
  //First input is a matrix. Second input is a scalar
  if (num_input != 2)
  {
    mexErrMsgTxt("Incorrect number of input arguments");
  }
 
  //Check number of outputs. In this case it is 1
  if (num_output != 1)
  {
    mexErrMsgTxt("Incorrect number of output arguments");
  }

  //Get second input parameter. It is an integer scalar.
  int second_input_int = (int)(mxGetScalar(input_pars[1]));

  //Associate inputs
  mxArray * first_input_matrix_mx = mxDuplicateArray(input_pars[0]);

  //Figure out dimensions. I am not using these variables in this
  //Demo but they can be used to check the number of rows and columns
  //of the first input parameter matrix
  const int dims = mxGetDimensions(input_pars[0]);
  int dimy = (int)dims[0]; 
  int dimx = (int)dims[1];

  //Associate outputs. The output is a column vector of 10 elements
  mxArray * first_output_matrix_mx = output_pars[0] = 
                                     mxCreateDoubleMatrix(10, 1, mxREAL);

  //Associate pointers
  double * first_input_matrix = mxGetPr(first_input_matrix_mx);
  double * first_output_matrix = mxGetPr(first_output_matrix_mx);
 
  //For each output element in the column vector of 10 elements
  for(int i = 0; i < 10; i++)
  {     
    //Calculate the output value. In this case we are just
    //incrementing the value a number of times defined
    //by the second input scalar parameter
    first_output_matrix[i] = 0;
    for(int j = 0; j < second_input_int; j++)
    {
      first_output_matrix[i] = first_output_matrix[i] + 1;
    }
  }

  return;
} 
