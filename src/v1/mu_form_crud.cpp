#include "./mu_form_crud.h"

MUFormCrudItem::MUFormCrudItem(QObject *parent):QStm::Object(parent), item(parent)
{
}

MUFormCrud::MUFormCrud(QObject *parent):MUFormLinkCollectionBase(parent)
{
}
