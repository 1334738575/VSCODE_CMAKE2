#include "ClassTest.h"

namespace VSCODE_CMAKE
{

    ClassTest::ClassTest(const int _id)
        : id_(_id)
    {
    }

    ClassTest::~ClassTest()
    {
    }

    void ClassTest::print()
    {
        std::cout << "id: " << id_ << std::endl;
    }

} // namespace VSCODE_CMAKE
