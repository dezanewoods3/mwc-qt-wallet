#include "connect2server.h"
#include "ui_connect2server.h"
#include <QMessageBox>
#include  "../state/connect2node.h"

namespace wnd {

ConnectToServer::ConnectToServer(QWidget *parent, state::Connect2Node * _state) :
    QWidget(parent),
    ui(new Ui::connect2server),
    state(_state)
{
    ui->setupUi(this);
}

ConnectToServer::~ConnectToServer()
{
    delete ui;
}

void ConnectToServer::on_submitButton_clicked()
{
    if (ui->radioSelectManually->isChecked()) {
        state->applyChoice( state::Connect2Node::NODE_MANUAL);
    }
    else if (ui->radioStandalone->isChecked()) {
        state->applyChoice( state::Connect2Node::NODE_LOCAL);
    }
    else if (ui->radioAutoConnect->isChecked()) {
        state->applyChoice( state::Connect2Node::NODE_POOL);
    }
    else {
        QMessageBox::critical(this, "Connecto to MWC node",
                              "Please select the connection type to your server");
    }

}

void ConnectToServer::on_cancelButton_clicked()
{
    state->cancel();
}


}
