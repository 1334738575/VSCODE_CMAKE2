// #include "CUDACommon.h"

// namespace VSCODE_CMAKE
// {
//     __device__ void add2(const float2 &a, const float2 &b, float2 &c)
//     {
//         c.x = a.x + b.x;
//         c.y = a.y + b.y;
//     }

//     __global__ void add2sCU(float2 *as, float2 *bs, float2 *cs, unsigned int s)
//     {
//         unsigned int idx = threadIdx.x + blockDim.x * blockIdx.x;
//         if (idx >= s)
//             return;
//         add2(as[idx], bs[idx], cs[idx]);
//     }
//     void testAdd2s(float2 *as, float2 *bs, float2 *cs, unsigned int s)
//     {
//         dim3 block(1024, 1);
//         dim3 grid((s + 1023) / 1024, 1);
//         add2sCU<<<grid, block>>>(as, bs, cs, s);
//     }

// } // namespace VSCODE_CMAKE
