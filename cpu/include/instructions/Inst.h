#ifndef __INST_H__
#define __INST_H__
#include <memory>

struct CpuData;

class Inst
{
protected:
    Inst(unsigned short opcode) { mOpCode = opcode;  }

public:
    virtual bool Handle(std::shared_ptr<CpuData> systemData) = 0;

protected:
    unsigned short mOpCode;
};

#endif