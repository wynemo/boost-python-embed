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

uint32_t CPlayerBase::getID(void)
{
    return id_;
}
void CPlayerBase::setID(uint32_t id)
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