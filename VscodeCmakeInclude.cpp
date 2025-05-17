#include "VscodeCmakeInclude.h"
#include "src/cpp/ClassTest.h"
#include "src/cu/CUDACommon.h"
#include <vector>

void func1(const VscodeCmakeOption &_opt)
{
    VSCODE_CMAKE::ClassTest cls1(_opt.id);
    cls1.print();
}

void func2()
{
    // unsigned int s = 10;
    // std::vector<float> as(s * 2);
    // std::vector<float> bs(s * 2);
    // std::vector<float> cs(s * 2);
    // for (int i = 0; i < s * 2; ++i)
    // {
    //     as[i] = rand();
    //     bs[i] = rand();
    // }
    // float2 *asDev;
    // float2 *bsDev;
    // float2 *csDev;
    // cudaMalloc((void **)asDev, 2 * s * sizeof(float));
    // cudaMemcpy(asDev, as.data(), 2 * s * sizeof(float), cudaMemcpyHostToDevice);
    // cudaMalloc((void **)asDev, 2 * s * sizeof(float));
    // cudaMemcpy(bsDev, bs.data(), 2 * s * sizeof(float), cudaMemcpyHostToDevice);
    // cudaMalloc((void **)asDev, 2 * s * sizeof(float));
    // VSCODE_CMAKE::testAdd2s(asDev, bsDev, csDev, s);
    // cudaDeviceSynchronize();
    // cudaMemcpy(cs.data(), csDev, 2 * s * sizeof(float), cudaMemcpyDeviceToHost);
    // for (int i = 0; i < s * 2; ++i)
    // {
    //     std::cout << cs[i] << std::endl;
    // }
}
