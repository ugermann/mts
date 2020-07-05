#include "qe.h"
#include <algorithm>
#include "common/definitions.h"
namespace marian {
namespace qe {

// Static function to add command line options related to QE
void QualityEstimator::addOptions(ConfigParser &cp) {
  // argument sequence for adding options is
  // - argument name (please use long argument names only, and prefix with --qe-)
  // - argument group (leave as Quality Estimation)
  // - help string
  // - optionally default value
  // - optionally an intrinsic value that is applied if the option is
  //   specified without any additional arguments on the command line
  cp.addOption<std::vector<float>>
    ("--qe-sentence-level-thresholds", "Quality Estimation", // arg name & group
     "Thresholds for mapping sentence scores to sentence-level QE scores.");
}

/// Constructor
QualityEstimator::QualityEstimator(Ptr<const marian::Options> options){
  // interpret command line options here:
  slThresholds_ = options->get<std::vector<float>>("qe-sentence-level-thresholds");
  sort(slThresholds_.begin(), slThresholds_.end());
}

/// Convert sentence score (log prob) to QE score
int QualityEstimator::mapSentenceScore(const float sentenceScore) {
  if (slThresholds_.empty()) return 0; // no estimate available
  size_t i = 0;
  while (i < slThresholds_.size() && sentenceScore >= slThresholds_[i++]);
  return slThresholds_.size() - i + 1;
  // float thresholds[2] = {-0.24869322, -0.10945034};
}



}} // end of namespace marian::qea
