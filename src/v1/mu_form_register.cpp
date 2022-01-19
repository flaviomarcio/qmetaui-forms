#include "./mu_form_register.h"
#include "./mu_form_body.h"
#include "./mu_form_control_cache.h"
#include "./../../qmetaui/includes/QMetaUi/Core"

MUFormRegister::MUFormRegister()
{

}

MUFormRegister::~MUFormRegister()
{

}

void MUFormRegister::init(QQmlApplicationEngine &engine)
{
    Q_UNUSED(engine)
    MU_DECLARE_CLASS_META_FORMS(MUFormBody);
    MU_DECLARE_CLASS_META_FORMS(MUFormControlCache);
}
