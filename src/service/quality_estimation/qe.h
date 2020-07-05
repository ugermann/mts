#pragma once
#include "common/options.h"
#include "common/config_parser.h"
#include <vector>
namespace marian {
namespace qe {

class QualityEstimator {
  std::vector<float> slThresholds_; // for mapping sentence scores to QE scores
public:
  static void addOptions(ConfigParser &cp);
  QualityEstimator(Ptr<const Options> options);

  /// convert sentence score (log prob) to QE score
  int mapSentenceScore(float sentence_score);

};


}} // end of namespace marian::qea
