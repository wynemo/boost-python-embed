#include <iostream>
#include "PlayerBase.h"

#include <boost/python.hpp>

using namespace boost;
using namespace boost::python;

extern "C" void initModules(void);

bool startup()
{
    Py_Initialize();

    char appendSearchPathCode[] =
    "import sys\n"
    "import os\n"
    "def AppendPyPath(arg, dirname, filenames):\n"
    "    if not '.svn' in dirname:\n"
    "        sys.path.insert(0, os.path.abspath(dirname))\n"
    "os.path.walk('.', AppendPyPath, None)\n";
    PyRun_SimpleString(appendSearchPathCode);
    
    initModules();
    return true;
}

void shutdown()
{

}

//in boost macro extern c
extern "C" void initModules(void)
{
   initPythonModule(MPlayer);
}

int main()
{
    startup();
    CPlayerBase ppp;
    ppp.setID(123);
    try
    {
        object bar = import("bar");
        call_method<void>(bar.ptr(), "ttt", ptr(&ppp));
        object a = object(handle<>(borrowed(PyEval_GetBuiltins())));
        object b = a["unicode"];
#ifdef WIN32        
        object c = call<object>(b.ptr(), "中文", "gb2312");
#else
        object c = call<object>(b.ptr(), "中文", "utf-8");
#endif
        auto d = call_method<std::string>(c.ptr(), "encode", "utf-8");
        std::cout << d << std::endl;
    }
    catch (error_already_set const &)
    {
        PyErr_Print();
    }
    shutdown();
    return 0;
}
