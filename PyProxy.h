#ifndef PyProxy_h
#define PyProxy_h


class PyBase
{
protected:
    virtual ~PyBase(void) = 0;
};

#define initPythonModule(m); \
    void init##m(void);      \
    init##m();


#endif
