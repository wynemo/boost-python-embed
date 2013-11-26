#include "PlayerBase.h"

#include <boost/python.hpp>
using namespace boost;
using namespace boost::python;

CPlayerBase::CPlayerBase(void)
{
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
    class_<PyBase, noncopyable>("PyBase", no_init)
    ;
    class_<CPlayerBase, bases<PyBase>, noncopyable>("PlayerBase", no_init)
        .def("getID", &CPlayerBase::getID)
        .def("setID", &CPlayerBase::setID)
    ;
}
