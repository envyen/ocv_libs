#ifndef OCV_WAVELET_TRANSFORM_HPP
#define OCV_WAVELET_TRANSFORM_HPP

#include <opencv2/opencv.hpp>

#include <iostream>
#include <vector>

/*!
 *  \addtogroup ocv
 *  @{
 */
namespace ocv{

enum class HaarShrink{
    HARD,
    SOFT,
    GARROT
};

void haar_wavelet(cv::Mat &src, cv::Mat &dst, int n_iter);

void haar_wavelet_inv(cv::Mat &src, cv::Mat &dst,
                      int n_iter,
                      HaarShrink shrinkage_type = HaarShrink::GARROT,
                      float shrinkage_t = 50);

std::vector<cv::Rect> haar_wavelet_region(cv::Size2i const &size,
                                          int n_iter);

} /*! @} End of Doxygen Groups*/

#endif // WAVELET_TRANSFORM_HPP

