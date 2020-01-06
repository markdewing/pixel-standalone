#ifndef alpakaConfig_h_
#define alpakaConfig_h_

#include <alpaka/alpaka.hpp>

#ifdef ALPAKA_ACC_GPU_CUDA_ENABLED
#define ALPAKA_ARCHITECTURE alpaka_cuda_async
namespace alpaka_cuda_async {
  using Dim = alpaka::dim::DimInt<1u>;
  using Idx = uint64_t;
  using Extent = uint64_t;
  using Acc = alpaka::acc::AccGpuCudaRt<Dim, Extent>;
  using DevHost = alpaka::dev::DevCpu;
  using DevAcc = alpaka::dev::Dev<Acc>;
  using PltfHost = alpaka::pltf::Pltf<DevHost>;
  using PltfAcc = alpaka::pltf::Pltf<DevAcc>;
  using Queue = alpaka::queue::QueueCudaRtNonBlocking;
  using WorkDiv = alpaka::workdiv::WorkDivMembers<Dim, Idx>;
  using Vec = alpaka::vec::Vec<Dim, Idx>;
}  // namespace alpaka_cuda_async

#endif  // ALPAKA_ACC_GPU_CUDA_ENABLED

#ifdef ALPAKA_ACC_CPU_B_SEQ_T_SEQ_ENABLED
#define ALPAKA_ARCHITECTURE alpaka_serial_sync
namespace alpaka_serial_sync {
  using Dim = alpaka::dim::DimInt<1u>;
  using Idx = uint64_t;
  using Extent = uint64_t;
  using Acc = alpaka::acc::AccCpuSerial<Dim, Extent>;
  using DevHost = alpaka::dev::DevCpu;
  using DevAcc = alpaka::dev::Dev<Acc>;
  using PltfHost = alpaka::pltf::Pltf<DevHost>;
  using PltfAcc = alpaka::pltf::Pltf<DevAcc>;
  using Queue = alpaka::queue::QueueCpuBlocking;
  using WorkDiv = alpaka::workdiv::WorkDivMembers<Dim, Idx>;
  using Vec = alpaka::vec::Vec<Dim, Idx>;
}  // namespace alpaka_serial_sync

#endif  // ALPAKA_ACC_CPU_B_SEQ_T_SEQ_ENABLED

#ifdef ALPAKA_ACC_CPU_B_TBB_T_SEQ_ENABLED
#define ALPAKA_ARCHITECTURE alpaka_tbb_async
namespace alpaka_tbb_async {
  using Dim = alpaka::dim::DimInt<1u>;
  using Idx = uint64_t;
  using Extent = uint64_t;
  using Acc = alpaka::acc::AccCpuTbbBlocks<Dim, Extent>;
  using DevHost = alpaka::dev::DevCpu;
  using DevAcc = alpaka::dev::Dev<Acc>;
  using PltfHost = alpaka::pltf::Pltf<DevHost>;
  using PltfAcc = alpaka::pltf::Pltf<DevAcc>;
  using Queue = alpaka::queue::QueueCpuNonBlocking;
  using WorkDiv = alpaka::workdiv::WorkDivMembers<Dim, Idx>;
  using Vec = alpaka::vec::Vec<Dim, Idx>;
}  // namespace alpaka_tbb_async

#endif  // ALPAKA_ACC_CPU_B_TBB_T_SEQ_ENABLED

#endif  // alpakaConfig_h_