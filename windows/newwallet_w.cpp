#include "newwallet_w.h"
#include "ui_newwallet.h"
#include "../state/newwallet.h"
#include <QMessageBox>

namespace wnd {

NewWallet::NewWallet(QWidget *parent, state::NewWallet * _state) :
    QWidget(parent),
    ui(new Ui::NewWallet),
    state(_state)
{
    ui->setupUi(this);

    ui->radioCreateNew->setChecked(true);
    updateControls();
}

NewWallet::~NewWallet()
{
    delete ui;
}

void NewWallet::updateControls() {
    bool isNewChecked = ui->radioCreateNew->isChecked() || ui->radioHaveSeed->isChecked();
    ui->submitButton->setEnabled(isNewChecked);
}


void NewWallet::on_submitButton_clicked()
{
    if ( ui->radioCreateNew->isChecked() )
        state->submitCreateChoice( state::NewWallet::NEW_WALLET_CHOICE::CREATE_NEW);
    else if (ui->radioHaveSeed->isChecked())
        state->submitCreateChoice( state::NewWallet::NEW_WALLET_CHOICE::CREATE_WITH_SEED);
    else {
        QMessageBox::critical(nullptr, "Please select", "Please select how you want to provision a new wallet");
        Q_ASSERT(false);
    }
}

void NewWallet::on_radioHaveSeed_clicked()
{
    updateControls();
}

void NewWallet::on_radioCreateNew_clicked()
{
    updateControls();
}

}