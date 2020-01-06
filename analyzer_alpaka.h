#ifndef analyzer_alpaka_h
#define analyzer_alpaka_h

#include "alpakaConfig.h"

class Input;
class Output;

namespace alpaka_serial_sync {
  void analyze(Input const& input, Output& output, double& totaltime);
}

namespace alpaka_tbb_async {
  void analyze(Input const& input, Output& output, double& totaltime);
}

namespace alpaka_cuda_async {
  void analyze(Input const& input, Output& output, double& totaltime);
}

#endif  // analyzer_alpaka_h
