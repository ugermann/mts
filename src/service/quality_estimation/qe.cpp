#include "qe.h"
namespace marian {
namespace qe {

/// convert sentence score (log prob) to QE score
int sentence_score2qe_score(const float sentence_score) {
  // empirically defined thresholds
  float thresholds[2] = {-0.24869322, -0.10945034};

  if (sentence_score < thresholds[0]) {
    return 3;
  } else if (sentence_score > thresholds[1]) {
    return 1;
  } else {
    return 2;
  }
}

}} // end of namespace marian::qea
