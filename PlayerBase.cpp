#include "PlayerBase.h"

using namespace boost;

CPlayerBase::CPlayerBase(void)
{
    try
    {
        createPyObject("foo", "PlayerProxy");
        auto ptr1 = boost::python::ptr(this);
        call_method<void>(mObject.ptr(), "set_base", ptr1);
    }
    catch (python::error_already_set const &)
    {
        PyErr_Print();
    }
}

int CPlayerBase::getID(void)
{
    return id_;
}
void CPlayerBase::setID(int id)
{
    id_ = id;
}

BOOST_PYTHON_MODULE(MPlayer)
{
    class_<CPlayerBase, noncopyable>("CPlayerBase", no_init)
        .def("getID", &CPlayerBase::getID)
        .def("setID", &CPlayerBase::setID)
    ;
}