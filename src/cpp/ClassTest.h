#ifndef VSCODE_CMAKE_CLASS_TEST_H
#define VSCODE_CMAKE_CLASS_TEST_H

#include <iostream>

namespace VSCODE_CMAKE
{
    class ClassTest
    {
    private:
        int id_;

    public:
        ClassTest(const int _id);
        ~ClassTest();

        void print();
    };

} // namespace VSCODE_CMAKE

#endif