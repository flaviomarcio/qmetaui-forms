#include "./mu_form_runner.h"

#define dPvt()\
auto&p = *reinterpret_cast<MUFormRunnerPvt*>(this->p)

class MUFormRunnerPvt{
public:
    MUFormRunner*parent=nullptr;
    explicit MUFormRunnerPvt(MUFormRunner*parent)
    {
        this->parent=parent;
    }

    virtual ~MUFormRunnerPvt()
    {
    }
};

MUFormRunner::MUFormRunner(QObject *parent):QStm::Object(parent)
{
    this->p=new MUFormRunnerPvt(this);
}

MUFormRunner::~MUFormRunner()
{
    dPvt();
    delete&p;
}
