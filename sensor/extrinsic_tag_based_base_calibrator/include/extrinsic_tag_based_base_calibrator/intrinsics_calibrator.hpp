// Copyright 2022 Tier IV, Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef EXTRINSIC_TAG_BASED_BASE_CALIBRATOR__INTRINSICS_CALIBRATOR_HPP_
#define EXTRINSIC_TAG_BASED_BASE_CALIBRATOR__INTRINSICS_CALIBRATOR_HPP_

#include <extrinsic_tag_based_base_calibrator/apriltag_detector.hpp>
#include <extrinsic_tag_based_base_calibrator/types.hpp>
#include <opencv2/core.hpp>

#include <memory>
#include <string>
#include <vector>

namespace extrinsic_tag_based_base_calibrator
{

class IntrinsicsCalibrator
{
public:
  IntrinsicsCalibrator(
    const ApriltagParameters & parameters, const std::vector<int> tag_ids,
    bool use_tangent_distortion, int num_radial_distortion_coeffs, bool debug = false)
  : detector_(parameters),
    calibration_tag_ids_(tag_ids),
    use_tangent_distortion_(use_tangent_distortion),
    num_radial_distortion_coeffs_(num_radial_distortion_coeffs),
    debug_(debug)
  {
  }

  /*!
   * Set the images to use for calibration
   * @param image_file_names the images to use for calibration
   */
  void setCalibrationImageFiles(const std::vector<std::string> & image_file_names);

  /*!
   * Calibrate the camera intrinsicss using images containing apriltags
   * @param[out] intrinsics the calibrated intrinsics
   * @returns whether or not the service callback succeeded
   */
  bool calibrate(IntrinsicParameters & intrinsics);

  ApriltagDetector detector_;

  std::vector<std::string> calibration_image_file_names_;
  std::vector<int> calibration_tag_ids_;
  bool use_tangent_distortion_;
  int num_radial_distortion_coeffs_;

  bool debug_;
};

}  // namespace extrinsic_tag_based_base_calibrator

#endif  // EXTRINSIC_TAG_BASED_BASE_CALIBRATOR__INTRINSICS_CALIBRATOR_HPP_
