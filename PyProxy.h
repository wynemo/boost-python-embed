#ifndef PyProxy_h
#define PyProxy_h

#ifdef _DEBUG
#ifndef _DLL
#define _DLL 1
#endif
#endif

#include <boost/python.hpp>
using namespace boost::python;

inline object pickleLoad(const char *data, int length)
{
    str pyData = str(data, length);
    
    object pickle = import("cPickle");
    return call_method<object>(pickle.ptr(), "loads", pyData);
}

inline object pickleDump(object obj)
{
    object pickle = import("cPickle");
    return call_method<object>(pickle.ptr(), "dumps", obj, 2);
}

class PyProxy
{
public:
    PyProxy(void)
    {

    }

    virtual ~PyProxy(void)
    {
    }

    void createPyObject(const char *moduleName, const char *className)
    {
        object m = import(moduleName);
        mObject = call_method<object>(m.ptr(), className);
    }

    void destroyPyObject(void)
    {
         mObject = object();
    }

    bool load(const char *data, int length)
    {   
        try
        {
            object pyDict = pickleLoad(data, length);
            call_method<object>(getPyObject().ptr(), "onLoad", pyDict);
            return true;
        }
        catch(const error_already_set &)
        {
            PyErr_Print();
        }
        return false;
    }

    bool save(char *buffer, int &length)
    {
        char *data = buffer + length;
        try
        {
            object pyDict = call_method<object>(getPyObject().ptr(), "onSave");
            object pyData = pickleDump(pyDict);
            std::string s = extract<std::string>(pyData);
            memcpy(data, s.c_str(), s.size());
            length += s.size();
            return true;
        }
        catch(const error_already_set &)
        {
            PyErr_Print();
        }
        return false;
    }

    object& getPyObject(void)
    {
        return mObject;
    }

protected:
    object mObject; //None in python
};

#define initPythonModule(m); \
    void init##m(void);      \
    init##m();

#endif
