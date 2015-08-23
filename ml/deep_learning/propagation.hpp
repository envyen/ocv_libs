#ifndef PROPAGATION_HPP
#define PROPAGATION_HPP

#include <opencv2/core.hpp>

#include "../utility/activation.hpp"

/*! \file propagation.hpp
    \brief collection of propagation algorithms
*/

/*!
 *  \addtogroup ocv
 *  @{
 */
namespace ocv{

/*!
 *  \addtogroup ml
 *  @{
 */
namespace ml{

/**
 *@brief forward propagation of neural network, this function\n
 *Assume this is a three layers neural network, this function\n
 *will compute the output of the layer 2
 *@param input The input of the neurals(input of layer 2)
 *@param weight The weight of the input
 *@param bias bias of the input
 *@param output The output of the neurals(output of layer 2).\n
 * After computation, output.rows == weight.rows && output.cols == input.cols
 *@param func unary functor which apply the activation on\n
 * the output
 *@pre input, weight and bias cannot be empty, the type of the\n
 * input, weight, bias and output should be double(CV_64F).\n
 * weight.cols == input.rows && bias.rows == weight.rows
 */
template<typename UnaryFunc = sigmoid>
void forward_propagation(cv::Mat const &input,
                         cv::Mat const &weight,
                         cv::Mat const &bias,
                         cv::Mat &output,
                         UnaryFunc func = UnaryFunc())
{
    if(!input.empty() && !weight.empty() &&
            !bias.empty()){
        //output = weight * input;
        cv::gemm(weight, input, 1.0, cv::Mat(),
                 0.0, output);
        for(int i = 0; i != output.cols; ++i){
            output.col(i) += bias;
        }
        func(output);
    }
}

} /*! @} End of Doxygen Groups*/

} /*! @} End of Doxygen Groups*/

#endif // PROPAGATION_HPP

